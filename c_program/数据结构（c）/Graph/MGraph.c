#include "Graph.h"

int main(){
    int i,j,k,n;
    char s[4] = "边";
    MGraph g;
    VertexType v1,v2;
    printf("请一次选择有向图，有向网，无向图，无向网；\n");
    for(i=0;i<4;i++){
        CreateGraph(&g);
        Display(g);
        printf("插入新顶点，请输入顶点的值：");
        Input(&v1);
        InsertVex(&g,v1);
        if(g.kind<2)    // 有向
        {
            strcpy(s,"弧");
        }
        printf("插入与新顶点有关的%s，请输入%s数：",s,s);
        scanf("%d",&n);
        for(k=0;k<n;k++)       // 依次插入n条弧
        {
            printf("请输入另一顶点的名称：");
            scanf("%s",v2.name);
            if(g.kind<=1)   // 有向
            {
                printf("请输入另一顶点的方向（0：弧头，1：弧尾）：");
                scanf("%d",&j);
                if(j)   // v2是弧尾
                    InsertArc(&g,v2,v1);    // 在图中插入弧v2->v1
                else
                    InsertArc(&g,v1,v2);    // v1->v2
                
            }
            Display(g);
            printf("删除顶点以及与其相关的%s，请输入待删除顶点的名称：",s);
            scanf("%s",v1.name);
            DeleteVex(&g,v1);
            Display(g);
            if(i==3)    // 对于最后一个无向网   测试以下函数
            {
                printf("修改顶点的值，请输入待修改顶点的名称：");
                Input(&v2);
                PutVex(&g,v1,v2);
                if(g.kind<2)    // 有向 假设最后一个可以不是无向网
                    printf("删除一条%s，请输入待删除%s的弧头 弧尾：",s,s);
                else
                    printf("删除一掉%s，请输入待删除%s的顶点1、顶点2：",s,s);
                scanf("%s %s",v1.name,v2.name);
                DeleteArc(&g,v1,v2);
                Display(g);
            }
            DestroyGraph(&g);
        }
    }
}