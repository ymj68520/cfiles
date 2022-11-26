#include <stdio.h>

void the_num(int * ar, int n);
int max_num(int * ar, int n);

int main(){
    int n;
    int i,j;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    the_num(a,n);
    return 0;
}

void the_num(int * ar, int n){
    int i,j,k;
    int arr[n];
    for(i=0;i<n;i++){
        arr[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(ar[i]==ar[j]){
                arr[i]+=1;
            }
        }
    }
    k=max_num(arr,n);
    printf("%d\n",ar[k]);
    return;
}

int max_num(int * ar, int n){
    int i,s;
    for(i=0;i<n;i++){
        if(ar[i]>n/2){
            s=i;
            break;
        }
    }
    return s;
}