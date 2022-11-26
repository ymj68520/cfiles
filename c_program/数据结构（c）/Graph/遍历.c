#include "./图的遍历.h"

int main(){
    Graph g;
    char filename[13];
    scanf("%s",filename);
    CreateFromFile(&g,filename,0);
    printf("深度优先遍历的结果：\n");
    DFSTraverse(g,Visit);
    puts("广度优先遍历的结果：");
    BFSTraverse(g,Visit);
    return 0;
}