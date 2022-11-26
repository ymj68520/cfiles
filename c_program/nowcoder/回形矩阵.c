#include <stdio.h>
#include <string.h>

/*
int main (){
    int n;
    scanf("%d",&n);
    int result[n][n];
    int i=1,j=n-1,count=1,step=1;;
    if(n==1){
        printf("1");
        return 0;
    }
    if(n==2){
        printf("1 2\n");
        printf("4 3\n");
        return 0;
    }
    for(int k=0;k<n;k++)
        result[0][k] = k+1;
    while(n-count-1 != 0){
        if(i==1){
            for(int k=0;k<n-count-1;k++){
                result[i][j] = n+step;
                step++;
                i++;
            }
            j--;
        }
        else{
            for(int k=0;k<n-count-1;k++){
                result[i][j] = n+step;
                step++;
                i--;
            }
            j++;
        }
        if(j==n-2){
            for(int k=0;k<n-count-1;k++){
                result[i][j] = n+step;
                step++;
                j--;
            }
            i--;
        }
        else{
            for(int k=0;k<n-count;k++){
                result[i][j] = n+step;
                step++;
                j++;
            }
            i--;
        }
        count++;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            printf("%d ",result[i][j]);
        }
        printf("%d\n",result[i][j]);
    }
    return 0;
}
*/
int main(){
    int total=0;
    int x=0,y=0;
    int N;
    scanf("%d",&N);
    int array[N+1][N+1];
    memset(array,0,(N+1)*(N+1)*sizeof(int));
    while(total<N*N){
        while(y<N && !array[x][y+1])    array[x][++y] = ++total;
        while(x<N-1 && !array[x+1][y])    array[++x][y] = ++total;
        while(y-1>0   && !array[x][y-1])      array[x][--y] = ++total;
        while(x>0   && !array[x-1][y])      array[--x][y] = ++total;
    }
    for(int i=0;i<N;i++){
        for(int j=1;j<=N;j++)
            printf("%3d ",array[i][j]);
        putchar('\n');
    }
    return 0;
}