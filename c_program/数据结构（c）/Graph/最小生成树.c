#include "./最小生成树.h"

int main(){
    MGraph g;
    char filename[20] = "1.txt";
    CreateFromFile(&g,filename,0);
    Display(g);
    // 普利姆算法
    //MinSpanTree_PRIM(g,g.vexs[0]);
    // 克鲁斯卡尔算法
    Kruskal(g);
}