#include <stdio.h>
#include <string.h>
int main(){
	char str[50];
	scanf("%s",str);
	int len = strlen(str);   //�������� 
	int top=0,end = len-1;	//������������ָ��ͷ��ĩβ
	while(top<end){			//һֱ������ͷ��ĩβ
		char temp = str[top];
		str[top] = str[end];
		str[end] = temp;
		top++;
		end--;
	}
	printf("%s\n",str);
}
