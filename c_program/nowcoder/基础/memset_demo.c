#include <stdio.h>
#include <string.h>

void pr(int *,int n);
int main(){
    unsigned int t1[10];
    int *t2;
    t2 = (int *) memset(t1,1,10*sizeof(int));
    pr(t1,10);
    pr(t2,10);
    puts("-----------分界线----------");
    memset(t2,0,10*sizeof(int));
    pr(t2,10);
    memcpy(t1,t2,10*sizeof(int));
    pr(t2,10); pr(t1,10);
    puts("-----------分界线----------");
    memset(t1,1,10*sizeof(int));
    memset(t2,0,10*sizeof(int));
    memmove(t1,t2,10*sizeof(int));
    pr(t2,10); pr(t1,10);
    puts("-----------分界线----------");
    t2[9] = 9;
    int * t3=memchr(t2,9,10*sizeof(int));
    pr(t3,1);
    puts("-----------分界线----------");
    char t4[10];
    memset(t4,9,10);
    int i;
    for(i=0;i<10;i++)
        printf("%d ",t4[i]);
    printf(" :%d\n",i);
    puts("-----------分界线----------");
    int t5[10];
    memset(t5,-1,sizeof(t5));
    pr(t5,10);
}
void pr(int *ar,int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    putchar(':');
    printf("%d",i);
    putchar('\n');
}