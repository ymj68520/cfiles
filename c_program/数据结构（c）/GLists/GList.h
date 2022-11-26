#include <stdio.h>

#define AtomType int
typedef enum {ATOM,LIST}ElemTag;    // ATOM = 0(原子); LIST = 1(子表)
typedef struct glnode{
    ElemTag tag;    // 公共部分，用于区分原子节点和表结点
    union{          // 原子节点与表结点的联合部分
        AtomType atom;  // atom是原子节点的值域，AtomType由用户定义
        struct{
            struct glnode *hp;  // 表结点的表头指针
        }ptr;   
    };
    struct glnode *tp;      // 相当于线性表的 *next，指向下一个结点
}GLNode,*GList; // 广义表