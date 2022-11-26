#include <stdlib.h>
#include <queue>
#include <stdio.h>
typedef char TreeType;

typedef struct TreeNode{
    TreeType data;
    TreeNode *lchild,*rchild;
}*Tree;
typedef Tree QElemType;
#include "./数据结构（c）/queue/queue.h"
int z=0;
void CreateTree(Tree *T, char *source,int N){
    if(z == N)
        return;
    *T = (Tree )malloc(sizeof(TreeNode));
    if(source[z]=='#'){
        z++;
        return;
    }
    (*T)->data = source[z++];
    CreateTree(&(*T)->lchild,source,N);
    CreateTree(&(*T)->rchild,source,N);
}

void CreateTree_q(Tree *T, char *source,int N){
    int x = 1;
    Tree t1,t2;
    std::queue<Tree> q;
    *T = (Tree)malloc(sizeof(TreeNode));
    (*T)->data = source[0];
    q.push(*T);
    while(!q.empty()){
        if(x==N)
            break;
        t1 = q.front();
        q.pop();
        if(source[x]=='#')
            x++;
        else{
        t2 = t1->lchild = (Tree)malloc(sizeof(TreeNode));
        t2->data = source[x++];
        q.push(t2);
        }
        if(source[x]=='#')
            x++;
        else{
            t2 = t1->rchild = (Tree)malloc(sizeof(TreeNode));
            t2->data = source[x++];
            q.push(t2);
        }
    }
    return;
}

void PrePrint(Tree T){
    if(!T)
        return;
    printf("%c",T->data);
    PrePrint(T->lchild);
    PrePrint(T->rchild);
}
int main(){
    FILE *fp;
    fp=fopen("1.txt","r");
    int N;
    fscanf(fp,"%d%*c",&N);
    char source[N];
    int i=0;
    
    for(i=0;i<N;i++)
        fscanf(fp,"%c%*c",source+i);
    for(int j=0;j<N;++j)
        printf("%c",source[j]);
    putchar('\n');
    Tree T;
    CreateTree_q(&T,source,N);
    PrePrint(T);
    return 0;
}