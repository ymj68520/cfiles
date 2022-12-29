#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/select.h>

#define MAXCONNECT 255
#define BROADCAST "0.0.0.0"
#define PORT 8088

// 实现echo服务器的功能函数
void echo(int client, struct in_addr addr){
    // 定义消息缓冲区并初始化
    char mesg[256]; memset(mesg,0,sizeof(mesg));
    // 从客户端套接字读取255个字符，保留一个'\0'的位置
    fd_set ori,tmp;
    FD_SET(client,&ori);
    while(1){
        tmp = ori;
        select(client+1,&tmp,NULL,NULL,NULL);
        int n = 0;
        ioctl(client,FIONREAD,&n);
        if(n==0)    break;
        read(client,mesg,255);
        // 将缓冲区内容发回客户
        write(client,mesg,strlen(mesg));
    }
    // 关闭连接
    close(client);
    // 服务器显示信息
    printf("一个来自：%s 的连接已经终止!\n",inet_ntoa(addr));
    // 子进程结束
    exit(0);
}

int main(){
    // 创建一个监听套接字，设置为TCP连接
    int listen_sk =  socket(AF_INET,SOCK_STREAM,0);
    if(listen_sk == -1){
        perror("创建套接字1失败!");
        exit(EXIT_FAILURE);
    } 
    // 为监听套接字创建并设置属性
    struct sockaddr_in listen_addr;
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = inet_addr(BROADCAST);
    listen_addr.sin_port = htons(PORT);
    bzero(&(listen_addr.sin_zero),8);
    // 绑定监听套接字
    if( -1 == bind(listen_sk, (struct sockaddr *)&listen_addr, sizeof(struct sockaddr))){
        perror("绑定失败！");
        exit(EXIT_FAILURE);
    }
    // 开始服务！
    printf("开始监听..................\n"); 
    while(-1 != listen(listen_sk,MAXCONNECT)){
        // 创建客户端套接字，由accept使用
        struct sockaddr_in client_addr;
        // 定义客户端套接字长度，由accept使用
        socklen_t client_addr_len=sizeof(struct sockaddr);
        // 定义处理请求的客户端套接字 并accept一个连接
        int client_sk = accept(listen_sk,(struct sockaddr *)&client_addr,&client_addr_len);
        // fork一个进程
        pid_t pid = fork();
        // 子进程执行动作，父进程进行下一循环。
        if(pid == 0){
            // 子进程执行功能函数
            echo(client_sk,client_addr.sin_addr);
        }
    }
    puts("Listening Error! Exiting.........");
    sleep(3);

    return 0;
}
