/*
    希尔排序（缩小增量排序），属于插入排序，但时间效率优于前几种插入排序；
        时间复杂度可以提高至 O(N) 级别
    若待排序序列中的记录“基本有序”，则插入排序的效率较高，
    而在n较小是，插入排序的效率也比较高。

    基于如上两个结论，希尔排序为插入排序的改进算法。

    基本思想：
        先将整个待排序记录全体分割为若干子序列分别进行直接插入排序，
        待整个序列中的记录基本有序时，再对全体记录进行一次直接插入排序。
    特点：
        子序列的构成是以一个特定的增量逐段分割。
        在最后一次进行简单插入排序时，记录序列已经基本有序
*/
typedef int KeyType;
typedef int InfoType;
#include "Data_Struct.h"
#include "../查找/静态查找表/数值比较的宏.h"

// 输出L的关键字
void Print1(SqList L){
    for(int i=1;i<L.r[i].key;i++)
        printf("%d",L.r[i].key);
    putchar('\n');
}
// 对顺序表做一趟希尔排序，算法和一趟插入排序相比，做如下约定：
// 1.前后记录位置的增量是dk，而不是1
// 2.r[0]只是暂存单元，而不是哨兵。当j<=0时，插入位置已经找到
void ShellInsert(SqList *L, int dk){
    int i,j;
    for(i = dk+1; i<=L->length; i++)    // 从与第一个记录相差增量dk的记录到表尾
        if  LT(L->r[i].key,L->r[i-dk].key){
            // 关键字小于前面记录的关键字
            // 以下将L->r[i]插入
            L->r[0] = L->r[i];  // 暂存记录于0号位
            for(j=i-dk;j>0&&LT(L->r[0].key,L->r[j].key);j-=dk)
                L->r[dk+j] = L->r[j];   // 记录后移，查找插入位置
            L->r[j+dk] = L->r[0];   // 插入
        }
}
// 按照增量序列dlta[0~t-1]对顺序表L做希尔排序
void ShellSort(SqList *L, int dlta[],int t){
    int k;
    for(k=0;k<t;k++){
        ShellInsert(L,dlta[k]);
        printf("dlta[%d] = %d, 第%d趟排序结果（仅输出关键字）：",k,dlta[k],k+1);
        Print1(*L);
    }
}


