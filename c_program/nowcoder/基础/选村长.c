#include<stdio.h>
int main(){
	int i=0,n,a=0,b=0,c=0,ii=0;
	while(scanf("%d",&n)){
		if(n==-1){
			break;
		}
		if(n==1){
			a+=1;
			i++;
		}
		if(n==2){
			b+=1;
			i++;
		}
		if(n==3){
			c+=1;
			i++;
		}
		ii++;
	}
	printf("A=%d\n",a);
	printf("B=%d\n",b);
	printf("C=%d\n",c);
	printf("Tot=%d\n",i);
	if(a>ii/2)
	printf("A-yes\n");
	else if(b>ii/2)
	printf("B-yes\n");
	else if(c>ii/2)
	printf("C-yes\n");
	else
	printf("all-NO\n");
	return 0;
} 
