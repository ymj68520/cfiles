// 求顶点的入度
void FindInDegree(ALGraph G,int *indgree){
    int i;
    ArcNode *p;
    for(i=0;i<G.vexnum;i++){
        // 对于所有顶点
        indgree[i] = 0; // 初始化所有入度
    }
    for(i=0;i<G.vexnum;i++){    // 对于所有顶点
        p = G.vertices[i].firstarc; // 将p指向顶点的邻接表的头指针
        while(p)    // 未到邻接表尾
        {   indgree[p->data.adjvex]++;  // 将p所指邻接顶点的入度+1
            p = p->nextarc;     // p指向下一个邻接顶点
        }
    }
}
