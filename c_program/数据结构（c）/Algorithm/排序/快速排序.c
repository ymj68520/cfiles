typedef int InfoType;
#include "快速排序.h"

int main(){
    int array[] = {
        9,8,7,6,5,4,1,2,3,77,8,9,2,5,12,4,5,12,6,45
    };
    int ar[] = {
        4,3,2,1
    };
    int arr[] = {
        9,8,7,6,5,4,1,2,3,77,8,9,2,5,12,4,5,12,6,45
    };
    bubble_sort(ar,4);
    for(int i=0;i<4;i++)
        printf("%d, ",ar[i]);
        putchar('\n');
    QuickSort_array(array,20);
    for(int i=0;i<20;i++)
        printf("%d, ",array[i]);
        putchar('\n');
    QuickSort_array_one(arr,0,19);
    for(int i=0;i<20;i++)
        printf("%d, ",arr[i]);
        putchar('\n');
    
    return 0;
}