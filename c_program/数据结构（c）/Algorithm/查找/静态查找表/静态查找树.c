#include "静态树表的查找.h"

int main(){
    SSTable st;
    SOSTree t;
    Status i;
    KeyType s;
    Creat_OrdFromFile(&st,"静态查找树.txt");
    // 由数据文件产生非降序静态查找表st
    printf("       ");
    Traverse(st,Visit_t); // 顺序输出非降序静态查找表st
    CreateSOSTree(&t,st);   // 由有序表st构造次优查找树t
    printf("\n请输入要查找的字符：");
    InputKey(&s);   // 由键盘输入关键字s
    i = Search_SOSTree(&t,s);   // 在次优查找树t中查找主关键词等于s的元素
    if(i)   // 找到，返回OK
        printf("%c的权值是%d\n",s,t->data.weight);
    else
        printf("表中不存在此字符\n");
    DestroyBiTree(&t);  // 查找完成，销毁查找树t
    return 0;
}