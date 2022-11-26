// 数据对象：具有相同特性的数据元素的集合 即顶点集
// 数据关系：<v,w>表示从v到w的弧(路径)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define Status bool
#define OK true
#define ERROR false

#define INFINITY __INT_MAX__    // 使用整型最大值代表正无穷
#define MAX_VERTEX_NUM 26       // 最大顶点树
typedef enum GraphKind{DG,DN,UDG,UDN}GraphKind;  // {有向图，有向网，无向图，无向网}   （网为带权图）
// MGraph
// 数组表示法
// 顶点信息的定义
// VertexType 类型只包含一个成员 即顶点名称
#define MAX_NAME 9      // 顶点名称最大长度+1
typedef struct{
    char name[MAX_NAME];
}VertexType;
void Visit(VertexType ver)  // 与之配套的访问函数
{
    printf("%s ",ver.name);
}
void Input(VertexType *ver) // 与之配套的输入顶点信息的函数
{
    scanf("%s",(*ver).name);
}
void InputFromFile(FILE *f,VertexType *ver)      // 与之配套的从文件输入顶点信息的函数
{
    fscanf(f,"%s",(*ver).name);
}

// 弧相关信息的定义
#define MAX_INFO 20     // 弧相关信息的字符串最大长度+1
typedef char InfoType;  // 弧的相关信息类型

void InputArc(InfoType **arc){
    // 与之配套的输入弧的相关信息的函数
    char s[MAX_INFO];       // 临时存储空间
    int m;      
    printf("请输入该弧的相关信息(<%d个字符)：",MAX_INFO);
    //gets(s);                      // 输入字符串
    fgets(s,MAX_INFO,stdin);
    m = strlen(s);  // 字符串长度
    if(m)   // m非空
    {   // 动态生成相关信息存储空间
        *arc = (char *)malloc((m+1)*sizeof(char));
        strcpy(*arc,s);     // 复制s到arc
    }
}
void InputArcFromFile(FILE *f,InfoType **arc){
    char s[MAX_INFO];   // 临时存储空间
    fgets(s,MAX_INFO,f);    // 从文件读入 可包含空格
    *arc = (char *)malloc((strlen(s)+1)*sizeof(char));
    // 动态生成信息存储空间
    strcpy(*arc,s);
}
void OutputArc(InfoType *arc)   // 与之配套的输入弧的相关信息的函数
{
    printf("%s\n",arc);
}

typedef  int VRType;           // 定义顶点关系类型为整型 与INFINITY一致
// 不考虑节点到自身的弧
typedef struct {    // 弧信息结构
    VRType adj;     // 顶点关系类型 对于无权图用1（是）或0（否）表示是否邻接 对带权图（网）则为权值
    InfoType *info;  // 与弧相关的信息指针 可无
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];     // 邻接矩阵
typedef struct {
    VertexType vexs[MAX_VERTEX_NUM];    // 顶点向量
    AdjMatrix arcs;     // 邻接矩阵
    int vexnum,arcnum;  // 图的当前顶点树和弧数
    GraphKind kind;     // 图的种类标志
}MGraph;

// 17个基本操作：

