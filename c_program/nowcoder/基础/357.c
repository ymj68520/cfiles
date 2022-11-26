#include<stdio.h>
int main(){
	long int n,b;
	int a,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		if(i%3==2){
			if(i%5==3){
				if(i%7==2){
					printf("%d\n",i); 
				}
			}
		} 
	}
	return 0;
}
