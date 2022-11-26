#include <stdio.h>
#define SIZE 10

int max_array(int * ar);
int max_sub(double * ar);

int main() {
    int i;
    int arr[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    double arra[SIZE] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
    int a, b;
    a = max_array(arr);
    b = max_sub(arra);
    printf("%d\n%d\n",a,b);
    return 0;
}

int max_array(int * ar){
    int temp,i,j;
    for(i=0;i<SIZE;i++){
        for(j=i+1;j<SIZE;j++){
            if(ar[i]<ar[j]){
                ar[i]=temp;
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
    }
    return ar[0];
}
int max_sub(double * ar){
    int n,i,j;
    for(i=0;i<SIZE;i++){
        for(j=i+1;j<=SIZE;j++){
            if(ar[i]<ar[j]){
                n=j;
            }
        }
    }
    return n;
}