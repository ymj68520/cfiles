#include "TopologicalSort.h"

void main(){
    ALGraph f;
    printf("请选择有向图\n");
    CreateGraph(&f);
    Display(f);
    TopologicalSort(f);
    return;
}