#include<stdio.h>
#include<ctype.h>   //为isspace()函数提供原型 其他c type 见书p195 
#include<stdbool.h>   //为bool true false 提供定义 
#define STOP '|'
int main (void){
	char c;       //读入字符 
	char prev;    //读入的前一个字符 
	long n_chars=0L;     //字符数 
	int n_lines=0;       //行数 
	int n_word=0;         // 单词数 
	int p_lines=0;        // 不完整行数 
	bool inword = false;  //如果c在单词中，inword=true 

	printf("Enter text to be analyzed(| to terminate):\n");
	prev='\n';            //识别完整行 
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

