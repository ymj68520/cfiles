#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b){
    return *(int *)a - *(int *)b;
}
int main(){
    int a[] = {1123,23423,436345,123412,1234,123,1,2,8,9,4,6};
    for(int i=0;i<12;++i)
        printf("%d : ",a[i]);
    putchar('\n');
    qsort(a,12,sizeof(int),compare);
    for(int i=0;i<12;++i)
        printf("%d : ",a[i]);
}