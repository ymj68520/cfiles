#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a,*b,*c;
    a = (int *)malloc(sizeof(int));
    b = (int *)malloc(sizeof(int));
    c = (int *)malloc(sizeof(int));
    printf("a:%p; b:%p; c:%p\n",a,b,c);
    c = a;
    a = b;
    b = c;
    printf("a:%p; b:%p; c:%p\n",a,b,c);
    free(a);free(b);
    return 0;
}