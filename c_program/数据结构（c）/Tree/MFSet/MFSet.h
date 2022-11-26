// 若S是MFSet型的集合，则它由n（n>0）个子集S_i组成，每个子集的成员都是
// 子界[-maxnumber,maxnumber]内的整数
#include <stdio.h>
#include <stdlib.h>

#include "../CSTree/CSTree.h"
typedef PTree MFSet;   // 二叉树的双亲表示法

// 查找函数
// S是已知的存在集合，x是S中某个子集的成员
// 确定S中x所属的子集S_i
int find_mfset(MFSet S,int i){
    // 找集合S中i所在子集的根
    if(i<1 || i>S.n)
        return -1;      // i不属于任一子集
    int j;
    for(j=i;S.nodes[j].parent>0;j=S.nodes[j].parent);
    return j;
}
// S.nodes[i]与S.nodes[j]分别为互不相交的两个子集S_i S_j的根节点
// 求并集
Status merge_mfset(MFSet *S,int i,int j){
    if(i<1 || i>(*S).n || j<1 || j>(*S).n)
        return ERROR;
    (*S).nodes[i].parent = j;
    return OK;
}

Status mix_mfset(MFSet *S,int i,int j){
    if(i<1 || i>(*S).n || j<1 || j>(*S).n)
        return ERROR;
    if((*S).nodes[i].parent>(*S).nodes[j].parent){
        // S_i比S_j所含成员少
        (*S).nodes[j].parent+=(*S).nodes[i].parent;
        (*S).nodes[i].parent = j;
    }else{
        (*S).nodes[i].parent+=(*S).nodes[j].parent;
        (*S).nodes[j].parent = i;
    }
    return OK;
}