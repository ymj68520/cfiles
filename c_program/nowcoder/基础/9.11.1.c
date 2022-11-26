#include <stdio.h>

//double min(double a, double b){return a<b?a:b;} //(1)
void rank_of(double * a, double * b, double *c);

int main(){
	double a, b, c;
	scanf("%lf%lf%lf",&a,&b,&c);     //（1）求最小值函数 
	//printf("The smaller number is %0.2lf",min(a, b));
	rank_of(&a,&b,&c);
	printf("%lf %lf %lf", a, b, c);
	return 0;
}

void rank_of(double*a, double*b, double*c){  //给主调函数传来的实参排序并修改主调的值 
	double temp;
	if(*a > *b)	{temp = *a;	*a = *b;	*b = temp;	}
	if(*a > *c)	{temp = *a;	*a = *c;	*c = temp;	}
	if(*b > *c)	{temp = *b;	*b = *c;	*c = temp;	}
	return;
}
