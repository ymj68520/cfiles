/*
拓扑排序是一个比较神奇的东西。
下面给出它的定义：
    在集合论中它的定义是：构造一个包含某个给定偏序的全序的过程称为拓扑排序。
    在图论中的定义是：对于一个有向无环图G = （V，E），对于某条边（u，v）属于G ，
        则结点u在拓扑排序中处于结点v的前面。
个人理解：
    拓扑排序的意义就在于在一个有向图中，找出一个顺序，可以在有向图中，依次遍历各个点。

实现拓扑排序的步骤如下：
    步骤1：找到AOE网络中入度为0的顶点，输出它。如果找不到，停止排序。
    步骤2：删除所有与该点关联的边，重复步骤1。
    步骤3：如果输出顶点个数小于总顶点个数，则证明图中存在环，没有关键路径
拓扑排序的结果叫做拓扑序列，一个AOE网络的拓扑序列不止一种
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "FindInDegree.c"

typedef int SElemType;  // 定义栈元素类型为整型（存储顶点序号）
#include "../Stack/stack.h"

Status TopologicalSort(ALGraph G){
    // 有向图G采用邻接表存储结构。若G无回路，则输出G的顶点的一个拓扑序列并返回OK
    // 否则返回ERROR
    int i,k,count=0;    // 已输出顶点数，初值为0
    int indgree[MAX_VERTEX_NUM];    // 入度数组，存放各顶点当前入度
    SqStack S;
    ArcNode *p;
    FindInDegree(G,indgree);    // 对G的各顶点求入度
    InitStack(&S);  // 舒适化入度为0的栈集合
    for(i=0;i<G.vexnum;i++)
        if(!indgree[i]) // 入度为0
            Push(&S,i); // 将i入零入度顶点栈
    while(!StackEmpty(S))   // 当零入度顶点栈不空
    {   Pop(&S,&i);  // 出栈一个零入度顶点.将其序号赋值给i
        printf("%s ",G.vertices[i].data.name);   // 输出顶点
        count++;    // 已输出顶点数+1
        for(p=G.vertices[i].firstarc;p;p=p->nextarc)    // 对i号顶点的每个邻接顶点
        {   k = p->data.adjvex; // 其序号为k
            if(!(--indgree[k])) // k的入度-1，若减为0，则将k入栈S
                Push(&S,k);
        }
    }
    if(count<G.vexnum)  // 零入度顶点栈以空，G中还有顶点未输出
    {
        printf("此有向图有回路\n");
        return ERROR;
    }
    else{
        printf("为一个拓扑序列。\n");
        return OK;
    }
}
