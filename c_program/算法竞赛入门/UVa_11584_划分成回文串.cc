#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
char a[1001];
int dp[1001],len;
bool mark[1001][1001]; // 标记s[i...j]是否为回文串

void init()
{
	for(int i=1;i<=len;i++)
	{
		int p,q;p=q=i;
		bool flag=true;
		while(p>=1&&q<=len)      //以某一个为中心 
		{
			if(a[p]!=a[q]) flag=false;
			mark[p][q]=flag;
			p--;q++;
		}
		p=i,q=i+1;
		flag=true;
		while(p>=1&&q<=len)    //以某两个为中心 
		{
			if(a[p]!=a[q]) flag=false;
			mark[p][q]=flag;
			p--;q++;
		}
	}
}
int main()
{
	while(scanf("%s",a+1)!=EOF)
	{
		memset(mark,false,sizeof(mark));
		len=strlen(a+1);
	    init();
	    dp[0]=0;dp[1]=1;      //边界赋值 
	    for(int i=2;i<=len;i++)
	    {
	    	dp[i]=i;
	    	for(int j=1;j<=i;j++)
	    	{
	    		if(mark[j][i]) dp[i]=min(dp[j-1]+1,dp[i]);
			}
		}
		cout<<dp[len]<<endl;
	}
	return 0;
}
 
