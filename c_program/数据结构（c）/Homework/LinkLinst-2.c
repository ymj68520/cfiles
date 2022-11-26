#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SQLIST_SIZE 50
#define INCREASE_SIZR 10

typedef int ELemType;

int main(){
    ELemType **sqlist = (ELemType **)malloc(MAX_SQLIST_SIZE*sizeof(ELemType *));
    for(int i=0;i<MAX_SQLIST_SIZE;++i){
        sqlist[i] = (ELemType *)malloc(2*sizeof(ELemType));
        sqlist[i][0] = sqlist[i][1] = -1;
    }
    sqlist[0][0] = MAX_SQLIST_SIZE;
    FILE *fp = fopen("LinkList-1","r");
    ELemType e;
    sqlist[0][1] = 1;   // 初始化表头
    for(int i=1;~fscanf(fp,"%d%*c",&e);++i){
        if(i>=sqlist[0][0]){
            sqlist = (ELemType **)malloc((sqlist[0][0]+INCREASE_SIZR)*sizeof(ELemType*));
            for(int j=sqlist[0][0];j<sqlist[0][0]+INCREASE_SIZR;++j){
                sqlist[i] = (ELemType *)malloc(2*sizeof(ELemType));
                sqlist[i][0] = sqlist[i][1] = -1;
            }
        }
        sqlist[i][0] = e;
        sqlist[i][1] = i+1;
    }// 生成表
    int pos,k;
    puts("请输入从第几个元素开始删除：");
    scanf("%d",&pos);
    puts("请输入删除几个元素");
    scanf("%d",&k);
    int count=0;
    for(int i=0;sqlist[i][0]!=-1;++i)   // 求长度，这样只是为了简单，没按表来查
        count++;
    if(pos+k>count){
        puts("ERROR!");
        assert(0);
    }
    for(int i = pos-1;i<k;++i)
        sqlist[i][0] = sqlist[i][1] = -1;
    if(pos+k < count)
        sqlist[pos-1][1] = pos+k;
    for(int i=sqlist[0][1];sqlist[i][0]!=-1;i = sqlist[i][1]){
        printf("%d ",sqlist[i][0]);
    }
    return 0;
}