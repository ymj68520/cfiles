/*
关于关键路径：
事件的最早发生时间ve：因为对于某一个事件（顶点）来说，其入度可能大于1，
                    所以从源点到达该顶点的路就不止一条。
                    对于其中一条路来说，经过的所有边的权值的和就是对这条路来说，到达
                    该顶点需要的时间。把到达该顶点所有路的时间进行比较，取最大值，
                    就是该事件的最早发生时间。
事件的最迟发生时间vl：值在不耽误整个工程完成时间的前提下，某一事件最晚的发生时间。
    例：有三个事件a，b，c，a和b是c的前驱事件。
        完成活动ac需要的时间是2小时，完成活动bc需要的时间是3小时。
        假设现在时间是下午1点，此时事件a和事件b都已经发生，
        根据前面的描述可知，活动ac和bc都可以开始了。
        但是因为bc需要完成的时间长，所以事件c发生的时间是下午4点。
        那么因为ac只需两个小时就可以完成，那么事件a发生的时间可以是下午2点，
        再加上ac完成时间2个小时也是下午4点，并没有耽误到事件c的发生，这就是所谓的最晚发生时间。
        所以事件a的最早发生时间是下午1点，最晚发生时间是下午2两点。
活动开始的最早时间ee：因为事件发生的同时与该事件关联的活动也就可以开始。
                   所以一个活动（边）的最早开始时间和其起点所代表的事件的最早开始时间相同。
活动开始的最晚时间el：事件的最晚发生时间是将事件推迟，活动的最晚开始时间是将活动推迟，二者类似。
关键活动：ee = el。
关键路径：所有关键活动组成的路径。
*/
#include "ALGraph.h"
#include "FindInDegree.c"

typedef int SElemType;  // 定义栈元素类型为整型（存储顶点序号）
#include "../Stack/stack.h"

int ve[MAX_VERTEX_NUM]; // 全局变量辅助数组，事件（顶点）最早发生时间

// 有向网G采用邻接表存储结构，求各顶点事件的最早发生时间ve(全局变量)。
// T为拓扑序列顶点栈，S为零入度顶点栈。若G无回路，则用T返回G的一个拓扑序列，
// 且函数值为OK，否则为ERROR
Status TopologicalOrder(ALGraph G,SqStack *T){
    int i,k,count=0; // 已入栈顶点数，初始为0；
    int indegree[MAX_VERTEX_NUM];   // 入度数组
    SqStack S;
    ArcNode *p;
    FindInDegree(G,indegree);   // 求入度
    InitStack(&S);
    for(i=0;i<G.vexnum;i++) // 初始化ve[]
        ve[i] = 0;
    while(!StackEmpty(S))   // 当零入度顶点栈非空
    {   Pop(&S,&i); // 从栈S将已经拓扑排序的顶点弹出，并赋值给i；
        Visit(G.vertices[i].data);  // 输出顶点的名称
        Push(T,i); // j号顶点入逆拓扑排序栈T（栈底元素为拓扑排序第一个元素）
        count++;    // 对入栈元素进行计数
        for(p=G.vertices[i].firstarc;p;p=p->nextarc){
            k = p->data.adjvex;
            if(--indegree[k]==0)
                Push(&S,k);
            if(ve[i] + p->data.info->weight > ve[k])
            // 顶点i事件的最早发生时间 + <i,k>的权值 > 顶点k事件的最早发生时间
                ve[k] = ve[i] + p->data.info->weight;
                // 顶点k时间的最早发生时间 = 顶点i时间的最早发生时间 + <i,k>的权值
                // 由于i已拓扑排序，故ve[i]不再改变
        }
    }
    if(count < G.vexnum){
        puts("此有向图有回路");
        return ERROR;
    }
    else
        return OK;
}
// 输出ve vl ee el的函数
void Visitel(int i){
    printf("%3d",i);
}

// G为有向网，输出G的各项关键活动
Status CriticalPath(ALGraph G){
    SqStack T;  // 逆拓扑排序栈
    int i,j,k;
    ArcNode *p;
    int ee[MAX_VERTEX_NUM]; // 辅助数组，活动（弧）最早开始时间
    int el[MAX_VERTEX_NUM]; // 辅助数组，活动（弧）最晚开始时间
    int vl[MAX_VERTEX_NUM]; // 辅助数组，事件（顶点）最晚开始时间
    if(!TopologicalOrder(G,&T))  // 产生回路
        return ERROR;
    j = ve[0];  // j的初始值
    for(i=0;i<G.vexnum;i++) // 在所有顶点中找ve的最大值
        if(ve[i]>j)
            j = ve[i];  // j = Max(ve[])完成点的最早发生时间
    for(i=0;i<G.vexnum;i++) // 初始化顶点事件的最迟发生时间
        vl[i] = j;  // 为完成点的最早发生时间（最大值）
    /*
        对于寻找最大值时不是直接取最后一个值的解释：
            拓扑序列是一个以偏序关系列出来的全序关系，
            且偏序关系允许存在多个最大值。
            因此，处于拓扑序列的最后一个并不一定是偏序关系的最大项
            有可能拓扑序列中有许多最大值
            在并不确定知道最大值的个数的情况下，直接遍历一遍效率最高。
    */
    while(!StackEmpty(T))   // 按拓扑排序的逆序求各顶点的vl(事件最迟发生时间)值 
        for(Pop(&T,&j),p = G.vertices[j].firstarc;p;p = p->nextarc)
        {   // 弹出栈T的元素，赋值给j，p指向j的后继事件（出弧）顶点k
            // 事件k的最迟发生时间已经确定（因为是逆拓扑序列）
            k = p->data.adjvex; // 后继事件的序号
            if(vl[k] - p->data.info->weight < vl[j])
                // 事件j的最迟发生时间 > 其后继事件k的最迟发生时间 - <j,k>的权值
                vl[j] = vl[k] - p->data.info->weight;
                // 事件j的最迟发生时间 = 事件k的最迟发生时间 - <j,k>的权值
        }// 由于k已逆拓扑有序，故vl[k]不再改变
    printf("\ni ve vl\n");
    for(i=0;i<G.vexnum;i++) // 对于每个顶点
    {
        printf("%d",i); // 输出序号
        Visitel(ve[i]); // 输出ve
        Visitel(vl[i]);
        if(ve[i] == vl[i])  // 事件（顶点）的最早发生时间 = 最迟发生时间
            printf("关键路径经过的顶点");
        printf("\n");
    }
    // 以下求ee el 和 关键活动
    printf("j k 权值 ee el\n");
    for(j=0;j<G.vexnum;j++)
        for(p=G.vertices[j].firstarc;p;p=p->nextarc){
            k = p->data.adjvex;
            ee[p->data.adjvex] = ve[j];
            // ee(活动<j,k>的最早开始时间) = (顶点j)事件最早发生时间
            el[p->data.adjvex] = vl[k] - p->data.info->weight;
            // el(活动<j,k>最晚开始时间) = (顶点k)事件最迟发生时间 - <j,k>的权值
            printf("%s -> %s",G.vertices[j].data.name,G.vertices[k].data.name); // 输出弧
            OutputArc(p->data.info); // 输出弧的权值
            Visitel(ee[p->data.adjvex]);    // 输出ee[]值
            Visitel(el[p->data.adjvex]);
            if(ee[p->data.adjvex] == el[p->data.adjvex])
            // 活动（顶点）的最早开始时间 = 活动（顶点）的最晚开始时间
                printf("关键活动");
            printf("\n");
        }
    return OK;
}