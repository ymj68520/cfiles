#include "HuffmanTree.h"

int main(){
    HuffmanTree HT;
    HuffmanCode HC;
    int *w,n,i;
    printf("请输入权值的个数(>1)：");
    scanf("%d%*c",&n);
    w = (int *)malloc(n*sizeof(int));
    printf("请依次输入%d个权值(整型)：\n",n);
    for(i=0;i<n;i++)
        scanf("%d",w+i);
    HuffmanCoding(&HT,&HC,w,n);
    for(i=1;i<=n;i++)
        puts(HC[i]);
    return 0;
}