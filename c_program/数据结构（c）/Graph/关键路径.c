#include "关键路径.h"

int main (){
    ALGraph h;
    printf("请选择有向网\n");
    CreateGraph(&h);
    Display(h);
    CriticalPath(h);
    return 0;
}
/*
1
6 8
v1 v2 v3 v4 v5 v6
v1 v2 3
v1 v3 2
v2 v4 2
v2 v5 3
v3 v4 4
v3 v6 3
v4 v6 2
v5 v6 1
*/