#include <stdio.h>
#include <pthread.h>

void print(){
    printf("Hello thread!\n");
}
int main(void){
    printf("Hello wrold!\n");
    pthread_t pt;
    int pc = pthread_create(&pt,NULL,(void *)print,NULL);

    return 0;
}