#include<stdio.h>
#include<stdbool.h>
#define MSG "I`m a message"
int main(){
	char a;
	putchar('H');
	putchar('\007');
	putchar('\n');
	putchar('\b');
	while(true)
	{
		putchar(getchar());
	}
	return 0;
}
