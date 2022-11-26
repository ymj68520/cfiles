#include<stdio.h>
int main(){
	int i=1,s=0,n,a;
	scanf("%d",&n);
	do{
		a=n%10;
		n/=10;
		s+=a;
	}while(a>=1);
	printf("%d",s);
	return 0;
} 
