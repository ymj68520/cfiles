// 顺序存储的数组——使用结构
// ADT Array {
//     数据对象：j(i)=0,...,b(i)-1; i = 1,2,3...n;
//     D = {a(j1 j2 ... jn)| n(>0)称为数组维数，b(i)是数组第i维长度，
//      j(i)是数组元素的第i维下标}
// }
// 线性结构存储，以下为行序为主序的数组链表线性描述
// 假设每个ElemType占据 L 个存储单元，则二维数组中的任一元素a(i j)的存储位置
// 可由式子：LOC(i,j) = LOC(0,0) + (b2 * i + j)L; // LOC(0,0) 是a(0,0)的位置
// 多维数组推广上式，被称为n维数组的映像函数;

#include <stdarg.h>     // 提供变长串支持
#include <stdbool.h>    // 提供布尔型支持
#include <stdlib.h>     // 动态分配支持

#define MAX_ARRAY_DIM 8 // 假设数组维数的最大值为8
#ifndef PROTECT
typedef int ElemType;   // 临时用，具体用时在.c文件中定义
#endif
typedef struct Array {
    ElemType *base;     // 数组元素基址，由InitArray分配
    int dim;            // 数组维数
    int *bounds;        // 数组维界基址，InitArray分配
    int *constants;     // 数组映像函数常量基址，InitArray分配
}Array;

#define OVERFLOW 2
#define Status int
#define OK true
#define ERROR false
#define FASLSE false
#define TRUE true
#define UNDERFLOW 4

// 若维数dim和各维长度(dim后的参数)合法，则构造相应的数组A，并返回OK
Status InitArray(Array *A,int dim,...){
    int elemtotal = 1;          // elemtotal是数组元素总数，初值为1(累乘器)
    int i;
    va_list ap;                 // 变长宏类型
    if(dim<1 || dim>MAX_ARRAY_DIM)  // 维数不合法
        return ERROR;
    A->dim = dim;                // 维数赋值
    A->bounds = (int *)malloc(dim*sizeof(int));    // 数组维界
    if(!A->bounds)              // 分配失败
        return OVERFLOW;
    va_start(ap,dim);           // 变长宏开始
    for(i=0;i<dim;++i){
        A->bounds[i] = va_arg(ap,int);  // 读取一个变长宏中的一个int型
        if(A->bounds[i]<0)              // 维长度不合法
            return UNDERFLOW;
        elemtotal *= A->bounds[i];      // 累乘器递增（总元素个数）
    }
    va_end(ap);                 //结束变长宏
    A->base = (ElemType *)malloc(elemtotal*sizeof(ElemType));   // 元素基址分配空间
    if(!A->base)        //  分配失败
        return OVERFLOW;
    A->constants = (int *)malloc(dim*sizeof(int ));     // 映像函数分配空间
    if(!A->constants)
        return OVERFLOW;
    A->constants[dim-1]=1;
    for(i=dim-2;i>=0;--i)   
        A->constants[i]=A->bounds[i+1]*A->constants[i+1];      // 印象函数值——到达下一维
    return OK;
}
// 销毁数组A
void DestroyArray(Array *A){
    if(A->base)
        free(A->base);
    if(A->bounds)
        free(A->bounds);
    if(A->constants)
        free(A->constants);
    A->base = A->bounds = A->constants = NULL;
    A->dim = 0;
}
// 若ap指示的各下标值合法，则求出该元素在A中的相对地址off
Status Locate (Array A,va_list va,int * off){
    int i,ind;      // 检查维数是否合法
    *off = 0;
    for(i=0;i<A.dim;++i){
        ind = va_arg(va,int);
        if(ind<0 || ind>=A.bounds[i])   // 检查维数
            return OVERFLOW;
        *off += A.constants[i] * ind;   // 位置
    }
    return OK;
}
// ...依次为各维的下标值，若各下标合法，则e被赋值为A的相应的元素值
Status Value(ElemType *e,Array A,...){
    va_list ap;
    int off;
    va_start(ap,A);
    if(Locate(A,ap,&off)==OVERFLOW)
        return ERROR;
    *e = *(A.base+off);
    return OK;
}
// ...依次为各维的下标值，若各下标合法，则将e的值赋给A的指定的元素
Status Assign (Array A, ElemType e,...){
    va_list ap;
    int off;
    va_start(ap,e);
    if(Locate(A,ap,&off)==OVERFLOW)
        return ERROR;
    *(A.base+off) = e;
    return OK;
}


