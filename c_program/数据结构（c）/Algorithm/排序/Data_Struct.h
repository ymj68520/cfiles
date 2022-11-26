#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

#define Status bool
#define OK true
#define ERROR false

#define MAXSIZE 20      // 一个用作示例的小顺序表的最大长度

typedef int KeyType;    // 定义关键字类型为整型

// Infotype 在主调函数里定义
typedef struct {
    KeyType key;    //关键字项
    InfoType otherinfo; // 其他数据项
}RedType;   // 记录类型

typedef struct{
    RedType r[MAXSIZE+1];   // r[0]闲置或者用作哨兵
    int length; // 顺序表长度
}SqList;    // 顺序表类型

//  当KeyType与InfoType均为整数时配套的输入输出函数
void Print(SqList L){
    int i;
    for(i=1;i<=L.length;i++)
        printf("(%d, %d)",L.r[i].key,L.r[i].otherinfo);
    putchar('\n');
}
void InputFromFile(FILE *f, RedType *c){
    fscanf(f,"%d%d",&c->key,&c->otherinfo);
}