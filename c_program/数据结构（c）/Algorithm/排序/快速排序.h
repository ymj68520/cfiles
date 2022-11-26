/*
    交换排序
        冒泡排序

        快速排序（对冒泡的改进）
            基本思想：
                通过一趟排序将待排序记录分割成独立的两部分，
                其中一部分记录的关键字均比另一部分记录的关键字小，
                则可分别对这两组记录继续进行排序，从而达到整个序列有序。

                假设待排序序列为r1.....rt，
                首先选择一个任意的记录（通常选择第一个r1）作为枢轴或者支点（pivot）
                然后将所有关键字较它小的记录都安置在它的位置之前，
                将所有关键字较它大的记录都安置在它的位置之后，
                之后可以将该枢轴记录最后所落的位置i作为分界线，将序列r1...rt分割成两个小序列
                rs....ri-1 ri....rt
                此过程称为一趟快速排序，或称为一次划分。

            一趟快速排序的步骤：
                附设两个指针low和high，它们的初始值分别为low和high，
                设枢轴记录的关键字为pivotkey，则首先从high所指的位置起向前搜索
                找到第一个关键字小于pivotkey的记录和枢轴记录互相交换，
                然后从low所指位置起向后搜索，
                找到第一个关键字大于pivotkey的记录和枢轴记录互相交换，
                重复这两步直至low = high为止。
*/

#include "Data_Struct.h"
#include "../查找/静态查找表/数值比较的宏.h"

// 冒泡排序
#define N 20
void bubble_sort(int a[],int n){
    int i,j,t;
    Status change;  // 调整的标志
    for(i=n-1,change=true;i>=i&&change;i--) // 由后到前调整，change = FALSE时终止循环
    {
        change = false; // 本次循环未调整的标志
        for(j=0;j<i;j++)    // 从第一个到倒数第二个
            if(a[j]>a[j+1]) // 前面的大于后面的
            {
                a[j]^=a[j+1]^=a[j]^=a[j+1]; // 换位
                change = true;  // 设置调整的标志
            }
    }
}
// 输出数组r的前n个数
void Print2(int r[],int n){
    for(int i=0;i<n;i++)
        printf("%d, ",r[i]);
    putchar('\n');
}

// 快速排序

// 交换顺序表L中子表的记录，使枢轴记录到位
// 并返回其所在位置，此时在它之前（后）的记录均不大（小）于它
int Partition_a(SqList *L,int low,int high){
    RedType t;
    KeyType pivotkey;   // 枢轴关键字
    pivotkey = L->r[low].key;   // 使用子表的第一个记录做初始枢轴记录
    while(low < high){  // 未分类区间大于0
        // 从表的两端交替的向中间扫描
        while(low<high && L->r[high].key >= pivotkey)   // 高端记录的关键字大于枢轴关键字
            high --;    // 高端向低端移动，继续比较
        t = L->r[low];  // 将比枢轴关键字小的记录交换到低端，枢轴到高端
        L->r[low] = L->r[high];
        L->r[high] = t;
        while(low < high && L->r[low].key <= pivotkey)  // 低端记录的关键字小于枢轴关键字
            low ++;
        t = L->r[low];  // 将比枢轴关键字大的记录交换到高端，枢轴到低端
        L->r[low] = L->r[high];
        L->r[high] = t;
    }
    return low; // 返回枢轴所在的位置
}
// 改进算法
int Partition(SqList *L,int low, int high){
    KeyType pivotkey;   // 枢轴
    pivotkey = L->r[low].key;   // 使用子表第一个记录做初始枢轴
    L->r[0] = L->r[low];    // 将枢轴保存至0号位
    while(low < high)   // 未分类的区间大于0
    {   // 从表两端交替向中间扫描
        while(low < high && L->r[high].key >= pivotkey)
            high--;
        L->r[low] = L->r[high]; // 将比枢轴关键字小的记录交换到低端，枢轴在0号位不动
        while(low < high && L->r[low].key <= pivotkey)
            low ++;
        L->r[high] = L->r[low]; // 将比枢轴关键字大的记录交换到高端，枢轴在0号位不动
    }
    L->r[low] = L->r[0];    // 枢轴记录到位
    return low; // 返回枢轴的位置
}
// 数组实现改进算法
int Partition_array(int L[], int low, int high){
    int pivotkey;  
    pivotkey = L[low];
    while(low < high){
        while(low < high && L[high] >= pivotkey)
            high --;
        L[low] = L[high];
        while(low < high && L[low] <= pivotkey)
            low ++;
        L[high] = L[low];
    }
    L[low] = pivotkey;
    return low;
}
// 对顺序表L中的子序列作快速排序
void QSort(SqList *L,int low, int high){
    int pivotloc;
    if(low < high)  // 子表序列大于1
    {
        pivotloc = Partition(L,low,high);
        QSort(L,low,pivotloc-1);    // 必修为枢轴左右，否则会无限循环
        QSort(L,pivotloc+1,high);
    }
}
void QuickSort(SqList *L){
    QSort(L,1,L->length);   // 对整个表进行快速排序
}
// 数组实现qsort
void QSort_array(int L[],int low,int high){
    int pivotloc;
    if(low<high){
        pivotloc = Partition_array(L,low,high);
        QSort_array(L,low,pivotloc-1);
        QSort_array(L,pivotloc+1,high);
    }
}
void QuickSort_array(int L[],int n){
    QSort_array(L,0,n-1);
}
// 有问题，待改
void QuickSort_array_one(int array[],int low,int high){
    /*int i,j;
    if(begin < end){
        i = begin + 1;  // begin为枢轴
        j = end;
        while(i<j){
            if(array[i]>array[begin]){
                array[i] ^=array[j] ^=array[i] ^=array[j];
                j--;
            }
            else
                i++;
        }
        if(array[i]>=array[begin])
            i--;
        array[i] ^= array[begin] ^= array[i] ^= array[begin];
        QuickSort_array_one(array,begin,i);
        QuickSort_array_one(array,j,end);
    }*/
    int pivotkey = array[low];
    if(low < high){
        while(low < high){
             while(low < high && array[high] >= pivotkey)
            high --;
            array[low] = array[high];
            while(low < high && array[low] <= pivotkey)
                low ++;
            array[high] = array[low];
        }
        array[low] = pivotkey;
        QuickSort_array_one(array,low,pivotkey);
        QuickSort_array_one(array,pivotkey,high);
    }
}