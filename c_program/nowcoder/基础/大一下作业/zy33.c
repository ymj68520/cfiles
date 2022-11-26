#include <stdio.h>
#include <string.h>

void my_strcpy(char * destination,char * source);

int main (){
    char sorc[1000];
    char des[1000];
    // gets(sorc);
    my_strcpy(des, "");
    for(int i=0;des[i]!='\0';i++){
        if(des[i]==' '){
            printf("#");
        }else 
        printf("%c",des[i]);
    }
    return 0;
}

/*void my_strcpy(char * destination,char * source){
    int slen;
    slen = sizeof(source);
    for(int i=0; i<slen && *(source+i) != ' '; i++){
        if('0'<=source[i]&&source[i]<='9'){
            
            destination[0]='e';
            destination[1]='r';
            destination[2]='r';
            destination[3]='o';
            destination[4]='r';
            return;
        }
    }
    for(int i=0; i<slen && *(source+i) != ' '; i++)
        *(destination+i) = *(source+i);
        
    
    return;
}*/
#include <stdio.h>
#include <string.h>
void my_strcpy(char * destination,char * source){
    if(destination==NULL||source==NULL){ //des与source为空指针，不存储数据
        printf("error");
        return;
    }
    int len=0,slen=0; 
    int i;
    for(i=0;source[i] != ' ';i++)
       len++;
    slen=sizeof(destination);
    if(slen<len){ //?  des大小不够存储source
        printf("error");
        return;
    }
    for(i=0;i<len;i++){
        destination[i] = source[i];
    }
    destination[i]=' ';
    return;
}