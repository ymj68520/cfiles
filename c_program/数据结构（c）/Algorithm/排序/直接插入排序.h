/*
    将一个记录插入到已排好序的有序表中，从而得到一个全新的、记录数增1的有序表。
    第i趟直接插入排序的操作为：
        在含有i-1个记录的有序子列r[1...i-1]中插入一个记录r[i]之后变为i个记录的有序子列序列r[1...i];
        并且，和顺序查找类型，为了在查找插入位置的过程中避免数组下标出界，在r[0]出设置监视哨。
        在自i-1起往前搜索的过程中，可以同时后移记录。
        整个排序过程为进行n-1趟插入，
        即：先将序列中的第1个记录看做一个有序的子序列，然后从第二个起逐个进行插入，直至整个序列变为有序。
*/
#include "Data_Struct.h"
void InsertSort(SqList *L){
    // 对顺序表L做直接插入排序
    int i,j;
    for(i=2;i <= L->length ;i++)    // 从第二个记录到最后一个记录
        if(L->r[i].key<L->r[i-1].key)   // 当前记录小于前一个记录
        {   // 将L.r[i]插入[1~i-1]的有序子表中
            L->r[0] = L->r[i];   // 将当前记录复制为哨兵（存入[0]中）
            for(j=i-1;L->r[0].key<L->r[j].key;j--)  // 有序子表从后到前，若哨兵小于记录
                L->r[j+1] = L->r[j];    // 记录向后移一个单元
            L->r[j+1] = L->r[0];    // 将哨兵插入到正确位置            
        }
}
void InsertSort_array(int ar[],int length){
    int i,j;
    int sentry=0;
    for(i=1;i<length;i++){
        if(ar[i]<ar[i-1]){
            sentry = ar[i];
            for(j=i-1;j>=0;j--)
                ar[j+1] = ar[j];    // 移位
            ar[j+1] = sentry;
        }
    }
}

// 折半插入排序
void BInsertSort(SqList *L){
    int i,j,m,low,high;
    for(i=2;i<=L->length;i++)   // 从第二个记录到最后一个记录
        if(L->r[i].key < L->r[i-1].key)   // 当前记录小于前一个记录，将L.r[i]插入前面有序子集中
        {
            L->r[0] = L->r[i];  // 暂存r[i]
            low = 1;    // 插入区间的低端
            high = i-1; // 区间高端
            while(low <= high)  // 在区间内折半查找待插入位置
            {
                m = (low + high)/2; // 中点位置
                if(L->r[0].key<L->r[m].key) // 关键字小于中点关键字
                    high = m-1; // 待插入区间在低位区间
                else
                    low = m + 1;    // 在高位区间
            } // low > high  [high+1]是待插入位置
            for(j=i-1;j>=high+1;j--)
                L->r[j+1] = L->r[j];    // 记录后移
            L->r[high+1] = L->r[0]; 
        }
}
void BInsertSort_array(int ar[],int length){
    int i,j,m,low,high,sentry;
    for(i=1;i<length;i++)
        if(ar[i] < ar[i-1]){
            sentry = ar[i];
            low = 1; high = i-1;
            while(low <= high){
                m = (low + high)/2;
                if(sentry < ar[m])
                    high = m-1;
                else
                    low = m+1;
            }
            for(j=i-1;j>=high+1;j--)
                ar[j+1] = ar[j];
            ar[high+1] = sentry;
        }
}

// 2-路插入排序（flag=0）和改进的2-路插入排序（flag=1）
// flag = 1, 当L.r[1]是待排序记录中关键字最小或最大的记录时，扔有优越性
// 循环数组,从first-final为一路，从final-first是二路
void P2_InsertSort(SqList *L, int flag){
    int i,j,first,final,mid=0;
    RedType *d;
    d = (RedType *)malloc(sizeof(RedType)*L->length);
    d[0] = L->r[1]; // 设L的第一个记录为d中排序好的记录（在位置[0]）
    first = final = 0;  // first\final分别指示d中排序好的记录的第一个和最后一个记录的位置
    for(i=2;i<=L->length;i++)   // 依次将L的第二个~最后一个记录插入d中
    {
        if(flag)    // 改进的2-路插入排序，每次插入之前都求mid
        {
            if(first > final)       // 此时意味着循环数组的first下标是负数
                j = L->length;  // j是调整系数
            else
                j = 0;
            mid = (first + final + j)/2 % L->length;    // d的中间记录的位置
        }
        if(L->r[i].key < d[mid].key)    // 待插记录将插在d的前半部分中（flag=0时，mid=0）
        { // mid为0时即为第一个元素
            j = first;  // j指向d的第一个记录
            first = (first-1 + L->length) % L->length;  // first 前移,
            // 需考虑数组下标为-1的情况,因此为循环数组，求模运算保证下标有效
            while(L->r[i].key > d[j].key)   // 待插记录大于j所指记录
            {
                d[(j-1+L->length)%L->length] = d[j];    // j所指记录前移
                j = (j+1) % L->length;  // j指向下一个记录
                // 考虑到数组下标为length+1的情况，求模运算保证下标有效
            }
            d[(j-1+L->length)%L->length] = L->r[i]; // 移动结束，待插记录在[j]前
            // 即为原记录的(first-1) % length 的位置
        }
        else// 待插记录在后半段
        {
            j = final++;    // j指向当前的最后一个记录，final指向插入后的最后一个记录
            while(L->r[i].key < d[j].key)   // 待插记录小于j所指记录
            {
                d[(j+1)%L->length] = d[j];  // j所指记录后移，flag=0时不必求余
                j = (j-1+L->length) % L->length;    // j指向上一个记录，flag=0时不必求余
            }
            d[(j+1)%L->length] = L->r[i];   // 待插记录不小于j所指记录，插在j后，flag=0时不必求余
        }
    }// 总长度为记录的总个数，因此下标不会发生冲突
    for(i=1;i<L->length;i++)    // 把在d中排好序的记录依次赋值给L.r
        L->r[i] = d[(first+i-1)%L->length]; // 线性关系
    free(d);
}
void P2_InsertSort_array(int ar[],int length){
    int i,j,first,final;
    first = final = 0;
    int array[length];
    array[0] = ar[0];
    for(i=1;i<length;i++){
        if(ar[i]<array[0])  // 比有序子表的首元小
        {
            j = first;
            first = (first - 1 + length) % length;
            while(ar[i] > array[j]){
                array[(j-1+length)%length] = array[j];
                j = (j+1+length)%length;
            }
            array[(j-1+length)%length] = ar[i];
        }
        else{
            j = final;
            final = (final + 1)%length;
            while(ar[i]<array[j]){
                array[(j+1)%length] = array[j];
                j = (j-1+length)%length;
            }
            array[(j+1)%length] = ar[i];
        }
    }
    for(i=first,j=0;(i%length)!=final;i++,j++)
        ar[j] = array[i];
    return;
}