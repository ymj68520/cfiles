#include<stdio.h>
#include<math.h>
/*int main(){
	int n,i,s,a,ii;
	int b;
	scanf("%d",&n);
	if(n>=10000)
		a=5;
	else if(n>=1000)
		a=4;
	else if(n>=100)
		a=3;
	else if(n>=10)
		a=2;
	else if(n>=1)
		a=1;
	char item[a];
	for(i=1;i<=a;i++) {
		item[i]=n%10;
		n/=10;
	}
	for(ii=1;ii<=a;ii++){
		if(item[ii]!=item[a-ii+1]){
			
		}
	}
	return 0;
}*/
int main(){
	int n,i,ii,s,a,b,c;
	char item[5];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		a=i;
		ii=0;
		do{
			item[ii]=a%10;
			a/=10;
			ii+=1;
		}while(a>=1);
		b=0;
		c=0;
		for(;ii>=1;ii--){
			b+=item[ii-1]*pow(10,c);
			c++;
		}
		if(i==b){
			printf("%d\n",i);
		}
	} 
	return 0;
}
