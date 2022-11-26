#include <stdio.h>
#include <string.h>
/*
char * strcpy(char * s1,const char * s2);
char * strncpy(char * s1,const char * s2,size_t);
char * strcat(char * s1,chonst char * s2);
char * strncat(char * si,const char * s2;size_t);
int    strcmp(const char * s1, const char s2);
int    strncmp(const char * s1, const char s2,size_t);

char * strchr(const char * s, int c);
char * strpbrk(const char *s1, const char *s2);
char * strrchr(const char *s, int c);
char * strstr(const char *s1, const char *s2);
size_t strlen(const char*s);

//组合    sprintf(type * s0,"%*",element1.);
*/
int main (){
    while(!(1-2)){
        printf("1111\n");
    }
    printf("%d\n",strcmp("g","g"));//前面的字符串在后面的字符串前返回-1，后返回1，相同返回0
    size_t a=1;
    printf("%lu\n",sizeof(a));
    char ch[10],cha[10];
    fgets(ch,5,stdin);
    strcpy(cha,ch);//可以整体cp，也可以一个个cp；
    puts(cha);
    printf("%lu\n",sizeof(cha));
    char *charr;
    printf("%p\n",charr);
    charr=ch;
    printf("%p\n",charr);
    char s[123];
    sprintf(s,"%s%s%s",ch,cha,charr);
    puts(s);
    return 0;
}