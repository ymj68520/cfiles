#include<stdio.h>
/*int main(){
	long long int a,b;
	int i,item=0,c,d;
	scanf("%lld %lld",&a,&b); 
	if(a>b){
		i=a;
		a=b;
		b=i;
	}
	for(i=0;i<=b-a;i++){
		c=(a+i)%10;
		d=(a+i)%100;
		if((c+d)%10==5||(c+d)%10==0)
		item+=1;
	}
	printf("%d",item);
	return 0;
}*/  /*取两位，下面是取N位*/ 
int main() 
{ 
 int i,count,p,q;
 int a,c; 
 scanf("%d %d",&p,&q);
 count=0; 
 for(i=p;i<=q;i++){  /*注意小于等于*/ 
    a=i;c=0;
         while(a!=0){ 
  		 c=c+a%10;/*依次取出个位，十位，百位.... */
         a=a/10;  
  } 
 if(c%5==0&&c!=0)
  count++; 
 } 
 printf("%d",count); 
 return 0; 
}
