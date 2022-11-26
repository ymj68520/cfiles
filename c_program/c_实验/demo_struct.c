#include <stdio.h>
typedef struct stu{
    int num;
    char name[21];
}Student,*SStudent;

int mian(){
    SStudent temp[1];
    printf("%p %p",temp,temp+1);
    
}