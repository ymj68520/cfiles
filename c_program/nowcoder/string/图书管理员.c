#include <stdio.h>

void order(int [],int);
void Change(int [],int);
int isok(int [],int []);
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int i=0;
    // 处理图书码，并倒序
    int temp[n];
    while(i<n){
        scanf("%d",&temp[i]);
        i++;
    }
    order(temp,n);
    int book[n][9];
    for(i=0;i!=n;i++){
        Change(book[i],temp[i]);
    }
    // 处理需求码，并倒序, 搜索输出
    for(i=0;i!=q;++i){
        int len,need;
        scanf("%d %d",&len,&need);
        int require[len+1];
        Change(require,need);
        int j;
        int flag = 0;
        for(j=0;j!=n;j++){
            if(isok(book[j],require)){
                flag = 1;
                break;
            }
        }
        if(flag)
            printf("%d\n",temp[j]);
        else
            printf("-1\n");
    }

}
void order(int ar[],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(ar[i]>ar[j]){
                ar[i] = ar[i] + ar[j];
                ar[j] = ar[i] - ar[j];
                ar[i] = ar[i] - ar[j];
            }
        }
    }
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
int isok(int ar1[],int ar2[]){
    int i=0;
    while(/*ar1[i]!=-1 && */ ar2[i]!=-1){
        if(ar1[i]!=ar2[i])
            return 0;
        i++;
    }
    return 1;
}