#include <stdio.h>

int main(){
    int T;
    scanf("%d%*c",&T);
    for(int q=0;q<T;q++){
        int n;
        scanf("%d%*c",&n);
        char source[100001];
        char ch = getchar();
        int len=0;
        while(ch!='\n'){
            source[len] = ch;
            ch = getchar();
            len++;
        }
        int add[n];
        add[n-1] = add[0] = (n-1)*2;
        for(int i=1;i<n-1;i++)
            add[i] = add[i-1] - 2;
        for(int i=0;i<n;i++){
            int count=0;
            while(i+count*add[i]<=len-i){
                printf("%c",source[i+count*add[i]]);
                count++;
            }

        }
        return 0;
    }
}