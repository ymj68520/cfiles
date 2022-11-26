#include<stdio.h>
int main(){
	/*long long 实验大数字*/int i=0,n;
	scanf("%d",&n); 
	do{
		if(n%2==1) //除二余一（即为基数） 
		n=(n*3)+1; //奇数成三加一 
		else
		n=n/2;     //偶数除以二 
		i+=1;
	}while(n!=1);
	printf("%d",i); //输出需要的步骤数 
	return 0;
} 
