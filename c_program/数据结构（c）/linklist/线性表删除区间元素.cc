#include <stdio.h>

#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
List Delete( List L, ElementType minD, ElementType maxD );

int main()
{
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete( L, minD, maxD );
    PrintList( L );

    return 0;
}
/*
List Delete( List L, ElementType minD, ElementType maxD ){
    if(L->Last){
        for(int i=L->Last;L->Data[i]>minD && L->Data[i]<minD; i--)  // 找到尾部第一个有效位
            if(L->Last)
                L->Last--;
            else
                break;
        // Last 指向尾部第一个有效位
        for(int i=L->Last-1;i>=0;--i){
            if(L->Data[i]>minD&&L->Data[i]<maxD){    // 符合条件
                for(int j=i+1;j<L->Last;j++)
                    L->Data[j-1] = L->Data[j];  // 移动后面的元素
            L->Last--;
            }
        }
    }
    return L;
}*/
List Delete( List L, ElementType minD, ElementType maxD ){
    if(L->Last){
        for(int i=0;i!=L->Last;++i){
            if(L->Data[i]>minD&&L->Data[i]<maxD){
                for(int j=i+1;j<L->Last;j++)
                    L->Data[j-1] = L->Data[j];  // 移动后面的元素
            L->Last--;
            }
        }
    }
    return L;
}