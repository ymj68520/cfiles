#include <stdio.h>

void Change(int ar[],int n);
int main(){
    int n;
    scanf("%d",&n);
    int flag;
    scanf("%d",&flag);
    int i,count=1;
    int sum=0;
    while(count <= n){
        int ar[8] = {0};
        Change(ar,count);
        i=0;
        while(ar[i]!=-1){
            if(ar[i]==flag)
                sum++;
            i++;
        }
        count ++;
    }
    printf("%d",sum);
}
void Change(int ar[],int n){
    int count=0;
    while(n>=1){
        ar[count] = n%10;
        n = n/10;
        count ++;
    }
    ar[count] = -1;
}