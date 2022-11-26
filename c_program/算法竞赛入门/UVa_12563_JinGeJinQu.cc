#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
int n,t;
int ans[10002];
int a[52];
int k=0;
int main(){
    int T;
	scanf("%d",&T);
	while(T--){
		memset(ans,-1,sizeof(ans));
		scanf("%d %d",&n,&t);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		ans[0]=0;
		for(int i=1;i<=n;i++){
			for(int j=t;j>=a[i];j--){
				if(ans[j-a[i]]!=-1){
					ans[j]=max(ans[j],1+ans[j-a[i]]);
				}
			}
		}
		int maxn=-1;int p=0;
		for(int i=0;i<t;i++){
			if(ans[i]>=maxn){
				maxn=ans[i];
				p=i;
			}
		}
		
		if((maxn+1>ans[t])||(maxn+1==ans[t]&&p+678>t)){
			printf("Case %d: %d %d\n",++k,maxn+1,p+678);
		}else{
			printf("Case %d: %d %d\n",++k,ans[t],t);//存在一种情况，t过长而给的歌曲过少 
		}
	}
	return 0;
}