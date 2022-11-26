#include <stdio.h>
#include <stdlib.h>

int main(){
    typedef int ELemtype;
    ELemtype squeue[100][2];
    int i=0;
    FILE *fp = fopen("Stack_queue","r");
    ELemtype e;
    while(fscanf(fp,"%d%*c",&e)){
        if(e>0){
            squeue[i++][0] = e;
            squeue[i-1][1] = i; 
        }
        else if(-1 == e){
            i--;
            squeue[i][0] = 0;   // 可以省略
        }
        else if(0 == e)
            break;
    }
    
    for(int j=0;j<i;j++){
        printf("%d ",squeue[j][0]);
    }
}