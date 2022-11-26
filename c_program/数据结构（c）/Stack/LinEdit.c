#include <stdio.h>
#include "stack.h"
//行编辑程序
void visit();
int main (){
    struct SqStack S;
    InitStack(&S);
    char ch = getchar();
    int chi;
    while (ch!=EOF){
        while (ch!=EOF && ch!='\n'){
            switch (ch){
                case '#' :
                    Pop(&S,&chi);
                    break;
                case '@' :
                    ClearStack(&S);
                    break;
                default :
                    Push(&S,ch);
                    break;
            }//switch
            ch = getchar();
        }//while
        StackTraverse(S,visit);
        ClearStack(&S);
        if(ch!=EOF) ch = getchar();

    }//while
    DestroyStack(&S);

    return 0;
}//LinEdit_main