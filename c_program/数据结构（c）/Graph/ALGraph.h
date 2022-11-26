#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// 邻接表
#ifndef MAX_VERTEX_NUM
#define MAX_VERTEX_NUM 20   // 最大顶点数
#endif
#define MAX_NAME 9      // 顶点名称最大长度+1
typedef struct{
    char name[MAX_NAME];
}VertexType;
void Visit(VertexType ver)  // 与之配套的访问函数
{
    printf("%s",ver.name);
}
void Input(VertexType *ver) // 与之配套的输入顶点信息的函数
{
    scanf("%s",(*ver).name);
}
void InputFromFile(FILE *f,VertexType *ver)      // 与之配套的从文件输入顶点信息的函数
{
    fscanf(f,"%s",(*ver).name);
}

typedef int VRType;     // 定义权值为整型
typedef struct infotype{
    VRType weight;      // 权值
}InfoType;
void InputArc(InfoType * *arc)  // 与之配套的输入弧的相关信息的函数
{
    *arc = (InfoType *)malloc(sizeof(InfoType));
    scanf("%d",&(*arc)->weight);
}
void OutputArc(InfoType * arc)  // 与之配套的输出弧的相关信息的函数
{
    printf(": %d",arc->weight);
}
void InputArcFromFile(FILE *f,InfoType * *arc){
    *arc = (InfoType*)malloc(sizeof(InfoType));
    fscanf(f,"%d",&(*arc)->weight);
}

typedef enum GraphKind{DG,DN,UDG,UDN}GraphKind;

typedef struct elemtype{    // 新增
    int adjvex;     // 该弧所指向的顶点的位置
    InfoType * info;    // 弧相关信息（包括网的权值）的指针
}ElemType;

