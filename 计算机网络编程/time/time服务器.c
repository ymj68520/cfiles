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
void server_time(int fd, struct sockaddr * client){
    char buf[17];
    while(true){
        int len;
        if(-1 == recvfrom(fd,buf,sizeof(buf),0,client,(socklen_t *)&len)){
            perror("连接错误");
            exit(EXIT_FAILURE);
        }
        time_t now,cur;
        time(&now);
        cur = now;
        now = htonl((unsigned long long)now+UNIXEPOCH);
        sendto(fd,&now,sizeof(now),0,client, len);
        
        printf("来自：%s的请求已经回复，回复内容为：%s\n",
            inet_ntoa(((struct sockaddr_in*)client)->sin_addr),ctime(&cur));
    }
}

int main(){
    int sk_fd = socket(AF_INET,SOCK_DGRAM,0);
    if(-1 == sk_fd){
        perror("创建套接字失败!");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    bind(sk_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr));

    puts("开始服务!...............");
    struct sockaddr_in client_addr;
    server_time(sk_fd,(struct sockaddr *)&client_addr);

    return 0;
}