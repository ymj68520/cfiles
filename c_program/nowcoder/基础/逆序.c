#include <stdio.h>
#include <string.h>
int main(){
	char str[50];
	scanf("%s",str);
	int len = strlen(str);   //给出长度 
	int top=0,end = len-1;	//定义两个变量指向开头和末尾
	while(top<end){			//一直交换开头和末尾
		char temp = str[top];
		str[top] = str[end];
		str[end] = temp;
		top++;
		end--;
	}
	printf("%s\n",str);
}
