#include<stdio.h>
int main(){
	int n,s,i;
	scanf("%d",&n);
	for(i=1;i<=n;){
		if(i%7==0)
		s+=i;
		i=i+1; 
	}
	printf("%d",s);
	return 0;
} 
