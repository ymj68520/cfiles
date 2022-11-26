#include <stdio.h>

int main(){
    int n;
    scanf("%d%*c",&n);
    for(int q=0;q<n;q++){
        char ch = getchar();
        int sum=0;
        while(ch!='\n'){
            sum += ch - '0';
            ch = getchar();
        }
        printf("%d",sum);
    }
    return 0;
}