typedef struct ArcNode // 表结点 存弧的信息
{
    ElemType data;     // 除指针以外的部分都属于Elemtype
    struct ArcNode *nextarc;    // 指向下一条弧的指针
}ArcNode;
typedef struct  // 头结点，存顶点的信息 
{
    VertexType data;        // 顶点信息
    ArcNode *firstarc;  // 第一个表结点的地址 指向第一条依附该顶点的弧的指针
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct algraph      // 邻接表结构
{
    AdjList vertices;   // 头结点（顶点）组数
    int vexnum,arcnum;  // 图当前的顶点数和弧数
    GraphKind kind;      // 图的种类
}ALGraph;
#define LNode ArcNode   // 新增定义单链表的结点类型是图的表结点类型
#define next nextarc    // 新增定义单链表结点的指针域是表结点指向下一条弧的指针域
typedef ArcNode *LinkList; // 新增定义指向单链表结点的指针是指向图的表结点指针
#include <stdbool.h>
#define Status bool
#define OK true
#define ERROR false

#define elem eeeeeee
#include "List.h"

// 图的邻接表存储

// 若图G存在 u和G中有顶点有相同特征（名称相同
// 返回该顶点在图中的位置
int LocateVex(ALGraph G,VertexType u){
    int i;
    for(i=0;i<G.vexnum;i++) // 对所有顶点依次查找
        if(strcmp(u.name,G.vertices[i].data.name)==0)
            return i;
    return -1;
}
// 采用邻接表存储结构，构造图或网G（用一个函数构造四种图）
void CreateGraph(ALGraph *G){
    int i,j,k;
    VertexType v1,v2;   // 顶点类型
    ElemType e; // 表结点的元素类型（存储弧的信息）
    char s[4] = "边";
    printf("请输入图的类型（有向图：0，有向网：1，无向图：2，无向网：3）：");
    scanf("%d%*c",&(*G).kind);
    if(G->kind<2)   // 有向
        strcpy(s,"弧");
    printf("请输入图的顶点数，边数：\n");
    scanf("%d %d%*c",&(*G).vexnum,&(*G).arcnum);
    printf("请输入%d个顶点的值（名字<%d个字符）：\n",G->vexnum,MAX_NAME);
    for(i=0;i<G->vexnum;i++)     // 构造顶点向量
    {
        Input(&(G->vertices[i].data)); // 输入顶点信息
        G->vertices[i].firstarc = NULL; // 初始化与该顶点有关的出弧链表
    }
    printf("请输入%d条%s的",G->arcnum,s);
    switch(G->kind){
        case DG:printf("弧尾 弧头：\n");   // 设图无弧信息
                break;
        case DN:printf("弧尾 弧头 弧的信息：\n");   // 弧的信息在这里被定义为网的权值
                break;
        case UDG:printf("顶点1 顶点2：\n"); // 设图没有弧信息
                break;
        case UDN:printf("顶点1 顶点2 边的信息：\n");
                break;
    }
    for(k=0;k<G->arcnum;k++)    // 构造相关弧链表
    {
        scanf("%s %s",v1.name,v2.name);
        i = LocateVex(*G,v1);   // 弧头
        j = LocateVex(*G,v2);   // 弧尾
        e.info = NULL;  // 给待插表结点e赋值，设图无弧信息
        if(G->kind % 2){    // 网
            InputArc(&e.info);
        }
        e.adjvex = j;   // 弧头
        ListInsert(&(G->vertices[i].firstarc),1,e);   // 将e插在第i个顶点（出弧）的表头
        if(G->kind>=2)  // 无向
        {
            e.adjvex = i;   // e.info 不变 不必再次赋值
            ListInsert(&G->vertices[j].firstarc,1,e);   // 插在第j个顶点的表头
        }
    }
}
// 采用邻接表存储结构，由文件构造图或网G（用一个函数构造4种图）
void CreateFromFile(ALGraph *G,char *filename){
    int i,j,k;
    VertexType v1,v2;   // 顶点类型
    ElemType e;     // 表结点的元素类型（存储弧的信息）
    FILE *f;        // 文件指针类型
    f = fopen(filename,"r");    // 以只读的方式打开数据文件并以f表示
    fscanf(f,"%d",&(*G).kind);
    fscanf(f,"%d",&(*G).vexnum);
    for(i=0;i<(*G).vexnum;i++){
        InputFromFile(f,&((*G).vertices[i].data));
        (*G).vertices[i].firstarc = NULL;
    }
    fscanf(f,"%d",&(*G).arcnum);
    for(k=0;k<(*G).arcnum;k++){
        fscanf(f,"%s %s",v1.name,v2.name);
        i = LocateVex(*G,v1);
        j = LocateVex(*G,v2);
        e.info = NULL;
        if((*G).kind%2)
            InputArcFromFile(f,&(e.info));
        e.adjvex = j;
        ListInsert(&((*G).vertices[i].firstarc),1,e);
        if((*G).kind>=2){
            e.adjvex = i;
            ListInsert(&((*G).vertices[j].firstarc),1,e);
        }
    }
    fclose(f);
}
// 若图G存在，v是G中的某个顶点的序号 则返回v的值
VertexType GetVex(ALGraph G,int v){
    if(v>=G.vexnum||v<0)        // 序号v非法
        exit(EXIT_FAILURE);
    return G.vertices[v].data;  // 返回顶点的值
}
// 若图G存在v是G中某个顶点 则对v赋值value
Status PutVex(ALGraph *G,VertexType v,VertexType value){
    int k = LocateVex(*G,v);    // k为v的序号
    if(k!=-1){  // v是G的顶点
        (*G).vertices[k].data = value;
        return OK;
    }
    return ERROR;
}
// 若图G存在，v是G中某个顶点的序号 则返回v的第一个邻接顶点序号若没有则返回-1
int FirstAdjVex(ALGraph G,int v){
    ArcNode * p = G.vertices[v].firstarc;   // p 指向顶点v的第一个邻接顶点
    if(p)   // 顶点有邻接顶点
        return p->data.adjvex;
    else
        return -1;
}
// delete next 要调用的函数
Status equalvex(ElemType a,ElemType b){
    if(a.adjvex == b.adjvex)    // 表结点的顶位置（序号）相同
        return OK;
    else 
        return ERROR;
}
// 若图G存在，v是G中的某个顶点的序号，w是v的邻接顶点的序号 
// 则 返回v的（相对于w的）下一个邻接顶点的序号，若w是v的最后一个邻接顶点，则返回-1
int NextAdjVex(ALGraph G,int v,int w){
    LinkList p,p1;  // p1在Point()中用作辅助指针
    ElemType e; // 表结点的元素类型（存储弧的信息
    e.adjvex = w;
    p = Point(G.vertices[v].firstarc,e,equalvex,&p1);
    // p指向顶点v的链表中邻接顶点为w的结点
    if(!p||!p->nextarc) // 未找到w或w是最后一个邻接顶点
        return -1;
    else    // p->data.adjvex == w
        return p->nextarc->data.adjvex; // 返回v（相对于w）的下一个邻接顶点的序号
}
// 若图G存在，v和图中顶点有相同的特征
// 在图中增添结点v（不添加弧）
void InsertVex(ALGraph *G,VertexType v){
    (*G).vertices[(*G).vexnum].data = v;    // 构造新顶点向量
    (*G).vertices[(*G).vexnum].firstarc = NULL; // 没有与顶点相关的弧
    (*G).vexnum ++; // 顶点数加一
}
// 若G存在，v和w是G中的两个顶点 则在G中增添弧<v,w> 若G无向则还添加对称弧<w,v>
Status InsertArc(ALGraph *G,VertexType v,VertexType w){
    ElemType e; // 表结点的元素类型（存储弧的信息）
    int i,j;
    char s1[4] = "边";
    char s2[7] = "——";  // 无向的情况
    if((*G).kind<2) // 有向
    {
        strcpy(s1,"弧");
        strcpy(s2,"->");
    }    
    i = LocateVex(*G,v);    // 弧尾或边的序号
    j = LocateVex(*G,w);    // 弧头或边的序号
    if(i<0 || j<0)
        return ERROR;       // v和w中至少有一个不是G中的顶点
    G->arcnum++;    // G的边数加一
    e.adjvex = j;   // 弧头表结点的值
    e.info = NULL;  // 初值，设图无弧信息
    if(G->kind%2)   // 网
    {
        printf("请输入%s %s %s %s的信息：",s1,v.name,s2,w.name);
        InputArc(&e.info);
    }
    ListInsert(&((*G).vertices[i].firstarc),1,e);
    // 将e插在弧尾的表头
    if(G->kind>=2)  // 无向 生成另一个表结点
    {
        e.adjvex = i;   // 弧尾表结点的值，e.info不变
        ListInsert(&((*G).vertices[j].firstarc),1,e);
    }
    return OK;
}
// 若图G存在 v和w是G中的两个顶点    则删除弧<v,w>
// 若图无向则还删除对称弧<w,v>
Status DeleteArc(ALGraph *G,VertexType v,VertexType w){
    int i,j,n;
    ElemType e; // 表结点的元素类型
    i = LocateVex(*G,v);    // i是顶点v(弧尾)的序号
    j = LocateVex(*G,w);    // j是顶点w(弧头)的序号
    if(i<0 || j<0 || i==j)  // v和w至少有一个不是G中的结点 或v和w是同一个节点
        return ERROR;
    e.adjvex = j;   // 弧头表结点的值
    n = LocateElem((*G).vertices[i].firstarc,e,equalvex);
    // 在弧尾链表中找弧头的表结点 将其在链表中的位序赋给n
    if(n)   // 存在弧
    {
        ListDelete(&((*G).vertices[i].firstarc),n,&e);
        //  在弧尾表中删除弧头表的结点，并用e返回其值
        G->arcnum -- ;  // 弧数减一
        if(G->kind%2)   // 网，设图无弧信息
        {
            free(e.info);
        }
        if(G->kind>=2)  // 无向 删除对称弧<w,v>
        {
            e.adjvex = i;   // 弧尾表结点的值
            n = LocateElem(&((*G).vertices[j].firstarc),e,equalvex);
            // 在弧头链表中找弧尾表结点，将其在链表中的位置赋给n
            ListDelete(&((*G).vertices[j].firstarc),n,&e);
            // 在弧头链表中删除弧尾表结点 用e返回其值
        }
        return OK;
    }
    else // 未找到待删除的弧
        return ERROR;
}
// 若G存在 v是G中的某个顶点 则删除G中顶点v及其相关弧
Status DeleteVex(ALGraph *G,VertexType v){
    int i,k;
    LinkList p; // 表结点类型
    k  = LocateVex(*G,v);   // k为待删除结点的序号
    if(k<0) // v不是图G的顶点
        return ERROR;
    for(i=0;i<(*G).vexnum;i++)
        DeleteArc(G,v,(*G).vertices[i].data); // 删除由顶点v发出的所有弧
    if(G->kind<2)   // 有向
        for(i=0;i<(*G).vexnum;i++)
            DeleteArc(G,(*G).vertices[i].data,v); // 删除发向v的所有弧
    for(i=0;i<(*G).vexnum;i++)  // 对于adjvex域>k的结点，其序号-1
    {
        p = (*G).vertices[i].firstarc;  // p指向弧结点的单链表
        while(p)    // 未到表尾
        {
            if(p->data.adjvex>k)
                p->data.adjvex --;  // 序号-1 （因为前移
            p = p->nextarc;
        }
    }
    for(i=k+1;i<(*G).vexnum;i++)
        (*G).vertices[i-1] = (*G).vertices[i];  // 顶点v后面的顶点依次前移
    (*G).vexnum --; // 顶点数-1
    return OK;
}
// 销毁图G
void DestroyGraph(ALGraph *G){
    int i;
    for(i=(*G).vexnum-1;i>=0;i--)   // 由大到小逐一删除顶点及与其相关的弧
        DeleteVex(G,(*G).vertices[i].data);
}
// 输出图的邻接矩阵
void Display(ALGraph G){
    int i;
    ArcNode *p;
    char s1[4] = "边",s2[7] = "——"; // 无向的情况
    if(G.kind<2)    // 有向
    {
        strcpy(s1,"弧");
        strcpy(s2,"->");
    }
    switch(G.kind){
        case DG:printf("有向图\n");
                break;
        case DN:puts("有向网");
                break;
        case UDG:puts("无向图");
                break;
        case UDN:puts("无向网");
    }
    printf("%d 个顶点，依次是：",G.vexnum);
    for(i=0;i<G.vexnum;i++)
        Visit(GetVex(G,i)); // 根据顶点信息的类型 访问第i个顶点
    printf("\n%d 条 %s:\n",G.arcnum,s1);
    for(i=0;i<G.vexnum;i++)
    {
        p = G.vertices[i].firstarc; // p指向序号为i的顶点的第一条弧
        while(p)
        {
            if(G.kind<=1||i<p->data.adjvex) // 有向或无向两次中的一次
            {
                printf(" %s%s%s",G.vertices[i].data.name,s2,G.vertices[p->data.adjvex].data.name);
                if(G.kind%2)    // 网
                {
                    OutputArc(p->data.info);
                }
            }
            p = p->nextarc;
        }
        putchar('\n');
    }
}



