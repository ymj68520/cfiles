#include <stdio.h>

int main(){
    int n;     //ta de shu liang
    int nh[100];  //ta de chu shi gao du
    int m;  //gong zuo tian shu 
    int a,b,c;  // cong di a ge ta dao di b ge ta zeng jia c ge gao du
    int i,j;  //ji shu qi
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&nh[i]);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        for(j=a;j<=b;j++){
            nh[j-1]+=c;
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",nh[i]);
    }
    return 0;
}