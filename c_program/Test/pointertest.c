#include <stdio.h>

void imax(int * a, int * b);
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	imax(&a, &b);
	printf("%d %d",a,b);
	return 0;
}

void imax(int * a, int * b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
