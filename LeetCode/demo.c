#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

// int main(){
//     int len;
//     char *buff;
//     // while(1){
//     int fd = open("/mnt/e/cfiles/wsnd.t",O_RDONLY);
//     read(fd,&len,sizeof(int));
//     printf("len: %d\n%p\n",len,(int*)len);
//     // }
//     // read(0,&len,sizeof(int));
//     // int n = read();
//     buff = malloc(len);
//     printf("size of buff: %d\n",strlen(buff));
//     read(fd,buff,len);
//     // printf("len: %d \nn: %d \ns: %s\n",n,buff);
//     printf("s: %s\n",buff);
//     return 0;
// }

// int main(){
//     int len;
//     char *buf;
//     int fd = open("/mnt/e/cfiles/wsnd.t",O_RDONLY);
//     read(fd,&len,sizeof(len));
//     if(len < 0)
//         perror("error");
//     buf = calloc(len,sizeof(char));
//     if(buf == NULL)
//         perror("er");
//     read(fd,buf,len);
//     buf[len] = '\0';

//     printf("len: %d\nlength of buff: %d\nbuff:%s\n",len,(int)strlen(buf),buf);
//     return 0;
// }

// int main(){
//     int fd = open("/mnt/e/cfiles/wsnd.t",O_WRONLY);
//     if(fd < 0)  exit(EXIT_FAILURE);
//     char * s = "114514 wsnd, sb";
//     write(fd,s,strlen(s));
//     return 0;
// }
int foo = 100;
int main(){
    int bar = 100;
    int pid = fork();
    if(pid > 0)
        foo += 100;
    else if(pid == 0)
        bar += 100;
    else{
        foo -= 100;
        bar -= 100;
    }
    if(pid == 0){
        printf("zi,bar: %d\nfoo: %d\n",bar,foo);
    }
    else
        printf("fu,bar: %d\nfoo: %d\n",bar,foo);
    return 0;
}