#include<stdio.h>
int main(){
	int i,ii,iii,s=0,n;
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		for(ii=0;ii<=n/2;ii++){
			for(iii=0;iii<=n/5;iii++){
				if(i+2*ii+5*iii==n){
					s+=1;
				}
			}
		}
	}
	printf("%d",s);
	return 0;
}
