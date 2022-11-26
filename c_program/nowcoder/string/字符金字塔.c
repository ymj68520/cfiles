#include <stdio.h>

int main(){
    char ch = getchar();
    int row = ch - 'A' + 1;
    char begin = 'A' - 1;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=row-i;j++)
            printf(" ");
        int k;
        for(k=1;k<=i;k++){
            putchar(begin+k);
        }
        k-=2;
        for(int j=k;j>0;j--)
            putchar(begin+j);
        putchar('\n');
    }
}