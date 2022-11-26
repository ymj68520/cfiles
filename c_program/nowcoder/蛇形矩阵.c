#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int main(){
    int a[1010][1010];
    int n,t=0;
    scanf("%d",&n);
    for(int k=1;k<=n;k++)
       if(k % 2)
          for(int j=1;j<=k;j++)
          {
             int i   =k+1-j;
             t++;
            a[i][j]   =t;
            a[n+1-i][n+1-j]=n*n+1-t;
             }
       else
          for(int j=k;j>=1;j--)
          {
             int i=k+1 -j;
             t++;
            a[i][j]   =t;
            a[n+1-i][n+1-j]=n*n +1 -t;
             }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%3d ",a[i][j]);
        putchar('\n');
    }
}
*/
int n;
// 从第i，j位开始斜着走到头
void xiezhezou(int ar[][n+2],int *i,int *j,int *count,int mod){
    //  mod == 1向右上 0为左下方向
    if(mod)
        while(!ar[(*i)-1][(*j)+1])
            ar[(*i)--][(*j)++] = (*count)++;
    else
        while(!ar[(*i)+1][(*j)-1])
            ar[(*i)++][(*j)--] = (*count)++;
    /*
    for(int i=0;i<n+2;i++){
        for(int j=0;j<n+2;j++)
            printf("%d ",ar[i][j]);
        putchar('\n');
    }
    putchar('\n');*/
}
int main(){
    scanf("%d",&n);
    int ar[n+2][n+2];
    /*ar = (int **)malloc((n+2)*sizeof(int*));
    for(int i=0;i<n;i++)
        ar[i] = (int *)malloc((n+2)*sizeof(int));*/
    for(int i=1;i<n+1;i++)
        for(int j=1;j<n+1;j++)
            ar[i][j] = 0;
    for(int i=0;i<n+2;i++){
        ar[0][i] = 1;
        ar[i][0] = 1;
        ar[n+1][i] = 1;
        ar[i][n+1] = 1;
    }/*
    for(int i=0;i<n+2;i++){
        for(int j=0;j<n+2;j++)
            printf("%d ",ar[i][j]);
        putchar('\n');
    }*/
    ar[n][n] = n*n;
    int i=1,j=1,count=1;
    while(count<=n*n-1){
        if((j==1&&i==1)/*起点*/ || (i==n && j==1 && !(n%2))/*偶数阶左下角*/){
            ar[i][j++] = count++;
            if(i==1)
                xiezhezou(ar,&i,&j,&count,0);
            if(i==n)
                xiezhezou(ar,&i,&j,&count,1);
            continue;
        }
        if(j==n && i==1 && n%2/*奇数阶右上顶角*/){
            ar[i++][j] = count++;
            xiezhezou(ar,&i,&j,&count,0);
            continue;
        }
        if(j==1 || i == n){
            if(j==1)
                ar[i++][j] = count++;
            else
                ar[i][j++] = count++;
            xiezhezou(ar,&i,&j,&count,1);
            continue;
        }
        if(i==1 || j == n){
            if(i==1)
                ar[i][j++] = count++;
            else
                ar[i++][j] = count++;
            xiezhezou(ar,&i,&j,&count,0);
            continue;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            printf("%3d ",ar[i][j]);
        putchar('\n');
    }
}
