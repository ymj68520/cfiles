#include <stdio.h>
#include <string.h>

int main(){
    char a[100000];
    int i,s=0;
    scanf("%s",a);
    int l=strlen(a);
    for(i=0;i<l;i++){
        s=s+a[i]-'0';
    }
    printf("%d",s);
    return 0;
}