#include<stdio.h>
#include<stdlib.h>      //ʹ��exit() 

int main(){
	int ch;
	FILE * fp;
	
	char fname[50];        //�����ļ��� 
	
	printf("Enter the name of the file:");
	scanf("%s",fname);
	fp = fopen(fname,"r");    //�򿪴���ȡ�ļ� 
	if(fp==NULL){            //���ʧ�� 
		printf("Failed to open the file. Bye\n");
		exit(1);          //�˳����� 
	}
	// getc(fp)�Ӵ򿪵��ļ��л�ȡһ���ַ� 
	while((ch=getc(fp))!=EOF){
		putchar(ch);
	}
	fclose(fp);                 //�ر��ļ�
	
	return 0 ; 
}
