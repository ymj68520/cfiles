#include <stdio.h>

typedef struct {
    int max_elem;
    int max_time;
}MAX;

int main(){
    int n;
    scanf("%d",&n);
    int terget[20][2] = {0};
    for(int i=0;i<n;i++)
        scanf("%d",&terget[i][0]);
    MAX Max = {0,0};
    int i,j;
    for(i=0;i<n;i++){
        if(terget[i][1]==1)
            continue;
        terget[i][1] = 1;
        int count=1;
        for(j=i;j<n;j++){
            if(terget[i][0]==terget[j][0]){
                count ++;
                terget[j][1] = 1;
            }
        }
        if(count>Max.max_time){
            Max.max_elem = terget[i][0];
            Max.max_time = count;
        }
        
    }
    printf("%d",Max.max_elem);
    return 0;
}