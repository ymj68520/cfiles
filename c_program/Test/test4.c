#include <stdio.h>
#include <string.h>
#define MSG 'I`m a message be defined'
#define LIM 200

int main (){
    char ch[LIM];
    fgets(ch,LIM,stdin);
    char addon[]={"qwqwqwqwqwqwq"};
    strncat(ch,addon,5);
    puts(ch);
    putchar('\b');
    strcat(ch,addon);
    fputs(ch,stdout);
    putchar('\n');
//    gets_s(ch,LIM);  //编译器不支持
    return 0;
}