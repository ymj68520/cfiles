#include<stdio.h>
int factorial(int x);
int main(){
	int n,s=0,i;
	scanf("%d",&n); 
	for(i=1;i<=n;i++){
		s+=factorial(i);
	}
	printf("%d",s);
	return 0;
}
int factorial(int x){
	int ii,a=1,b;
	for(ii=1;ii<=x;ii++){
		a*=ii;
	}
	return a;
}
