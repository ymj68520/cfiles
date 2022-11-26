/*×Ö·û»¥»»*/
#include <stdio.h>
int main (){
	char ch;
	int i=0,s,n;
	char a[1000];
	while((ch=getchar())==1){
		a[i]=ch;
		i++;
	}
	for(;i>=1;i--){
		printf("%c",a[i]);
	}
	return 0;
}
