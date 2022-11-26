#include<stdio.h>
int main(){
	int i,a,b;
	for(i=1;i<=9;i++){
		for(a=1;a<=i;a++){
			printf("%d*%d= %d ",a,i,a*i);
			}
		printf("\n");
	}
	return 0;
}
