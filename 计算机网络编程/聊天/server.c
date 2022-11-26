#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <time.h>
#include <stdbool.h>
#include <sys/select.h>

#define PORT 8088

int main(){
    int server_sockfd, client_sockfd[2]; 
	int server_len, client_len; 
	struct sockaddr_in server_address; 
	struct sockaddr_in client_address[2]; 
	int result,cnt,maxfd; 
	fd_set readfds, t_readfds, writefds, t_writefds; 
    char buf[257];

	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);//建立服务器端socket 
	server_address.sin_family = AF_INET; 
	server_address.sin_addr.s_addr = htonl(INADDR_ANY); 
	server_address.sin_port = htons(8088); 
	server_len = sizeof(server_address); 

	if(-1 == bind(server_sockfd, (struct sockaddr *)&server_address, server_len)){
        perror("bind");
        exit(1);
    }
	if(-1 == listen(server_sockfd, 5)){
        perror("listen");
        exit(1);
    }

    FD_ZERO(&readfds);
    // FD_ZERO(&writefds);
    FD_SET(server_sockfd,&readfds);
    maxfd = server_sockfd;
    cnt = 0;

    while(true){
        int fd;
        int nread;
        // int rdflag = 0;
        t_readfds = readfds;
        // t_writefds = writefds;
        printf("server waiting\n"); fflush(stdout);

        result = select(maxfd+1,&t_readfds,NULL,NULL,NULL);
        printf("result:%d\n",result);
        if(result < 0 ){
            perror("select");
            exit(1);
        }

        for(fd=3;fd<=maxfd;fd++){
            if(FD_ISSET(fd,&t_readfds)){
                if(cnt < 2 && fd == server_sockfd){
                    client_len = sizeof(client_address[cnt]); 
					client_sockfd[cnt] = accept(server_sockfd, 
					(struct sockaddr *)&client_address[cnt], (socklen_t *)&client_len); 
                    write(client_sockfd[cnt],"Willcome!",strlen("Willcome!"));
					FD_SET(client_sockfd[cnt], &readfds);//将客户端socket加入到集合中
                    FD_SET(client_sockfd[cnt], &writefds);
                    maxfd = client_sockfd[cnt];
					printf("adding client on fd %d\n", client_sockfd[cnt++]);
                    continue;
                }
                else{
                    ioctl(fd,FIONREAD,&nread);
                    if(nread == 0){
                        close(fd);
                        FD_CLR(fd,&readfds);
                        FD_CLR(fd,&writefds);
                        cnt++;
                        cnt %= 2;
                        printf("removing client on fd %d\n", fd);
                    }
                    else if(nread > 0){
                        read(fd,buf,256);
                        printf("serving client on fd %d\n", fd);
                        // rdflag = fd;
                        if(fd == client_sockfd[0]){
                            write(client_sockfd[1],buf,strlen(buf));
                            printf("sendto client[1]\n");
                        }
                        else if(fd == client_sockfd[1]){
                            write(client_sockfd[0],buf,strlen(buf));
                            printf("sendto client[1]\n");
                        }
                        break;
                    }
                }
            }
            
        }

        // for(int i = 3; rdflag && i<=maxfd; i++){
        //     if(i != fd && FD_ISSET(i,&t_writefds)){
        //         char temp[257];
        //         temp[0] = i + '0';
        //         temp[1] = ':';
        //         temp[2] = ' ';
        //         for(int j=0;j<strlen(buf);j++)
        //             temp[3+j] = buf[j];
        //         temp[3+strlen(buf)] = '\0';
        //         write(i,temp,strlen(temp));
        //         rdflag = 0;
        //     }
        // }
    }


}