#include <stdio.h>
#include <string.h>

//kao bei, mei liang ge hou jia yi ge *
void star_strcpy(char * des,char * sor);

int main(){
    char st[10000];
    char result[10000];
    gets(st);
    star_strcpy(result,st);
    puts(result);

    return 0;
}

void star_strcpy(char * des,char * sor){
    int i=0,st_num=0;
    int slen = strlen(sor);
    for(i=0;i<slen;i++){
        des[i+st_num] = sor[i];
        if(sor[i+1]=='\0'){
            return;
        }
        if(i%2 != 0){
            des[i+st_num+1] = '*';
            st_num++;
        }
    }
    
    return;
    
}