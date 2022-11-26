#include <stdio.h>

int main(){
    int T;
    scanf("%d%*c",&T);
    for(int i=0;i<T;i++){
        int sum=0;
        char ch[100001];
        char cha = getchar();
        while(cha !='\n'){
            sum +=cha - 'A' + 1;
            cha = getchar();
        }
        printf("%d\n",sum);
    }
    return 0;
}