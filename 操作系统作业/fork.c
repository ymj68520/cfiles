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
#include <wait.h>

int main(){
    pid_t id = fork();
    if(id == 0){
        execl("/mnt/e/cfiles/操作系统作业/hello",NULL);
    }
    else{
        waitpid(id,NULL,0);
        puts("Bye!");
    }
    return 0;
}
