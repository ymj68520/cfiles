#include <stdio.h>
#include <string.h>

int main(){
    char * ret_val;
    char * find;
    char * st;
    ret_val = fgets(st, 20, stdin);
    find = strchr(st,'a');
    if(find){
        puts("kong");
    }
    else{
        puts("feikong");
    } 

    return 0 ;
}
