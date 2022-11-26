#include <stdio.h>

//int Boom(char TheBoom[m][n],int i,int j);
int main (){
    int m,n;
    scanf("%d %d",&m,&n);
    char TheBoom[200][200];
    int count[200][200];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%c",&TheBoom[i][j]);
            if(TheBoom[i][j]=='\n')
                scanf("%c",&TheBoom[i][j]);
            if(TheBoom[i][j]=='*'){
                count[i][j] = -99;
                count[i][j+1]++;
                count[i][j-1]++;
                count[i+1][j]++;
                count[i-1][j]++;
                count[i-1][j-1]++;
                count[i-1][j+1]++;
                count[i+1][j+1]++;
                count[i+1][j-1]++;
            }

        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(count[i][j]<0){
                printf("*");
                continue;
            }
            printf("%d",count[i][j]);
            }
        printf("\n");
    }
    return 0;
}
/*    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int count=0;
            if(TheBoom[i][j]=='*'){
                printf("*");
                continue;
            }
            count = Boom(TheBoom,i,j);
            count += Boom(TheBoom,i,j-1);
            count += Boom(TheBoom,i,j+1);
            printf("%d",count);
        }
        printf("\n");
    }
}
int Boom(char TheBoom[m][n],int i,int j){
    int count = 0;
    if(i == m || j == n)
        return 0;
    if(i+1 != m && TheBoom[i+1][j] == '*')
        count ++;
    if(TheBoom[i][j] == '*')
        count ++;
    if(i != 0 && TheBoom[i-1][j] == '*')
        count ++;
    return count;
}*/