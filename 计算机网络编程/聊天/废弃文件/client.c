#include <stdio.h>
#include <fcntl.h>
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
#define S_ADDR "127.0.0.1"
#define MAXBUF 256+1

char buf[MAXBUF];

int main(){
    int mysock = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in myaddr;
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = inet_addr(S_ADDR);
    myaddr.sin_port = htons(PORT);
    bzero(&(myaddr.sin_zero),8);

    if(-1 == connect(mysock,(struct sockaddr *)&myaddr,sizeof(struct sockaddr))){
        perror("连接失败！稍后再试一下！");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout,"已经连接到服务器了哦~~~\n");
    
    while(true){
        
        
        

    }
}

/*
pid_t pd = fork();
        if(pd > 0){
            fd_set wt;
            FD_ZERO(&wt);
            char wt_buf[MAXBUF];
            printf("在此输入：");
            scanf("%s",wt_buf);
            if(0>=select(FD_SETSIZE,NULL,&wt,NULL,NULL)){
                perror("select ERROR!");
                exit(EXIT_FAILURE);
            }
            if(FD_ISSET(mysock,&wt)){
                write(mysock,wt_buf,strlen(wt_buf));
            }
        }
        else if(pd == 0){
            fd_set rd;
            FD_ZERO(&rd);
            if(0>=select(FD_SETSIZE,&rd,NULL,NULL,NULL)){
                perror("select ERROR!");
                exit(EXIT_FAILURE);
            }
            if(FD_ISSET(mysock,&rd)){
                int ret = read(mysock,buf,MAXBUF-1);
                if(ret < 0){
                    fprintf(stderr,"服务器已断开连接~\n");
                    fprintf(stdout,"即将退出~\n");
                    sleep(3);
                    exit(EXIT_FAILURE);
                }
                else if(ret > 0){
                    fprintf(stdout,"%s\n",buf);
                }
                memset(buf,0,sizeof(buf));
            }
        }
        else{
            perror("创建新的进程失败！！！！！");
            exit(EXIT_FAILURE);
        }
*/