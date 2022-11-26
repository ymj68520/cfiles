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

#define PORT 8088
#define UNIXEPOCH 2208988800UL
#define ADDR "127.0.0.1"
const char msg[] = "What time is it?";
int main(){
    int fd = socket(AF_INET,SOCK_DGRAM,0);
    if(fd == -1){
        perror("创建套接字失败!");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in myaddr;
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = inet_addr(ADDR);
    myaddr.sin_port = htons(PORT);

    if(-1 == connect(fd,(struct sockaddr *)&myaddr,sizeof(struct sockaddr))){
        perror("connect error!");
        exit(EXIT_FAILURE);
    }
    sendto(fd,msg,sizeof(msg),0,(struct sockaddr *)&myaddr,sizeof(struct sockaddr));
    time_t t=0;
    if(-1 == read(fd,(char *)&t,sizeof(time_t))){
        perror("读取失败！");
        exit(EXIT_FAILURE);
    }

    t = ntohl(t);
    t -= UNIXEPOCH;

    printf("%s\n",ctime(&t));

    printf("Good Bye!");

    return 0;
    
}