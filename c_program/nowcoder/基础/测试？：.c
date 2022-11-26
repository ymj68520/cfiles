#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
int main(){
	int x=10,y=10;
	char ch;
	while(true){
		ch=getchar();
		/*scanf("%d",&y);
		x=(y<0)?-y:y;
		printf("%d\n",x);
		if(y==0){
			break;
		}*/
		printf("%c",ch);
		if(ch=='q'){
			break;
		}
	}
	return 0;
} 
