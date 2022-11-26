#include <stdio.h>
#include <stdbool.h>
#include <string.h>
char HEAD[35][20] = {"algorithm", "bitset", "cctype",
 "cerrno", "clocale", "cmath", "complex", "cstdio", "cstdlib",
  "cstring", "ctime", "deque", "exception", "fstream", "functional", "limits"
  , "list", "map", "iomanip", "ios", "iosfwd", "iostream", "istream", 
  "ostream", "queue", "set", "sstream", "stack", "stdexcept", "streambuf", 
  "string", "utility", "vector", "cwchar", "cwctype"};
bool isin(char HEAD[35][20],char []);
bool gets_s(char []);
int main(){
    int T;
    scanf("%d%*c",&T);
    char ch[20];
    for(int i=0;i<T;i++){
        gets_s(ch);
        if(isin(HEAD,ch))
            puts("Qian");
        else
            puts("Kun");
    }

}
bool isin(char HEAD[35][20],char *ch){
    for(int i=0;i<35;i++){
        if(!strcmp(HEAD[i],ch)){
            return true;
        }
    }
    return false;
}
bool gets_s(char ch[]){
    int i=0;
    char cha;
    cha = getchar();
    while(cha!='\n'){
        ch[i] = cha;
        cha = getchar();
        i++;
    }
    ch[i] = '\0';
    return true;
}