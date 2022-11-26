#include<stdio.h>
//查找水花仙数
int find(int n);

int main(){
    int n;
    scanf("%d",&n);
    int s;
    s = find(n);
    printf("%d",s);
}
int find(int n){
    if(n<100||n>999){
        return 0;
    }
    int g,s,b;
    int num=0;
    for(int i=100;i<=n;i++){
        g = i%10;
        s = (i/10)%10;
        b = (i/100)%10;
        if(g*g*g+s*s*s+b*b*b == i){
            num++;
        }
    }
    if(num == 0)
        return 0;
    else
        return num;
}