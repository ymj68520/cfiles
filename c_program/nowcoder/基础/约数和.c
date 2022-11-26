#include<stdio.h>
int main(){
	int i,s,n;
	scanf("%d",&n);
	s=0;
	for(i=1;i<=n;i++){  /*这里可以写：i<=n/2+1*/ 
		if(n%i==0){
			s=s+i;
		}
	}
	printf("%d",s);
	return 0;
} 
