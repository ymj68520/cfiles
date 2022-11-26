#include<stdio.h>
/*#include<ctype.h>
#include<stdbool.h>*/
#include<conio.h>


int main(){
	int a,b;
	while(1){
	a=getche(); //无缓冲输入，回显输入
	printf("\n");
	b=getch();  //无缓冲输入，无回显输入 
	printf("%d\n",b);
    }
	return 0;
} 
