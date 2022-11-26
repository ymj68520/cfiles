// 在m*n矩阵中有t个不为0的元素. Δ=(t)/(m*n)[稀疏因子]. Δ < 0.5 时称为稀疏矩阵
// 顺序三元组(i,j,aij)确定一个矩阵
// 未测试
#include <stdio.h>
#include <stdbool.h>

#define Status bool
#define ERROR false
#define OK true

typedef int ElemType;
#define MAX_SIZE 100

typedef struct triple{
    int i,j;    // 行列
    ElemType e; // 元素值
}Triple;

typedef struct tsmatrix{
    Triple data[MAX_SIZE+1];
    int mu,nu,tu;           // 行、列、元素数
}TSMatrix;

//比较整数c1和c2的大小，分别返回-1,0,1
int comp(int c1, int c2){   
    if(c1<c2)
        return -1;
    else if(c1==c2)
        return 0;
    else    //c1 > c2
        return 1;
}

// 关于稀疏矩阵的操作，4个

//创建稀疏矩阵
Status CreateSMatrix(TSMatrix *M){
    int i;
    Triple T;
    Status k;
    printf("请输入矩阵的行数、列数、非零元数：");
    scanf("%d,%d,%d",&(M->mu),&(M->nu),&(M->tu));
    if((M->tu)>MAX_SIZE)
        return ERROR;       // 元素太多
    M->data[0].j = 0;       // 为以下比较顺序做准备
    for(i=0; i<M->tu;i++){  // 依次输入tu个非零元
        do{
            printf("请按行序输入第 %d 个非零元所在的行(1~ %d), 列(1~ %d),元素值：",
                i,M->mu,M->nu);
            scanf("%d %d %d",&(T.i),&(T.j),&(T.e));
            k = 0;          // 输入值的范围正确的标志
            if(T.i<1 || T.i>M->mu || T.j<1 || T.j>M->nu)    // 行列超过范围
                k=1;
            if(T.i<M->data[i-1].i || T.i==M->data[i-1].i && T.j<=M->data[i-1].j)
                k=1;        // 行列的顺序有错
        }while(k);          // 输入错误继续输入
        M->data[i] = T;     // 将正确的输入值赋给三元组结构M的相应单元
    }
    return OK;
}
// 求稀疏矩阵的和 Q = M + N;
Status AddSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q){
    int m=1, n=1, q=0;
    if(M.mu!=N.mu || M.nu != N.nu)
        return ERROR;               // 两个矩阵的维数不等
    Q->mu = M.mu;
    Q->nu = M.nu;                   // 设置和矩阵的行列数
    while(m<=M.tu && n<=N.tu)       // 两个矩阵都没有处理完
        switch(comp(M.data[m].i,N.data[n].i))   // 比较两个当前元素的行数
            {
            case -1:    // M的行数小，将M的值赋给Q
                Q->data[++q] = M.data[m++];
                break;
            case 0:
                switch(comp(M.data->j,N.data->i)) // 行数相同比较列数
                {
                    case -1:                            // 矩阵M的列值小，将M的值赋给Q
                        Q->data[++q] = M.data[m++];     
                        break;
                    case 0:                             // M、N当前元素的行列相等，将
                        Q->data[++q] = M.data[m++];       // 两元素求和并赋值给矩阵Q
                        Q->data[q].e+= N.data[n++].e;
                        if(Q->data[q].e == 0)             // 两元素之和为0，不存入Q
                            q--;
                        break;
                    case 1:                            // 矩阵N的列值小，将N的值存入Q
                        Q->data[++q] = N.data[n++];
                }
                break;                
            case 1:     // 矩阵N的行值小，将N的当前元素值赋给矩阵Q
                Q->data[++q] = N.data[n++];
            }
    // 以下循环最多执行一个
    while(m<=M.tu)  // 矩阵N的元素已经全部处理完，处理剩余M
        Q->data[++q] = M.data[m++];
    while(n<=N.tu)  // 矩阵M的元素已经全部处理完，处理剩余N
        Q->data[++q] = N.data[n++];
    if(q>MAX_SIZE)  // 非零元素太多
        return ERROR;
    Q->tu = q;      // 矩阵Q的非零元素个数
    return OK;
}
// 求稀疏矩阵M的转置T
void TransposeSMatrix(TSMatrix M, TSMatrix *T){
    int p,col,q=1;      // q 指示转置矩阵当前元素，初值为1
    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;
    if(T->tu)           // 非空
        for(col=1; col<=M.nu; col++)    // 从矩阵T的第一行到最后一行
            for(p=1; p<=M.tu; p++)      // 对于矩阵M的所有元素
                if(M.data[p].j == col)  // 该元素的列数等于当前矩阵T的行数
                {
                    T->data[q].i = M.data[p].j;  // 将矩阵M的值行列对调赋给T的当前元素
                    T->data[q].j = M.data[p].i;
                    T->data[q++].e = M.data[p].e;// 转置矩阵T的当前元素指针+1； 
                }

}
// 求稀疏矩阵的乘积 Q = M * N
Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q){
    int i,j,p,q;
    ElemType Qs;        // 矩阵元素临时存放处
    TSMatrix T;         // N的转置矩阵
    if(M.nu != N.mu)    // 维度不匹配，无法相乘
        return ERROR;
    Q->mu = M.mu;       // Q的行数等于M的行数
    Q->nu = N.nu;       // Q的列数等于N的列数
    Q->tu = 0;          // Q非零元个数初值为0
    TransposeSMatrix(N,&T);// T是N的转置
    for(i=1; i<=Q->mu; i++){// 对于M的每一行，求Q[i][j]
        q=1;            // q指向T的第一个非零元素
        for(j=1;j<=T.mu;j++)    // 对于T的每一行（即N的列）求Q[i][j]
        {
            Qs = 0;         // 设置Q[i][j]初值为0
            p = 1;          // p指向T的第一个非零元素
            while(M.data[p].i<i) // 使p指向矩阵M的第i行的第一个非零元素
                p++;
            while(T.data[q].i<j) // 使q指向矩阵T的第j行（即N的第j列）的第一个非零元
                q++;
            while(p<=M.tu && q<=T.tu && M.data[p].i==i && T.data[q].i==j)
            // [p]仍是M的第i行的非零元素且[q]仍是T的第j行（即N的第j列）的非零元
                switch(comp(M.data[p].j,T.data[q].j)){
                    // 比较M当前元素的列值和T矩阵当前元素的列值（即N的行值）
                    case -1:
                        p++;    // M矩阵当前元素的列值 < T(N)矩阵的列值，p后移
                        break;
                    // M当前元素的列值 =T(N)当前元素的列(行)值，则两值相乘并累加到Qs
                    // p、q均向后移
                    case 0:
                        Qs += M.data[p++].e * T.data[q++].e;
                        break;
                    case 1:
                        q++;    // M矩阵当前元素列值 >T(N)矩阵当前元素的列(行)值，q后移                
                }
            if(Qs)  // Q[i][j]不为0
            {
                if(++Q->tu>MAX_SIZE)    // Q的非零元素个数太多
                    return 0;
                Q->data[Q->tu].i = i;   // 将Q[i][j]顺序存入稀疏矩阵Q
                Q->data[Q->tu].j = j;
                Q->data[Q->tu].e = Qs;
            }
        }
    }
}
// 三元组稀疏矩阵的四个基本操作，也可用于行逻辑链接结构

