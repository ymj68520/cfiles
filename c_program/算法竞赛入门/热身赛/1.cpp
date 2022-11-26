// 双十一
#include <iostream>

using namespace std;
int main(){
    int n,m,t,i,sum=0;
    scanf("%d%d",&n,&m);
    int price[n];
    for(i=0;i<n;i++)
        price[i] = __INT_MAX__;
    while(m--){
        for(i=0;i<n;i++){
            scanf("%d",&t);
            if(t == -1)
                continue;
            else if(t<price[i])
                price[i] = t;
        }
    }
    for(i=0;i<n;i++)
        sum+=price[i];
    printf("%d\n",sum);

    return 0;
}