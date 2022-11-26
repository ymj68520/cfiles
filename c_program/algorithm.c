#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



//矩阵相乘
int * matrix(int n,int a[][n],int b[][n]){
    int c[n][n];
    for(int i=1;i<=n; i++){
        for(int j=1;j<=n;j++){
            c[i][j] = 0;
            for(int k=1;k<=n;k++)
                c[i][j]+=a[i][k] * b[k][j];
        }
    }
    return c;

}
