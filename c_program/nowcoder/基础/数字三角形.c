#include<stdio.h>
int main(){
	int i,s=1,n,a;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(a=1;a<=i;a++){
			printf("%4d",s); //�ĸ��ֶο�ȱ�֤�����Ҷ��� 
			s++;
		}
		printf("\n");
	}
	return 0;
}
