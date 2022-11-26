#ifndef malloc
#include <stdlib.h>
#endif

#ifndef bool
#include <stdbool.h>
#endif

#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACK_INCREMENT 2 // 存储空间分配增量
#ifndef OK
#define OK 1
#endif
#ifndef ERROR
#define ERROR 0
#endif
#define OVERFLOW 1
//#define
//#ifndef PROTECT
//typedef int SElemType; 
//#endif
typedef bool status;

typedef struct SqStack{
    SElemType *base; // 在栈构造之前和销毁之后， base的值为NULL
    SElemType *top; // 栈顶指针
    int stacksize; // 当前已分配的存储空间，以元素为单位
}SqStack; // 顺序栈

status InitStack(struct SqStack *S);
void DestroyStack(struct SqStack *S);
void ClearStack(struct SqStack *S);
status StackEmpty(struct SqStack S);
int StackLength(struct SqStack S);
status GetTop(struct SqStack S,SElemType *e);
status Push(struct SqStack *S, SElemType e);
status Pop (struct SqStack *S, SElemType *e);
void StackTraverse(struct SqStack S,void(*visit)(SElemType));
void visit(SElemType s);

//构造空栈
status InitStack(struct SqStack *S){
    S->base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S->base) exit(OVERFLOW);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE; //初始大小
    return OK;
}
// 销毁栈S， S不再存在
void DestroyStack(struct SqStack *S){ 
    free(S->base);
    S->base=NULL;
    S->top=NULL;
    S->stacksize=0;
}
// 把S置为空栈
void ClearStack(struct SqStack *S){ 
    S->top=S->base;
}
// 若栈S为空栈，则返回TRUE；否则返回FALSE
status StackEmpty(struct SqStack S){ 
    if(S.top==S.base)
        return true;
    else
        return false;
}
// 返回S的元素个数，即栈的长度
int StackLength(struct SqStack S){ 
    return S.top-S.base;
}
//栈顶元素,用e返回
status GetTop(struct SqStack S,SElemType *e){
    if(S.base == S.top) return ERROR;
    *e = *(S.top-1);
    return OK;
}
//插入元素e为新的栈顶元素
status Push(struct SqStack *S, SElemType e){
    if(S->top - S->base >= S->stacksize){
        S->base = (SElemType*)realloc(S->base,
        (S->stacksize+STACK_INCREMENT)*sizeof(SElemType));
        
        if(!S->base) exit(OVERFLOW);
        
        S->top = S->base + S->stacksize;
        S->stacksize += STACK_INCREMENT;
    }//if
    
    *S->top ++ = e;
    return OK;
}//Push
//删除栈顶元素,用e返回其值
status Pop (struct SqStack *S, SElemType *e){
    if(S->base==S->top) return ERROR;

    *e = * --S->top;
    return OK;
}//Pop
//从栈底到栈顶依次对栈中每个元素调用函数visit()
void StackTraverse(struct SqStack S,void(*visit)(SElemType)){ 
    while(S.top>S.base)
    visit(*S.base++); //并不改变原栈
}

extern int printf(const char *__restrict__ __format, ...);
//visit()
void visit(SElemType s){
    printf("%d",s);
}