#include<stdio.h>
#include <stdbool.h>
#include <string.h>
 int main() { 
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[6];
    fgets(str3,5,stdin);
    
    if(str1 == str2)
         printf("Equal\n"); 
    else 
        printf("Unequal\n"); 
    
    if(strcmp(str1, str2))
        puts("111");
    else
        puts("222");
    
    if(strcmp(str1, str3))
        puts("111");
    else
        puts("222");
    
    return 0;
}
