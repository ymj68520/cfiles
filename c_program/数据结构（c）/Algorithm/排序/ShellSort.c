#include "Shells_Sort.h"

#define N 10
#define T 3

int main(){
    RedType d[N]={
        {98,1},{36,2},{-9,3},{0,4},{47,5},
        {23,6},{1,7},{8,8},{10,9},{7,10}
    };
    int i,dlta[T] = {5,3,1};
    SqList m;
    for(i=0;i<N;i++)
        m.r[i+1] = d[i];
    m.length = N;
    printf("希尔排序前：\n");
    Print(m);
    ShellSort(&m,dlta,T);
    printf("希尔排序后：\n");
    Print(m);
    return 0;
}