#include <stdio.h>

char * test(char*);

int main(){
    char ar[3] = {'q','w','e'};
    char *arr = test(ar);
    printf("%c %c\n",ar[0],arr[0]);
    
}
char * test(char*ar){
    ar[0] = '1';
    return ar;
}