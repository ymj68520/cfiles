#include<stdio.h>
int main(){
	/*long long ʵ�������*/int i=0,n;
	scanf("%d",&n); 
	do{
		if(n%2==1) //������һ����Ϊ������ 
		n=(n*3)+1; //����������һ 
		else
		n=n/2;     //ż�����Զ� 
		i+=1;
	}while(n!=1);
	printf("%d",i); //�����Ҫ�Ĳ����� 
	return 0;
} 
