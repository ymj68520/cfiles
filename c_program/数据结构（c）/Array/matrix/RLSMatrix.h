#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100    // 非零元最大数
#define MAX_RC 20       // 最大行数
#define Status bool
#define ERROR false
#define OK true

typedef int ElemType;
typedef struct {
    int i,j;
    ElemType e;
}Triple;
typedef struct{
    Triple data[MAX_SIZE];
    int rpos[MAX_RC+1];     // 各行第一个非零元的位置表
    int mu,nu,tu;
}RLSMatrix;

//比较整数c1和c2的大小，分别返回-1,0,1
int comp(int c1, int c2){   
    if(c1<c2)
        return -1;
    else if(c1==c2)
        return 0;
    else    //c1 > c2
        return 1;
}

// 创建稀疏矩阵M
Status CreatSMtrix(RLSMatrix *M){
    int i,j;
    Triple T;
    Status k;
    printf("请输入矩阵的行数，列数，非零元个数：");
    scanf("%d%d%d",&M->mu,&M->nu,&M->tu);
    if(M->tu>MAX_SIZE || M->mu>MAX_RC)  // 矩阵的非零元个数太多或行数太多
        return  ERROR;
    M->data[0].i = 0;   // 做准备
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
    for(i=1;i<=M->mu;i++)   // 给rpos[]赋初值
        M->rpos[i] = 1;
    for(i=1;i<=M->tu;i++)   // 对于每个非零元，按行统计，并计入rpos[]
        for(j=M->data[i].i+1;j<=M->mu;j++)  // 从非零元所在的行的下一行起
            M->rpos[j]++;   // 每行第一个非零元的位置 +1
    return OK;
}
// 求稀疏矩阵的和 Q = M + N
Status AddSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix *Q){
    int k,p,q,up,uq;
    if(M.mu!=N.mu || M.nu!=N.nu)    // 维度不匹配
        return ERROR;
    Q->mu = M.mu;
    Q->nu = M.nu;
    Q->tu = 0;      // 初始化为0
    for(k=1;k<=M.mu;k++){   // 对于每一行，k指示行号
        Q->rpos[k] = Q->tu+1;   // 矩阵Q第K行的第一个元素的位置
        p = M.rpos[k];
        q = N.rpos[k];
        if(k<M.mu)  // 不是最后一行
        {
            up = M.rpos[k+1];   // 下一行的第一个元素位置是本行元素的上界
            uq = N.rpos[k+1];
        }
        else        // 是最后一行
        {
            up = M.tu+1;
            uq = N.tu+1;
        }
        while(p<up && q<uq){    // 矩阵M、N均有第K行未处理
            switch(comp(M.data[p].j,N.data[q].j))   // 比较列值
            {// 矩阵M当前元素的列<矩阵N当前的列，将M的当前元素赋值给Q，p后移
                case -1: 
                    Q->data[++Q->tu] = M.data[p++];
                    break;
                case 0:
                    if(M.data[p].e+N.data[q].e!=0){
                        Q->data[++Q->tu] = M.data[p];
                        Q->data[Q->tu].e+= N.data[q].e;
                    }
                    p++;    // 无论和是否为0，都向后移
                    q++;
                    break;
                // 矩阵M当前元素的列>矩阵N当前元素的列，将N的当前元素赋值给Q，q向后移
                case 1:
                    Q->data[++Q->tu] = N.data[q++];
            }// 以下两个循环最多执行一个
            while(p<M.rpos[k+1] && p<=M.tu) // N的K行处理完，M还有余下
                Q->data[++Q->tu] = M.data[p++];
            while(q<N.rpos[k+1] && q<=N.tu) // N还有余下
                Q->data[++Q->tu] = N.data[q++];
        }
    }
    if(Q->tu>MAX_SIZE)  // 非零元太多
            return ERROR;
        else
            return OK;
}
// 求稀疏矩阵M的转置T
void TransposeSMatrix(RLSMatrix M,RLSMatrix *T){
    int i,j,k,num[MAX_RC+1];    // [0]不可用
    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;
    if(T->tu){
        for(i=1;i<=T->mu;i++)
            num[i] = 0;
        for(i=1;i<=M.tu;i++)
            num[M.data[i].j]++;
        T->rpos[1] = 1;
        for(i=2;i<=T->mu;i++)
            T->rpos[i] = T->rpos[i-1]+num[i-1];
        for(i=1;i<=M.tu;i++){
            j = M.data[i].j;
            k = num[j]++;
            T->data[k].i = M.data[i].j;
            T->data[k].j = M.data[i].i;
            T->data[k].e = M.data[i].e;
        }
    }
}
// 求稀疏矩阵的乘积 Q = M * N
Status MiltSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix *Q){
    int arow,brow,p,q,ccol,ctemp[MAX_RC+1],t,tp;
    if(M.nu != N.mu) // 维数不匹配
        return ERROR;
    Q->mu = M.mu;
    Q->nu = N.nu;
    Q->tu = 0;
    if(M.tu * N.tu != 0)
        for(arow = 1;arow<=M.mu;arow++){
            for(ccol = 1;ccol<=Q->nu;ccol++){
                ctemp[ccol] = 0;
            }
            Q->rpos[arow] = 0;
            if(arow<M.mu)
                tp = M.rpos[arow+1];
            else
                tp = M.tu + 1;
            for(p = M.rpos[arow];p<tp;p++){
                brow = M.data[p].j;
                if(brow<N.mu)
                    t = N.rpos[brow+1];
                else    
                    t = N.tu+1;
                for(q = N.rpos[brow];q<t;q++){
                    ccol = N.data[q].j;
                    ctemp[ccol] += M.data[p].e * N.data[q].e;
                }
            }
            for(ccol =1;ccol<=Q->nu;ccol++)
                if(ctemp[ccol]){
                    if(++Q->tu>MAX_SIZE)
                        return ERROR;
                    Q->data[Q->tu].i = arow;
                    Q->data[Q->tu].j = brow;
                    Q->data[Q->tu].e = ctemp[ccol];
                }
        }
    return OK;
}

