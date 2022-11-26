#include<stdio.h>
#include<math.h>
int main(){
	int n,i,itemn=1;
	double s,item;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		item=(double)1/i*itemn;
		itemn=-itemn;
		s+=item;
	}
	printf("%.3f",s);
	return 0;
} 