// 图G存在，u和G中的结点有相同特征 （顶点名称相同）
// 返回u在图中的位置序号 否则返回-1
int LocateVex(MGraph G, VertexType u){
    int i;
    for(i=0;i<G.vexnum;i++){
        // 对于所有顶点依次查找
        if(strcmp(u.name,G.vexs[i].name)==0)
            return i;
    }
    return -1;      // 未找到即不存在与u相同特征的结点
}
// 采用数组即邻接矩阵表示法，构造有向图DG
void CreateDG(MGraph *G){
    int i,j,k,IncInfo;  // IncINfo为0则弧不含信息
    VertexType v1,v2;   // 顶点类型
    printf("请输入有向图G的顶点个数，弧数，弧是否含相关信息(是：1，否：0)：\n");
    scanf("%d %d %d",&((*G).vexnum),&((*G).arcnum),&IncInfo);
    printf("请输入%d个顶点的值(名称<%d个字符)：\n",(*G).vexnum,MAX_NAME);
    for(i=0;i<(*G).vexnum;i++)      // 构造顶点向量
        Input(&(*G).vexs[i]);
    for(i=0;i<(*G).vexnum;i++)  //  初始化邻接矩阵（二维数组
    // 弧信息
        for(j=0;j<(*G).arcnum;j++){
            (*G).arcs[i][j].adj = 0;    // 图，不相邻
            (*G).arcs[i][j].info = NULL;    // 无相关信息
        }    
    printf("请输入%d条弧的弧尾 弧头：\n",G->arcnum);
    for(k=0;k<G->arcnum;k++){
        scanf("%s%s%*c",v1.name,v2.name);
        i = LocateVex(*G,v1);   // 弧尾序号
        j = LocateVex(*G,v2);   // 弧头序号
        G->arcs[i][j].adj = 1;  // 有向图
        if(IncInfo) // 有相关信息
            InputArc(&(G->arcs[i][j].info));
            // 动态生成存储空间 输入弧的相关信息
    }
    (*G).kind = DG;
}
// 采用数组（邻接矩阵）表示法，构造有向网DN
void CreateDN(MGraph *G){
    int i,j,k,IncInfo;      // IncInfo=0 则弧不含信息
    VRType w;       // 顶点关系类型
    VertexType v1,v2;   // 顶点类型
    printf("请输入有向网G的顶点个数，弧数，弧是否含相关信息(是：1，否：0)：\n");
    scanf("%d %d %d",&((*G).vexnum),&((*G).arcnum),&IncInfo);
    printf("请输入%d个顶点的值(名称<%d个字符)：\n",(*G).vexnum,MAX_NAME);
    for(i=0;i<(*G).vexnum;i++)      // 构造顶点向量
        Input(&(*G).vexs[i]);
    for(i=0;i<(*G).vexnum;i++)  //  初始化邻接矩阵（二维数组
        for(j=0;j<(*G).arcnum;k++){
            (*G).arcs[i][j].adj = INFINITY;    // 网，不相邻
            (*G).arcs[i][j].info = NULL;    // 无相关信息
        }    
    printf("请输入%d条弧的弧尾 弧头 权值：\n",G->arcnum);
    for(k=0;k<G->arcnum;k++){
        scanf("%s%s%d%*c",v1.name,v2.name,&w);
        i = LocateVex(*G,v1);       // 弧尾序号
        j = LocateVex(*G,v2);       // 弧头序号
        (*G).arcs[i][j].adj = w;    // 有向网
        if(IncInfo)     // 有相关信息
            InputArc(&((*G).arcs[i][j].info));
    }
    G->kind = DN;
}
// 采用数组（邻接矩阵）表示法 构造无向图UDG
void CreateUDG(MGraph *G){
    int i,j,k,IncInfo;
    VertexType v1,v2;
    printf("请输入无向图G的顶点个数，弧数，弧是否含相关信息(是：1，否：0)：\n");
    scanf("%d %d %d",&((*G).vexnum),&((*G).arcnum),&IncInfo);
    printf("请输入%d个顶点的值(名称<%d个字符)：\n",(*G).vexnum,MAX_NAME);
    for(i=0;i<(*G).vexnum;i++)      // 构造顶点向量
        Input(&(*G).vexs[i]);
    for(i=0;i<(*G).vexnum;i++)  //  初始化邻接矩阵（二维数组
        for(j=0;j<(*G).arcnum;k++){
            (*G).arcs[i][j].adj = INFINITY;    // 图，不相邻
            (*G).arcs[i][j].info = NULL;    // 无相关信息
        }
    printf("请输入%d条边的顶点1 顶点2：\n",G->arcnum);
    for(k=0;k<G->arcnum;k++){
        scanf("%s %s %*c",v1.name,v2.name);
        i = LocateVex(*G,v1);
        j = LocateVex(*G,v2);
        G->arcs[i][j].adj = 1;
        if(IncInfo)
            InputArc(&(G->arcs[i][j].info));
        G->arcs[j][i] = G->arcs[i][j];
    } 
    G->kind = UDG;
}
// 采用数组（邻接矩阵）表示法，构造无向网UDN
void CreateUDN(MGraph *G){
    int i,j,k,IncInfo;      // IncInfo=0 则弧不含信息
    VRType w;       // 顶点关系类型
    VertexType v1,v2;   // 顶点类型
    printf("请输入有向网G的顶点个数，弧数，弧是否含相关信息(是：1，否：0)：\n");
    scanf("%d %d %d",&((*G).vexnum),&((*G).arcnum),&IncInfo);
    printf("请输入%d个顶点的值(名称<%d个字符)：\n",(*G).vexnum,MAX_NAME);
    for(i=0;i<(*G).vexnum;i++)      // 构造顶点向量
        Input(&(*G).vexs[i]);
    for(i=0;i<(*G).vexnum;i++)  //  初始化邻接矩阵（二维数组
        for(j=0;j<(*G).arcnum;k++){
            (*G).arcs[i][j].adj = INFINITY;    // 网，不相邻
            (*G).arcs[i][j].info = NULL;    // 无相关信息
        }    
    printf("请输入%d条边的 顶点1 顶点2 权值：\n",G->arcnum);
    for(k=0;k<G->arcnum;k++){
        scanf("%s%s%d%*c",v1.name,v2.name,&w);
        i = LocateVex(*G,v1);       // 顶点1序号
        j = LocateVex(*G,v2);       // 顶点2序号
        (*G).arcs[i][j].adj = w;    // 网
        if(IncInfo)     // 有相关信息
            InputArc(&((*G).arcs[i][j].info));
        G->arcs[j][i] = G->arcs[i][j];  // 无向网 两个单元信息相同
    }
    G->kind = UDN;
}
// 采用数组 （邻接矩阵）表示法 构造图G
void CreateGraph(MGraph *G){
    printf("请输入图的类型（有向图：0，有向网：1，无向图：2，无向网：3）：\n");
    scanf("%d",&(*G).kind);
    switch(G->kind){
        case DG:
            CreateDG(G);
            break;
        case DN:
            CreateDN(G);
            break;
        case UDG:
            CreateUDG(G);
            break;
        case UDN:
            CreateUDN(G);
            break;
        default:
            printf("请输入合理的数。\n");
            break;
    }
}
// 若图G存在且v是某个顶点序号，则返回v的值
VertexType GetVex(MGraph G,int v){
    assert(!(v>=G.vexnum || v<0));
    return G.vexs[v];
}
// 若图G存在，v是G中的某个顶点，则对v赋新值value
Status PutVex(MGraph *G,VertexType v,VertexType value){
    int k = LocateVex(*G,v);
    if(k<0)     // 不存在
        return ERROR;
    (*G).vexs[k] = value;  // 赋值
    return OK;
}
// 若图存在且v是其中某个顶点序号，则返回v的第一个邻接顶点的序号，若顶点没有邻接顶点则返回-1
int FirstAdjVex(MGraph G, int v){
    int i;
    VRType j = 0;   // 顶点关系类型：图
    if(G.kind%2)    // 网
        j = INFINITY;
    for(i=0;i<G.vexnum;i++) // 从第一个顶点开始查找
        if(G.arcs[v][i].adj != j)
            return i;   // 返回邻接顶点的序号
    return -1;  // 没有邻接顶点
}
// 若图G存在v是G中某个顶点的序号，w是v的邻接顶点的序号，则返回v相对于w的下一个邻接顶点
// 若w是v的最后一个邻接顶点，则返回-1
int NextAdjVex(MGraph G,int v,int w){
    int i;
    VRType j = 0;   // 顶点关系：图
    if(G.kind%2)    // 网
        j = INFINITY;
    for(i=w+1;i<G.vexnum;i++)   // 从w+1个顶点开始查找
        if(G.arcs[v][i].adj != j)   // 是从w+1开始的第一个邻接顶点
            return i;
    return -1;
}
// 若图G存在，v和G中的顶点有相同特征 则在图G中新增顶点V不增添与之相关的弧
Status InsertVex(MGraph *G,VertexType v){
    int i;
    VRType j = 0;   // 顶点关系类型：图
    if(G->kind%2)   // 网
        j = INFINITY;
    G->vexs[G->vexnum] = v;
    for(i=0;i<=G->vexnum;i++)   // 对于新增行、列
    {
        G->arcs[G->vexnum][i].adj = G->arcs[i][G->vexnum].adj = j;
        // 初始化新增行、列 邻接矩阵的值（无弧）
        G->arcs[G->vexnum][i].info = G->arcs[i][G->vexnum].info = NULL;  // 初始化相关信息指针
    }
    G->vexnum++;
}