// 销毁稀疏矩阵
void DestroySMatrix(TSMatrix *M){
    M->tu = 0;
    M->nu = 0;
    M->mu = 0;
    return;
}
// 按矩阵形式输出M
void printSMatrix(TSMatrix M){
    int i,j,k=1;            // 非零元计数器，初值为1
    Triple *p = M.data+1;   // p指向M的第一个非零元素
    for(i=1;i<=M.mu;i++){
        // 从第一行到最后一行
        for(j=1;j<=M.nu;j++){
            // 从第一列到最后一列
            if(k<M.tu && p->i==i && p->j==j) // p指向非零元，且p所指元素为当前循环在处理元
            {
                printf("%3d",(p++)->e);     // 输出p所指元素，并向后移一位
                k++;                        // 计数器递增
            }
            else    // p所指元素不是当前循环在处理元素
                printf("%3d",0);    // 0位
        }
        putchar('\n');
    }
}
// 由稀疏矩阵M复制得T
void CopySMatrix(TSMatrix M,TSMatrix *T){
    *T = M;
}
// 求稀疏矩阵的差 Q = M - N
Status SubtSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q){
    int i;
    if(M.nu!=N.nu || M.mu!=N.mu)
        return ERROR;               // 维度不匹配
    for(i=1;i<=N.tu;i++){
        N.data[i].e *= -1;          // 对N的每一个元素乘以-1
    AddSMatrix(M,N,Q);
    return OK;
    }
}
#include <stdlib.h>
// 快速求稀疏矩阵的转置
void FastTransposeSMtrix(TSMatrix M,TSMatrix *T){
    int p,q,col,*num,*cpot;
    num = (int *)malloc((M.nu+1)*sizeof(int));  // 存M每列（T每行）非零元个数，【0】不可用
    cpot = (int *)malloc((M.nu+1)*sizeof(int)); // 存T每行下一个非零元的位置【0】不可用
    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;
    if(T->tu){          // T 非零
        for(col=1;col<=M.nu;col++)      // 从M的第一列到最后一列
            num[col] = 0;               // 计数器初始化为0
        for(p=1;p<=M.tu;p++)            // 对M的每一个非零元素
            ++num[M.data[p].j];         // 根据它所在的列进行统计
        cpot[1]=1;                      // T的第一行第一个非零元在T中排第一
        for(col=2;col<=M.nu;col++)      // 从M(T)的第二列(行)到最后一列(行)
            cpot[col] = cpot[col-1]+num[col-1];
        for(p=1;p<=M.tu;p++){           // 对于M的每一个非零元
            col = M.data[p].j;          // 将其在M的列数赋值给col
            q = cpot[col];              // q指示M当前的元素在T中的序号
            T->data[q].i = M.data[p].j; // 将M的当前元素的转置赋值给T
            T->data[q].j = M.data[p].i;
            T->data[q].e = M.data[p].e;
            cpot[col]++;    // T第col行的下一个非零元在T.data中的序号比当前元素大 1
        }
    }
    free (num);
    free (cpot);
}