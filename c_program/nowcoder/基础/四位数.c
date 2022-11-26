/*#include<stdio.h>
int main(){
	int a,b,c,d;
	int e,f,g,item;
	long int n,i;
	scanf("%d",&n);
	for(i=1000;i<=n;i++){
		item=i;
		d=item%10;
		item/=10;
		c=item%10;
		item/=10;
		b=item%10;
		item/=10;
		d=item%10;
		e=(a*10)+b;
		f=(c*10)+d;
		g=e+f;
		g=g*g;
		if(g==i){
			printf("%d",i);
		} 
	}
	return 0;
}*/
#include<stdio.h>
int main(){
    int n,i,a,b,c,d;
    scanf("%d",&n);
    for(i=1000;i<=n;i++)
    {
    a=i/100;
    b=i/10%10;
    c=i%10;
    d=b*10+c;
	if((a+d)*(a+d)==/*a*100+d*/i)
        printf("%d\n",i);
    }
}
