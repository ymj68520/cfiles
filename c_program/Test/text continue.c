#include <stdio.h>
//#include <>
int main(){
	int i=0,a,b;
	a=10;
	while(i<a){
		scanf("%d",&b);

		if(b==0){
			continue;
		}
		printf("%d",b);
	}
	return 0;
}
