#include "./关节点和重连通分量.h"

int main(){
    int i;
    ALGraph g;
    char filename[13];
    printf("请输入数据文件名：");
    scanf("%s",filename);
    CreateFromFile(&g,filename);
    Display(g);
    printf("输出关节点：\n");
    FindArticul(g);
    printf("i G.vertices[i].data visited[i] lowOrder[i]\n");
    for(i=0;i<g.vexnum;++i)
        printf("%2d %9s %14d %8d %8d\n",i,g.vertices[i].data.name,
        visited[i],low[i],lowOrder[i]);
}