#include<stdio.h>

int main(void){
	int a,b=10,c=20;
	while(scanf("%d",&a)!=EOF){ //ctrl + Z ?????   导致无限循环？？？？ 
		printf("%d\n",b*a-c);
	}
}
