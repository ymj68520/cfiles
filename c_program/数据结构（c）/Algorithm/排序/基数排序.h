/*
    基数排序
        链式基数排序：
            利用静态链表完成的就地排序，它不需要额外的存储空间，因此空间复杂度低；
            在排序过程中只改变next域的值，因此时间复杂度也低；
            链式排序完成后，利用前面介绍过的Sort()和Rearrange()函数，使其有序。
            基数排序一般用于关键字为字符串的排序。
*/
#define MAX_NUM_KEY 8   // 关键字的最大长度
#define RADIX 6     // 关键字基数，此时是a~e和空
#define MAX_SPACE 100

typedef struct slcell   // 静态链表的节点类型
{
    char keys[MAX_NUM_KEY]; // 关键字
    char otheritems[15];    // 其他数据项，目前暂定为字符串
    int next;
}SLCell;
typedef struct {
    // 静态链表类型
    SLCell r[MAX_SPACE];    // 静态链表可用空间
    int keynum; // 关键字的最大常数
    int length; // 链表的当前表长
}SqList;
typedef int ArrType[RADIX]; // 指针数组类型

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

#include "fun9-2.h"

void MadeListFromFile(SqList *L,FILE *f){
    int i;
    fscanf(f,"%d",&L->r);
    L->keynum = 0;
    for(i=1;i<=L->length;i++)
    {
        fscanf(f,"%s%s",&L->r[i].keys,&L->r[i].otheritems);
        L->keynum = (L->keynum > strlen(L->r[i].keys))?L->keynum:strlen(L->r[i].keys);
        // 求关键字的最大长度
    }
    for(i=0;i<L->length;i++)    // 将L改造成静态链表
        L->r[i].next = i+1;
    L->r[L->length].next = 0;
}
int ord(char c){
    // 返回关键字c的序号
    return c-'a'+1;
}

 