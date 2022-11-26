/*
    选择排序：
        基本思想：
            每一趟在n-i+1(i=1,2...n-1)个记录中选取关键字最小的记录作为有序序列中第i个记录。
            其中最简单的为简单选择排序。
*/
#include "Data_Struct.h"

// 简单选择排序

// 返回在L.r[i-L.length]中key最小的记录的序号
int SelectMinKey(SqList L,int i){
    int j,k=i;  // 初始设置[i]的关键字为最小存i于k
    KeyType min = L.r[i].key;   // [i]的关键字存于min
    for(j=i+1;j<=L.length;j++)
        if(L.r[j].key<min){
            // 找到更小的Key
            k = j;  // 分别将更小的赋给k和min
            min = L.r[j].key;
        }
    return k;
}
// 对顺序表做选择排序
void SelectSort(SqList *L){
    int i,j;
    RedType t;
    for(i=1;i < L->length; i++) // 选择第i小的记录，并交换到位
    {
        j = SelectMinKey(*L,i); // 在L.r[i~L.length]中选择key最小的记录
        if(i!=j){
            t = L->r[i];    // 与第i个记录交换，使得第i小的存于[i]
            L->r[i] = L->r[j];
            L->r[j] = t;
        }
    }
}
