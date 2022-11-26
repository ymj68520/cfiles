#include "最短路径.h"

int main(){
    int i,j;
    MGraph g;
    PathMatrix p;
    ShortPathTable d;
    bool *path;
    int k=0;
    CreateFromFile(&g,"最短路径.txt",0);
    Display(g);
    path = (bool*)malloc(sizeof(bool)*g.vexnum);
    ShortPath_DIJ(g,k,p,d);
    // 以g中序号为k的顶点为源点，求其到其余各顶点的最短距离，存于d中
    printf("最短路径数组p[i][j]: \n");
    for(i=0;i<g.vexnum;i++){
        if(i!=k&&d[i]<INFINITY){
            printf("%s -> %s : %d: ",g.vexs[k].name,g.vexs[i].name,d[i]);
            printf("%s -> ",g.vexs[k].name);
            for(j=0;j<g.vexnum;j++)
                path[j] = p[i][j];
            MakePath(g,path,k,i);
        }
    }
}