#include <stdio.h>

int main(){
    int a[8]={123,14235346,363245,1234,4523412,312,33,13};
    select_sort(a,8);
    for(int i=0; i<8; i++){
        printf("%d ",a[i]);
    }
    return 0;
}


void select_sort (int a[], int n){
    int minindex,min;
    for(int i = 0; i < n; i++){
        minindex = i;
        min = a[minindex];
        for(int j = i + 1; j < n; j++){
            if(min > a[j]){
                min = a[j];
                minindex = j;
            }
        }
        if(minindex != i){
            a[minindex] = a[i];
            a[i] = min;
        }
    }
}
