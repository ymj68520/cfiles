#include <stdio.h>

void Change(int ar[],int n);

int main (){
    int lb;
    int ub;
    scanf("%d %d",&lb,&ub);
    const int flag = 2;
    int sum = 0;
    int count = lb;
    int n = ub;
    int i;
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