#include <stdio.h>
#include <stdlib.h>
#include "数值比较的宏.h"

#ifndef ET
typedef int ElemType; 
#endif

typedef struct SSTable{
    ElemType *elem; // 数据元素存储空间基址，建表时按照实际长度分配，0号单元留空
    int Length;  // 表长
}SSTable;  // 静态查找表

// 由数据文件构造静态顺序查找表ST
void Creat_SeqFromFile(SSTable *ST,char *filename){
    int i;
    FILE * f;
    f = fopen(filename,"r");
    fscanf(f,"%d",&ST->Length);  // 数据文件首元素为数据个数
    ST->elem = (ElemType *)calloc(ST->Length+1,sizeof(ElemType));// 首位置空出故+1
    if(!ST->elem)   // 生成失败
        exit(EXIT_FAILURE);
    for(i=1;i<=ST->Length;i++)
        InputFromFile(f,&ST->elem[i]);
        // 由文件依次输入静态顺序查找表ST的数据元素
    fclose(f);
}
void Ascend(SSTable *ST){
    // 重建静态查找表为按关键字非降序排序
    int i,j,k;
    for(i=1;i<ST->Length;i++){  // 交换排序
        k=i;    // k存当前关键字最小值的序号
        ST->elem[0] = ST->elem[i];  // 0号单元存储待比较元素
        for(j=i+1;j<=ST->Length;j++)    // 从元素i之后比起
            if LT(ST->elem[j].key,ST->elem[0].key){
                // 当前元素小于待比较元素的关键字
                k=j;    // 当前元素序号存于k
                ST->elem[0] = ST->elem[j];  // 将当前元素的值存0号单元
            }
        if(k!=i)    // 有比元素i更小的值则交换
        {
            ST->elem[k] = ST->elem[i];
            ST->elem[i] = ST->elem[0];
        }
    }
}
// 由含n个数据元素的数组r构造按关键字非降序查找表ST
void Creat_OrdFromFile(SSTable *ST,char *filename){
    Creat_SeqFromFile(ST,filename);
    Ascend(ST);
}
// 静态查找表ST存在，则销毁静态表
Status Destroy(SSTable *ST){
    free(ST->elem);
    ST->elem = NULL;
    ST->Length = 0;
    return OK;
}
// 在顺序表中顺序查找其主关键字等于Key的数据元素
// 若找到，则返回该元素在表中的位置，否则返回0
int Serch_Seq(SSTable *ST,KeyType Key){
    int i;
    ST->elem[0].key = Key;  // 监视哨，关键字存0号单元
    for(i=ST->Length;!EQ(ST->elem[i].key,Key);--i); // 从后往前找
    return i;
}
// 折半查找
int Search_Bin(SSTable *ST,KeyType key){
    int mid,low=1,high=ST->Length;
    while(low<high){
        mid = (low+high)/2; // 中值，下取整
        if EQ(key,ST->elem[mid].key)    // 中值是待查找元素
            return mid;
        else if LT(key,ST->elem[mid].key)
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return 0;
}
// 按顺序对ST的每个元素调用Visit
void Traverse(SSTable ST,void(* Visit)(ElemType)){
    int i;
    ElemType *p = ++ST.elem;    // p指向第一个元素
    for(i=1;i<ST.Length;i++)
        Visit(*p++);
}