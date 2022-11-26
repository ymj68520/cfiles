#include <stdio.h>
#include <string.h>

int isH(char *cha,int n);  // 这里叫函数声明 形式参数

int main(){    
    char ch[100000] = {'\0'};    
    scanf("%s",ch);
    int len = strlen(ch);
    if(isH(ch,len))        // 引用   
        puts("Yes");
    else        
        puts("No");
    return;
}

int isH(char *cha,int n){    // 这里是定义
    char temp[n];    
    for(int i=0;i<n;i++)        
    temp[i] = cha[n-1-i];    
    if(strcmp(temp,cha))        
        return 0;    
    else        
        return 1;
}

