#include <stdio.h>
#include <stdbool.h>

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

#define OK 1
#define ERROR 0
#define Status bool


typedef unsigned long size_t;
extern void *malloc(size_t __size);
extern void free(void *__ptr);
extern void exit(int _status);

//typedef int QElemType; //队列元素类型

typedef struct QNode{   //链队列
    QElemType data;
    struct QNode * next;
}Qnode,*QueuePtr;

typedef struct LinkQueue {
    QueuePtr front, rear; //队头(front)队尾(rear)指针
}LinkQueue;
// 构造一个空队列Q
void InitQueue (LinkQueue * Q){
    if(!(Q->front=Q->rear=(QueuePtr)malloc( sizeof(struct QNode) ) ) )
        exit(EXIT_FAILURE);
    Q->front->next = NULL;
}
// 销毁队列Q(无论空否均可)
void DestroyQueue (LinkQueue * Q){
    while (Q->front){  //彻底销毁后队首指针为NULL
        Q->rear = Q->front->next;   //将尾指针指向头结点，即销毁后空表
        free(Q->front);     //释放所有节点
        Q->front = Q->rear;  //使头指针与尾指针指向同一个节点
    }
}
// 将Q清为空队列
void ClearQueue (LinkQueue * Q){
    QueuePtr p,q;       //清空链队列时浮标
    Q->rear = Q->front;     //使队列首尾指针均指向头结点，即初始状态
    p = Q->front->next;     //设定浮标
    Q->front->next = NULL;  //使头结点的next为NULL
    while(p){   //p 不为NULL 即链队列队尾后
        q = p;          //待释放结点
        p = p->next;    //指向下一个结点
        free(q);        //释放节点
    }
}
// 若Q为空队列，则返回OK；否则返回ERROR
Status QueueEmpty (LinkQueue Q){
    if(Q.front->next == NULL)   //头结点的next为NULL即空链队列
        return OK;
    
    return ERROR;
}
// 求队列的长度
int QueueLength (LinkQueue Q){
    int i = 0;      //计数器
    QueuePtr p;     //浮标
    p = Q.front;    //使浮标指向头结点
    while(Q.rear != p){     //浮标不等于队尾
        i++;    //计数器+1
        p = p->next;    //下一个结点
    }

    return i;
}
// 若队列不为空 则用e返回该队列的队头元素，并返回OK，否则返回ERROR
Status GetHead (LinkQueue Q, QElemType * e){
    QueuePtr p;             //待指向头结点的data
    if(Q.front == Q.rear)   //判断队列是否为空
        return ERROR;       //若空返回ERROR
    p = Q.front->next;      //初始化p
    *e = p->data;           //取得队头的值
    return OK;
}
// 插入元素e，为新的队尾元素,并返回OK，否则返回ERROR
Status EnQueue (LinkQueue * Q, QElemType e){
    QueuePtr p;             //新的结点指针
    if(!(p=(QueuePtr)malloc ( sizeof(Qnode) ) ) ) //分配失败
        exit(EXIT_FAILURE);
    p->data = e;    //为新节点赋值
    p->next = NULL;     //新的队尾next为NULl
    Q->rear->next = p;  //将新节点链接到原队列
    Q->rear = p;    //队尾指针指向队尾
}
// 若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR
Status DeQueue (LinkQueue * Q, QElemType * e){
    QueuePtr p;                 //中介指针
    if( Q->front == Q->rear )   //队列为空返回ERROR
        return ERROR;
    p = Q->front->next;         //Q->front 为头结点 将队首地址赋给p
    *e = p->data;               //取得队首data
    Q->front->next = p->next;   //使头结点next指向队首下一个结点
    if(Q->rear = p)             //若队列只有一个结点
        Q->rear = Q->front;     //直接置空队列
    free(p);                    //释放结点
    return OK;
}
// 从队头到队尾依次对队列Q中每个元素调用函数visit()
void QueueTraverse (LinkQueue Q, void(*visit)(QElemType qe)){
    QueuePtr p;             //游标
    p = Q.front->next;      //游标指向队首
    while(p){               //若p到队尾则为NULL，退出循坏
        visit(p->data);     //执行visi（）
        p = p->next;        //下一个结点
    }
    printf("\n");           //
}
