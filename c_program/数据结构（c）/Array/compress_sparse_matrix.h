// sparse matrix 稀疏矩阵
// defination {
//    matrix[m,n];
//    In matrix[m,n], there are t element is not zero;
//    Let δ=t/(m*n),δ is matrix`s sparse factor(稀疏因子);
//    Usually, if δ<=0.05, this matrix is sparse matrix;
// }
#define MAX_SIZE 100 // 非零元个数的最大值