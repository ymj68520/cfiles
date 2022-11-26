/*
    归并排序
     2-路归并
        将一维数组中前后相邻的两个有序序列归并为一个有序序列。
*/

#include "../查找/静态查找表/数值比较的宏.h"
typedef int KeyType;
typedef int InfoType;
#include "Data_Struct.h"

// 将有序的SR[i~m]和SR[m+1~n]归并为有序的TR[i~n]
void Merge(RedType SR[],RedType TR[],int i,int m,int n){
    int j,k,p;
    for(j=m+1,k=i;i<=m && j<=n;k++)     // 将SR中记录由小到大并入TR
        if LQ(SR[i].key,SR[j].key)
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    if(i<=m)
        for(p=0;p<=m-i;p++)
            TR[k+p] = SR[i+p];      // 将剩余的SR[i+m]复制到TR
    if(j<=n)
        for(p=0;p<=n-j;p++)
            TR[k+p] = SR[j+p];  // 将剩余的SR[j~n]复制到TR
}
// 将SR[s-t]归并为TR1[s~t]
void MSort(RedType SR[],RedType TR1[],int s,int t){
    int m;
    RedType TR2[MAXSIZE+1];
    if(s==t)    // 只有一个元素待归并
        TR1[s] = SR[s]; // 直接赋值
    else{
        // 有多个元素待归并
        m = (s+t)/2;    // 将SR[s~t]平分为SR[s~m],SR[m+1~t]
        MSort(SR,TR2,s,m);  // 递归的将SR[s~m]归并为有序的TR2[s~m]
        MSort(SR,TR2,m+1,t); // 递归的归并后半段
        Merge(TR2,TR1,s,m,t);   // 将TR2[s~m]和TR1[m+1~t]归并为TR1
    }
}
void MergeSort(SqList *L){
    MSort(L->r,L->r,1,L->length);
}