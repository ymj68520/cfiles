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
#define MAXCON 2
#define MYADDR "0.0.0.0"
#define MAXBUF 256+1
#define TIMEOUTSEC 15
#define LOG_FILE_NAME "chat_log_file"

char M_client[] =  "client";
char M_hasLoged[] =  "is connected at ";

int fdSet[MAXCON];
int curConnectCount;
char buf[MAXCON][MAXBUF];
bool wt_flag[MAXCON];

void logFunc(int logfile_fd, int client, char *buf){
    char temp[128];
    char Client_msg[] = "Client[";
    for(int i=0;i<7;i++)    
        temp[i] = Client_msg[i];
    temp[7] = client + '0';
    temp[8] = ']';
    temp[9] = ':';
    temp[10] = ' ';
    for(int i=0;i<strlen(buf);++i){
        temp[11+i] = buf[i];
    }
    int len = 11 + strlen(buf);
    temp[len++] = ' ';
    time_t now;
    time(&now);
    char *t = ctime(&now);

    for(int i=0;i<strlen(t);++i){
        temp[len+i] = t[i];
    }
    temp[len+strlen(t)] = '\n';
    temp[len+strlen(t)+1] = '\0';
    write(logfile_fd,temp,strlen(temp));
}

int main(){
    int logfile_fd = open(LOG_FILE_NAME, O_CREAT | O_APPEND);
    if(logfile_fd < 0){
        fprintf(stderr,"Open file: %s Error! Please try it later!",LOG_FILE_NAME);
        exit(EXIT_FAILURE);
    }

    memset(fdSet,0,sizeof(fdSet));
    memset(wt_flag,0,sizeof(wt_flag));
    
    int mySocket = socket(AF_INET,SOCK_STREAM,0);
    int cilentSock;

    struct sockaddr_in myAddr;
    myAddr.sin_family = AF_INET;
    // myAddr.sin_addr.s_addr = inet_addr(MYADDR);
    myAddr.sin_addr.s_addr = INADDR_ANY;
    myAddr.sin_port = htons(PORT);
    bzero(&(myAddr.sin_zero),8);

    //设置套接口的选项 SO_REUSEADDR 允许在同一个端口启动服务器的多个实例
    // setsockopt的第二个参数SOL SOCKET 指定系统中，解释选项的级别 普通套接字
    int yes=1;
    if(setsockopt(mySocket,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int))==-1){
        perror("setsockopt error \n");
        exit(1);
    }

    if(-1 == bind(mySocket, (struct sockaddr *)&myAddr, sizeof(struct sockaddr))){
        perror("Bind() Error!");
        exit(1);
    }

    if(-1 == listen(mySocket,MAXCON)){
        perror("Listening Error!");
        exit(1);
    }

    fd_set rd,wt;
    FD_ZERO(&rd);

    int maxSock;

    struct timeval tVal;
    tVal.tv_sec = TIMEOUTSEC;
    tVal.tv_usec = 0;

    curConnectCount = 0;

    struct sockaddr_in client_addr[MAXCON];
    socklen_t socklen = sizeof(struct sockaddr);
    

    for(int i=0;i<2;i++){
        fdSet[i] = accept(mySocket,(struct sockaddr*)&(client_addr[i]),&socklen);
        FD_SET(fdSet[i],&rd);
        if(fdSet[i] == -1){
            perror("accept");
            exit(EXIT_FAILURE);
        }
        curConnectCount++;
        fprintf(stdout,"Client[%d] is connected!\n",i);
        // 日志文件！我tm好想用c++的string！！！！！
        char temp[128];
        for(int i=0;i<strlen(M_client);++i) temp[i] = M_client[i];
        int s_len = strlen(temp);
        temp[s_len++] = '(';
        char *addr = inet_ntoa(client_addr[i].sin_addr);
        for(int i=0;i<strlen(addr);++i)  temp[s_len+i] = addr[i];
        s_len += strlen(addr);
        temp[s_len++] = ')';
        temp[s_len++] = '[';
        temp[s_len++] = (char)i+'0';
        temp[s_len++] = ']';
        temp[s_len++] = ' ';
        for(int i=0;i<strlen(M_hasLoged);++i){
            temp[s_len+i] = M_hasLoged[i];
        }
        time_t now;
        time(&now);
        addr = ctime(&now);
        for(int i=0;i<strlen(addr);++i)  temp[s_len+i] = addr[i];
        temp[s_len+strlen(addr)]   = '!';
        temp[s_len+strlen(addr)+1] = '\n';
        temp[s_len+strlen(addr)+2] = '\0';
        // 终于处理完啦！！！！！

        // 写入日志
        write(logfile_fd,temp,strlen(temp));
    }

    maxSock = fdSet[MAXCON-1];

    while(true){
        // // 连接数小于需要的数量，在线主机需要等待
        // while(curConnectCount<MAXCON){
        //     int wait_flag[2] = {0,0};
        //     int i;
        //     for(i=0;i<MAXCON;++i){
        //         if(!wait_flag[i] && fdSet[i] != 0){
        //             wait_flag[i] = 1;
        //             write(fdSet[i],"Waiting for someone~",21*sizeof(char));
        //         }
        //     }
        //     fdSet[!i] = accept(mySocket,(struct sockaddr*)client_addr+(!i),&socklen);
        // }
        wt = rd;
        // FD_SET(mySocket,&rd);

        // for(int i=0;i<MAXCON;i++){
        //     if(fdSet[i]!=0){
        //         FD_SET(fdSet[i],&rd);
        //         FD_SET(fdSet[i],&wt);
        //     }
        // }

        
        int ret = select(FD_SETSIZE,&wt,NULL,NULL,&tVal);
        if(-1 == ret){  // socket错误
            perror("select() ERROR!");
            exit(1);
        }
        else if(0 == ret){  // 超时后无可用连接
            perror("Time out!\nNo one can be Selected! Will continue!");
            continue;
        }
        
        for(int i=0;i<curConnectCount;i++){
            if(FD_ISSET(fdSet[i],&rd)){
                ret = read(fdSet[i],buf[i],MAXBUF-1);
                if(ret <= 0){
                    printf("Client[%d] close!",i);
                    close(fdSet[i]);
                    FD_CLR(fdSet[i],&rd);
                    FD_CLR(fdSet[i],&wt);
                    fdSet[i] = 0;
                    curConnectCount --;
                }
                write(fdSet[MAXCON-i-1],buf[i],strlen(buf[i]));
                logFunc(logfile_fd,i,buf[i]);
            }
            
        }
    }
    for(int i=0;i<MAXCON;++i){
        if(fdSet[i]!=0){
            close(fdSet[i]);
            fdSet[i] = 0;
        }
    }
    close(logfile_fd);
    printf("服务器退出。。。\n");
    sleep(3);

    return 0;
}