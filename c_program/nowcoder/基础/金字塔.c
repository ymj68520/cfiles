#include<stdio.h>
#define A '*'
#define B ' '
int main (){
	int i,ii,iii,s,n;
	scanf("%d",&n);
	if(n<=0){printf("error"); return 0;}
	if(n%2==0) {printf("error"); return 0;}
	n=(n+1)/2;
	for(i=1;i<=n;i++){ 
		for(ii=0;ii<n-i;ii++){
			printf("%c",B);
		}
		for(iii=0;iii<2*i-1;iii++){
			printf("%c",A);
		}
		printf("\n");
	}
	return 0;
} 
