#include <stdio.h>
/*
int main(){
    char pre=0;
    char now;
    int result=0;
    scanf("%d",&pre);
    while(~scanf("%c",&now)){
        if(now == '*'){
            scanf("%d",&now);
            int temp = pre*now;
            result +=  temp;
            pre = now;
            continue;
        }
        if(now == '+'){
            result +=pre;
            continue;
        }
        pre = (int)now-48;

    }
    printf("%d",result);
    return 0;
}
*/

int main(){
    const int SLEN=200000;
    typedef struct{
        int top;
        int base;
        int count;
    }StPt;
    StPt p = {1,0,1};
    long St[SLEN];
    scanf("%ld",St);
    char ch;
    while(~scanf("%c",&ch)){
        if(ch == '+'){
            scanf("%ld",St+p.top);
            p.top++;
            p.count++;
        }
        if(ch == '*'){
            scanf("%ld",St+p.top);
            St[p.top-1] = (St[p.top-1] * St[p.top])%10000; 
        }
    }
    for(int i=1;i<p.count;++i){
        St[0]+=St[i];
    }
    printf("%ld",St[0]%10000);
    return 0;
}