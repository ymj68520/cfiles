#include <bits/stdc++.h>
using namespace std;

struct Point{
	int x,y;
}P[1001];
int n;
double dp[1001][1001];

double dist(int i,int j){
	double len=sqrt((P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y));
	return len;
}

int main(){
	while(scanf("%d",&n)==1){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d %d",&P[i].x,&P[i].y);
		}
		
//		for(int j=1;j<=n;j++){
//			dp[j][n]=dp[n][j]=dist(j,n);
//		}
		
		for(int j=1;j<n-1;j++){
			dp[n-1][j]=dist(n-1,n)+dist(j,n);
		}
//		
		for(int i=n-2;i>=1;i--){
			for(int j=i-1;j>=1;j--){
				dp[i][j]=min(dp[i+1][j]+dist(i,i+1),dp[i+1][i]+dist(j,i+1));
			}
		}
		printf("%.2lf\n",dp[2][1]+dist(1,2));
	}
	return 0;
}