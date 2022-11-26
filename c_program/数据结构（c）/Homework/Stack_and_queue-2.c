#include <stdio.h>
#include <stdlib.h>

int main(){
    int xiao,zhong,da;
    da=xiao=zhong = 0;
    char ch;
    while((ch = getchar())!='#'){
        switch(ch){
            case '{':
                da++;
                break;
            case '[':
                zhong++;
                break;
            case '(':
                xiao++;
                break;
            case ')' :
                xiao --;
                
                break;
            case ']':
                zhong --;
                
                break;
            case '}':
                da--;
                
                break;
            default:
                puts("Error input : ");
                putchar(ch);
                break;
        }
    }
    if(da!=0 && zhong !=0 && xiao!=0)
        puts("ERROR");
    else
        puts("OK");
    return 0;
}