Status InsertArc(MGraph *G,VertexType v, VertexType w){
    int i,v1,w1;
    v1 = LocateVex(*G,v);   // 弧尾顶点v的序号
    w1 = LocateVex(*G,w);   // 弧头顶点w的序号
    if(v1<0 || w1<0)    // 不存在v或w
        return ERROR;
    G->arcnum++;
    if(G->kind%2){  // 网
        printf("请输入此弧的权值：");
        scanf("%d",&(G->arcs[v1][w1].adj));
    }else   // 图
        G->arcs[v1][w1].adj = 1;
    printf("是否有该弧的相关信息（0：无，1：有）：");
    scanf("%d%*c",&i);
    if(i)
        InputArc(&(G->arcs[v1][w1].info));
    if(G->kind>1)   // 无向
        G->arcs[w1][v1] = G->arcs[v1][w1];
    return OK;
}
// 若图G存在，v和w是G中的两个顶点 则 删除弧<v，w> 若图无向则同时删除对称弧<w,v>
Status DeleteArc(MGraph *G,VertexType v,VertexType w){
    int v1,w1;
    VRType j = 0;       // 顶点关系类型：图
    if(G->kind%2)       // 网
        j = INFINITY;
    v1 = LocateVex(*G,v);   // 弧尾顶点v的序号
    w1 = LocateVex(*G,w);   // 弧头顶点w的序号
    if(v1<0 || w1 <0)   // 不存在v或w
        return ERROR;
    if(G->arcs[v1][w1].adj != j)    // 有弧<v,w>
    {
        G->arcs[v1][w1].adj = j;    // 删除操作
        if(G->arcs[v1][w1].info)    // 有相关信息
        {
            free(G->arcs[v1][w1].info); // 释放相关信息
            G->arcs[v1][w1].info = NULL;    // 置相关信息指针为空
        }
        if(G->kind>=2)  // 无向，删除对称弧
            G->arcs[w1][v1] = G->arcs[v1][w1];
        G->arcnum --;   // 总弧数-1
    }
    return OK;
}
// 若图G存在，v是G中某个顶点 则删除G中顶点V以及与其相关的弧
Status DeleteVex(MGraph *G,VertexType v){
    int i,j,k;
    k = LocateVex(*G,v);    // k为待删除顶点v的序号
    if(k<0)     // v不是G的顶点
        return ERROR;
    for(i=0;i<G->vexnum;i++)
        DeleteArc(G,v,G->vexs[i]);  // 删除由顶点v出发的所有弧
    if(G->kind<2)   // 有向
        for(i=0;i<G->vexnum;i++)
            DeleteArc(G,G->vexs[i],v);  // 删除由所有顶点发向v的弧
    for(j = k+1;j<G->vexnum;j++)    // 序号k后面的顶点依次向前移
        G->vexs[j-1] = G->vexs[j];
    for(i=0;i<G->vexnum;i++)
        for(j=k+1;j<G->vexnum;j++)
            G->arcs[i][j-1] = G->arcs[i][j];    // 移动待删除顶点之右的矩阵元素
    for(i=0;i<G->vexnum;i++)
        for(j=k+1;j<G->vexnum;j++)
            G->arcs[j-1][i] = G->arcs[j][i];    // 移动待删除顶点之下的矩阵元素
    G->vexnum --;   // 更新顶点数
    return OK;
}
// 若图G存在 则销毁图G
void DestroyGraph(MGraph *G){
    int i;
    for(i = G->vexnum-1;i>=0;i--)   // 由大到小逐一删除顶点与其相关的弧
        DeleteVex(G,G->vexs[i]);
}
// 输出邻接矩阵存储结构的图G
void Display(MGraph G){
    int i,j;
    char s[10] = "无向网",s1[4] = "边";
    switch(G.kind){
        case DG:
            strcpy(s,"有向图");
            strcpy(s1,"弧");
            break;
        case DN:
            strcpy(s,"有向网");
            strcpy(s1,"弧");
            break;
        case UDG:
            strcpy(s,"无向图");
            break;
        case UDN:
            break;
        default:
            printf("图类型错误！");
    }
    printf("%d个顶点%d条%s的%s。顶点依次是：",G.vexnum,G.arcnum,s1,s);
    for(i=0;i<G.vexnum;i++)
        Visit(GetVex(G,i)); // 根据顶点信息的类型，访问第i个顶点
    printf("\nG.arcs.adj:\n");
    char wuqiong[] = "∞";
    for(i=0;i<G.vexnum;i++){    // 输出二维数组
        for(j=0;j<G.vexnum;j++)
            if(G.arcs[i][j].adj == INFINITY)
                printf("%6s",wuqiong);
            else
                printf("%4d",G.arcs[i][j].adj);
        printf("\n");
    }
    printf("G.arcs.info:\n");
    if(G.kind<2)
        printf("弧尾 弧头 该%s的信息：\n",s1);
    else
        printf("顶点1 顶点2 该%s的信息：\n",s1);
    for(i=0;i<G.vexnum;i++)
        if(G.kind<2)    // 有向
        {
            for(j=0;j<G.vexnum;j++)
                if(G.arcs[i][j].info){
                    printf("%5s %5s",G.vexs[i].name,G.vexs[j].name);
                    OutputArc(G.arcs[i][j].info);   // 输出弧的相关信息
                }
        }   // 加括号为避免if-else对配错
        else    // 无向 输出上三角
            for(j=j+1;j<G.vexnum;j++)
                if(G.arcs[i][j].info){
                    printf("%5s %5s",G.vexs[i].name,G.vexs[j].name);
                    OutputArc(G.arcs[i][j].info);   // 输出弧信息
                }
}
// 采用数组表示法 从文件构造图或网
void CreateFromFile(MGraph *G,char *filename,int IncInfo){
    int i,j,k;
    VRType w=0;         // 顶点关系类型：图
    VertexType v1,v2;   // 顶点类型
    FILE *f;    // 文件指针
    f = fopen(filename,"r");
    fscanf(f,"%d",&(*G).kind);      // 由文件输入G的类型
    if((*G).kind%2)    // 网
        w = INFINITY;
    fscanf(f,"%d",&(*G).vexnum);    // 由文件输入G的节点数
    for(i=0;i<G->vexnum;i++)
        InputFromFile(f,&(G->vexs[i]));// 由文件输入顶点信息
    fscanf(f,"%d",&(*G).arcnum);    // 由文件输入G的弧数
    for(i=0;i<G->vexnum;i++)    // 初始化邻接矩阵
        for(j=0;j<G->vexnum;j++){
            G->arcs[i][j].adj = w;  // 不相邻
            G->arcs[i][j].info = NULL;  // 无信息
        }
    if(!(G->kind%2))    // 图
        w = 1;
    for(k=0;k<G->arcnum;k++)    // 对于所有弧
    {
        fscanf(f,"%s %s",v1.name,v2.name);  // 由文件输入弧尾、弧头的名称
        if(G->kind%2)   // 网
            fscanf(f,"%d",&w);  // 再输入权值
        i = LocateVex(*G,v1);   // 弧尾序号
        j = LocateVex(*G,v2);   // 弧头序号
        G->arcs[i][j].adj = w;  // 权值
        if(IncInfo) // 有相关信息
            InputArcFromFile(f,&(G->arcs[i][j].info));
        if(G->kind>1)   // 无向
            G->arcs[j][i] = G->arcs[i][j];
    }
    fclose(f);  // 关
}

