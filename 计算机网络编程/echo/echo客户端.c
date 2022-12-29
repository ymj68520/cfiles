#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>

#define PORT 8088
#define MY_ADDR "127.0.0.1"
#define MAXBUF 256
int main(){
    char buf[MAXBUF]; memset(buf,0,sizeof(buf));

    int sk_fd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in myaddr;

    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(PORT);
    myaddr.sin_addr.s_addr = inet_addr(MY_ADDR);
    bzero(&(myaddr.sin_zero),8);

    if(-1 == connect(sk_fd,(struct sockaddr *)&myaddr,sizeof(struct sockaddr))){
        perror("连接失败!");
    }
    while(1){
        printf("你想要说什么呢？：\n");
        scanf("%s",buf);
        write(sk_fd,buf,strlen(buf));
        char rec_msg[MAXBUF];memset(rec_msg,0,sizeof(rec_msg));
        read(sk_fd,rec_msg,MAXBUF-1);
        printf("echo服务器说：\n%s\n",rec_msg);
    }
    close(sk_fd);
    
    return 0;
}