#include <stdio.h>

unsigned long long rFibonacci(unsigned n);//�ݹ� 
unsigned long long Fibonacci(unsigned n);//ѭ�� 

int main(){
	unsigned int n;
	scanf("%d",&n);
	printf("%lld\n",Fibonacci(n)); 
	printf("%lld",rFibonacci(n));  //��n=40��ʼ ���ݹ�����ӳ�  
	return 0;
} 

unsigned long long rFibonacci(unsigned n){
	if(n>2)
		return rFibonacci(n-1)+rFibonacci(n-2);
	else
		return 1;
}

unsigned long long Fibonacci(unsigned n){
	unsigned long i,s,n1=1,n2=1;
	if(n<=2)
		return 1;
	for(i=3;i<=n;i++){
		s = n1 + n2;
		n1 = n2;
		n2 = s;
	}
	return s;
}
