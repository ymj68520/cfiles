typedef int KeyType;
typedef int InfoType;
#include "树形选择排序.h"

int main(){
    int array[] = {87,241,2,1854,21,485,12,854,512,5641,21,31,1,0,222,2,3,4,7,8};
    for(int i=0;i<20;i++)
        printf("%4d ",array[i]);
        putchar('\n');
    HeapSort_array(array,20,1);
    for(int i=0;i<20;i++)
        printf("%4d ",array[i]);
        putchar('\n');
    HeapSort_array(array,20,0);
    for(int i=0;i<20;i++)
        printf("%4d ",array[i]);
        putchar('\n');

    return 0;
}
