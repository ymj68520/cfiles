#include <stdio.h>
#include <math.h>

int main(){
    int square[5][5];
    int i,k,j,s;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            scanf("%d",&square[i][j]);
        }
        
    }
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(square[i][j]==1)
                break;
        }
        if(square[i][j]==1)
                break;
    }
    s=abs(i-2)+abs(j-2);
    printf("%d\n",s);
    return 0;
}