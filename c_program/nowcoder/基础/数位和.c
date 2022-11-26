#include<stdio.h>
int main(){
	int n;
	int a,b=0;
	scanf("%d",&n);
	do{
		a=n%10;
		b+=a;
		n/=10;
	}while(n>=1);
	printf("%d",b);
	return 0;
}
