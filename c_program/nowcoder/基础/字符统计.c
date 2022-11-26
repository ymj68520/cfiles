#include<stdio.h>
int main(){
	char ch;
	int a=0,b=0,c=0;
	ch=getchar();
	while(ch!='?'){  //£¿½áÊøÑ­»· 
		if(isalpha(ch))
		a++;
		else if(isdigit(ch))
		b++;
		else
		c++;
		ch=getchar();
	}
	printf("Letters=%d\n",a);
	printf("Digits=%d\n",b);
	printf("Others=%d\n",c);
	return 0;
}
