#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Qu 4 // 客户队列数
#define Khjg 5 // 两相邻到达的客户的时间间隔最大值
#define Blsj 30 // 每个客户办理业务的时间最大值

typedef bool Status;

typedef struct {
    int OccurTime;  //事件发生时刻
    int NType;      //事件类型，0表示到达，1-4表示四个窗口的离开事件
}Event, ElemType;   //事件类型，有序链表Linklist数据类型

#include "Linklist.h"

typedef LinkList EventList;         // 事件链表指针类型，定义为有序链表
typedef struct {
    int ArrivalTime; // 到达时刻
    int Duration; // 办理事务所需时间
}QElemType; // 定义队列的数据元素类型QElemType为结构体类型

#include "queue.h"

// 程序中用到的主要变量(全局)
EventList ev; // 事件表头指针
Event en,et; // 事件,临时变量
//FILE *fp; // 文件型指针，用于指向b.txt或d.txt文件
long int TotalTime=0; // 累计客户逗留时间(初值为0)
int CloseTime,CustomerNum=0; // 银行营业时间(单位是分),客户数(初值为0)

int cmp(Event a,Event b)
{ // 依事件a的发生时刻<、 =或>事件b的发生时刻分别返回-1、 0或1
    if(a.OccurTime==b.OccurTime)
        return 0;
    else
        return (a.OccurTime-b.OccurTime)/abs(a.OccurTime-b.OccurTime);//-1 || 1
}

void Random(int *d,int *i)
{ // 生成两个随机数
    *d=rand()%Blsj+1; // 1到Blsj之间的随机数(办理业务的时间)//10
    *i=rand()%(Khjg+1); // 0到Khjg之间的随机数(客户到达的时间间隔)//5
}

void OpenForDay();
void CustomerArrived();
void CustomerDeparture();

void Bank_Simulation()
{ // 银行业务模拟函数
    LinkList p;
    OpenForDay(); // 初始化事件表ev且插入第1个到达事件，初始化队列
    while(!ListEmpty(ev)) // 事件表ev不空
    {
        DelFirst(ev,ev->next,p); // 删除事件表ev的第1个结点，并由p返回其指针，在bo2-6.cpp中
// if(p->data.OccurTime<50) // 输出前50分钟内发生的事件到文件d.txt中
// fprintf(fp,"p->data.OccurTime=%3d p->data.NType=%d\n",p->data.OccurTime,p->data.NType);
        en.OccurTime=p->data.OccurTime;
// GetCurElem()在bo2-6.cpp中，返回p->data(ElemType类型)
        en.NType=p->data.NType;
        if(en.NType==Qu) // 到达事件
            CustomerArrived(); // 处理客户到达事件
        else // 由某窗口离开的事件
            CustomerDeparture(); // 处理客户离开事件
    } // 计算并输出平均逗留时间
    printf("窗口数=%d 两相邻到达的客户的时间间隔=0～%d分钟 每个客户办理业务的时间=1～%d分钟\n",Qu,Khjg,Blsj);
    printf("客户总数:%d, 所有客户共耗时:%ld分钟,平均每人耗时:%d分钟,",CustomerNum,TotalTime,
            TotalTime/CustomerNum);
    printf("最后一个客户离开的时间:%d分\n",en.OccurTime);
}

LinkQueue q[Qu]; // Qu个客户队列
QElemType customer; // 客户记录，临时变量
//FILE *fq; // 文件型指针，用于指向a.txt文件
void OpenForDay()
{ // 初始化事件链表ev且插入第1个到达事件，初始化Qu个队列
    int i;
    InitList(ev); // 初始化事件链表ev为空(见图342)
    en.OccurTime=0; // 设定第1位客户到达时间为0
    // (银行一开门，就有客户来)
    //fprintf(fq,"首位客户到达时刻=%3d,",en.OccurTime);
    en.NType=Qu; // 到达
    OrderInsert(ev,en,cmp); // 将第1个到达事件en有序插入事件表ev中
    for(i=0;i<Qu;++i) // 初始化Qu个队列
    InitQueue(q+i);
}

int Minimum(LinkQueue Q[])
{ // 返回最短队列的序号，若有并列值，返回队列序号最小的
    int l[Qu];
    int i,k=0;
    for(i=0;i<Qu;i++)
        l[i]=QueueLength(Q[i]);
    for(i=1;i<Qu;i++)
    if(l[i]<l[0])
    {
        l[0]=l[i];
        k=i;
    }
    return k;
}

void CustomerArrived()
{ // 处理客户到达事件en(en.NType=Qu)
    QElemType f;
    int durtime,intertime,i;
    ++CustomerNum; // 客户数加1
    Random(durtime,intertime);//生成当前客户办理业务的时间和下一个客户到达的时间间隔2个随机数
    et.OccurTime=en.OccurTime+intertime; // 下一客户et到达时刻等于当前客户en的到达
    // 时间加时间间隔
    et.NType=Qu; // 下一客户到达事件
    i=Minimum(q); // 求长度最短队列的序号，等长为最小的序号(到达事件将入该队)
//if(CustomerNum<=20) // 输出前20个客户到达信息到文件a.txt中
// fprintf(fq,"办理业务的时间=%2d,所排队列=%d\n下一客户到达时刻=%3d,",durtime,i,et.OccurTime);
    if(et.OccurTime<CloseTime) // 下一客户到达时银行尚未关门
    OrderInsert(ev,et,cmp); // 按升序将下一客户到达事件et插入事件表ev中，在bo2-6.cpp中
    f.ArrivalTime=en.OccurTime; // 将当前客户到达事件en赋给队列元素f
    f.Duration=durtime;
    EnQueue(q+i,f); // 将f入队到第i队列(i=0～Qu-1)
    if(QueueLength(q[i])==1) // 该元素为队头元素
    {   
        et.OccurTime=en.OccurTime+durtime; // 设定一个离开事件et
        et.NType=i;
        OrderInsert(ev,et,cmp); // 将此离开事件et按升序插入事件表ev中
    }
}

void CustomerDeparture()
{ // 处理客户离开事件en(en.NType<Qu)
    int i;
    i=en.NType; // 确定离开事件en发生的队列序号i
    DeQueue(q+i,&customer); // 删除第i队列的排头客户
    TotalTime+=en.OccurTime-customer.ArrivalTime;
    // 客户逗留时间=离开事件en的发生时刻-该客户的到达时间
    if(!QueueEmpty(q[i]))
    { // 删除第i队列的排头客户后，第i队列仍不空
        GetHead(q[i],&customer); // 将第i队列新的排头客户赋给customer
        et.OccurTime=en.OccurTime+customer.Duration;
    // 设定离开事件et,新排头的离开时间等于原排头的离开时间加新排头办理业务的时间
        et.NType=i; // 第i个队列的离开事件
        OrderInsert(ev,et,cmp); // 将此离开事件et按升序插入事件表ev中
    }
}

void main()
{
//fq=fopen("a.txt","w"); // 打开a.txt文件，用于写入客户到达信息
//fp=fopen("b.txt","w"); // 打开b.txt文件，用于写入有序事件表的历史记录
    printf("请输入银行营业时间长度(单位:分): ");
    scanf("%d",&CloseTime);
//srand(time(0));
// 设置随机数种子，以使每次运行程序产生的随机数不同(time(0)是长整型数，与调用时间有关)
    Bank_Simulation();
//fclose(fq); // 关闭a.txt
//fclose(fp); // 关闭b.txt
}