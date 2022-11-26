#include<stdio.h>
int Myfloor(double data);
int Myceil(double data);
int main(){
	double data;
	scanf("%f",&data);
	printf("%d\n",Myfloor(data));
	printf("%d\n",Myceil(data));
	return 0;
} 
int Myfloor(double data){
	double date;
	int a;
	a=(int)date;
	return date;
}
int Myceil(double data){
	double datc;
	int b;
	b=(int)(datc+1.0);
	return datc;
}
