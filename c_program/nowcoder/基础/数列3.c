#include<stdio.h>
int main(){
	int n,i,j,item=0;
	scanf("%d",&n);
	for(j=0;j<=n;j++){
		for(i=0;i<=j;i++){
			item+=i;
		}
	}
	printf("%d",item);
	return 0;
} 
