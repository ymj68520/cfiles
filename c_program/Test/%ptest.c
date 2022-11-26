#include<stdio.h>

int imax(int a, int b){ return a>b?a:b;}

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d is located in %p\n",imax(a, b),&a);
	return 0 ;
} 
