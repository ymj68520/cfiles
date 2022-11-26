#include <stdio.h>

double larger_of(double * x, double *y);

int main(){
	double x,y,z;
	scanf("%lf %lf",&x,&y);
	z = larger_of(&x, &y);
	printf("%lf",z);
	return 0 ;
}

double larger_of(double * x, double *y){
	double temp;
	temp = (*x > *y) ? *x : *y;
	*x = *y = temp;
	return temp;
}
