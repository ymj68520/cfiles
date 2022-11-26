#include <stdio.h>

int max_num(int * ar,int n);

int main (){
    int i;
    int male,female;
    int max_m,max_f;
    scanf("%d %d",&male,&female);
    int mfight[male],fefight[female];
    for(i=0;i<male;i++){
        scanf("%d",&mfight[i]);
    }
    max_m = max_num(mfight,male);
    for(i=0;i<female;i++){
        scanf("%d",&fefight[i]);
    }
    max_f = max_num(fefight, female);
    printf("%d",max_m + max_f);
    return 0 ;
}

int max_num(int * ar, int n){
    int i,maxn=0;
    for(i=0;i<n;i++){
        if(maxn < ar[i]){
            maxn = ar[i];
        }
    }
    return maxn;
}