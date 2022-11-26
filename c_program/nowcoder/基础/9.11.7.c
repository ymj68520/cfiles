#include <stdio.h>
#include <ctype.h>
 
int sta(char ch);
//int statistics(void);

/*int main(){
	
	sta();
	return 0;
}

int statistics(void){
	char ch;
	while ((ch=getchar()) !=EOF){
		if(isalpha(ch)){
			ch = tolower(ch);
			printf("The location of %c is %d\n",ch,ch-96);
		}
		else
			return -1;
		
	}
	return;
	 
}*/

int main () {
	char cha;
	int local;
	while(scanf("%c",&cha)==1 && cha!=EOF){
		local=sta(cha);
		printf("%d  ",local);
	}
	return 0;
}

int sta( char ch){
	if(isalpha(ch)){
		ch = tolower(ch);
		ch=(int)ch-96;
		return ch;
	}
	else
		return -1;
}
