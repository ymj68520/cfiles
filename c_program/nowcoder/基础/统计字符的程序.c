#include<stdio.h>
#include<ctype.h>   //Ϊisspace()�����ṩԭ�� ����c type ����p195 
#include<stdbool.h>   //Ϊbool true false �ṩ���� 
#define STOP '|'
int main (void){
	char c;       //�����ַ� 
	char prev;    //�����ǰһ���ַ� 
	long n_chars=0L;     //�ַ��� 
	int n_lines=0;       //���� 
	int n_word=0;         // ������ 
	int p_lines=0;        // ���������� 
	bool inword = false;  //���c�ڵ����У�inword=true 

	printf("Enter text to be analyzed(| to terminate):\n");
	prev='\n';            //ʶ�������� 
	while((c=getchar())!=STOP){
		n_chars++;//tong ji zi fu
		if(c=='\n'){
			n_lines++;  //tong ji hang
		}
		if(!isspace(c)&&!inword){
			inword = true;//kai shi yi ge xin de dan ci
			n_word++; //tongji dan ci
		}
		if (isspace(c)&&inword)
			inword = false;
		prev = c;
	}
	if (prev != '\n')
		p_lines = 1;
	printf("characters = %d, word = %d, lines = %d,",
			            n_chars, n_word, n_lines);
	printf("paratial lines = %d\n",p_lines);
	return 0;


}

