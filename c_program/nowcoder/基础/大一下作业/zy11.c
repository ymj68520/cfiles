#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (){
    char ssh[21];
    int i=0;
    while(i<20 && (ssh[i] = getchar()) != '\n'){
        if(ssh[i] > 'z' && ssh[i] < 'a' && ssh[i] <'A' && ssh[i] > 'Z'){
            printf("error");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    if(ssh[0]=='\0'){
        printf("error");
    }
    for(int i = 0;i<strlen(ssh)-1;i++){
        if(ssh[i] > 'v' || ssh[i] > 'V'){
            ssh[i] =(int)ssh[i] - 22; 
        }
        ssh[i] =(int)ssh[i] + 4;
    }
    puts(ssh);
    putchar('\b');

    return 0;

}