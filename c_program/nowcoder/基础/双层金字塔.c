/*#include<stdio.h>
#define A '*'
#define B ' '
void JZT1(int z);
int main() {
	int n1,n2,a,b,c;
	scanf("%d %d",&n1,&n2);
	JZT1(n1);
	for(a=1;a<=n2;a++){
		for(b=1;b<=n2;b++){
			printf("%c",B);
		}
		for(c=1;c<=2*a-1;c++){
			printf("%c",A);
		}
		printf("\n");
	}
	b-=b;c-=c;
	for(;a>=1;a--){
		for(;b>=1;b--){
			printf("%c",B);
		}
		for(;c>=1;c--){
			printf("%c",A);
		}
		printf("\n");
	}
	return 0;
}
void JZT1(int z){
	int i,ii,iii,s,n;
	for(i=1;i<=n;i++){ 
		for(ii=0;ii<n-i;ii++){
			printf("%c",B);
		}
		for(iii=0;iii<2*i-1;iii++){
			printf("%c",A);
		}
		printf("\n");
	}
}*/
#include<stdio.h>
#include<string.h>
#define A '*'
#define S ' '
int main(){
	int i,j,k,n,s;
	scanf("%d %d",&n,&s);
	for(i=0;i<n;i++){ //双层金字塔上半层 
		for(j=0;j<n-i;j++){  //空格数 
			printf("%c",S);
		}
		for(k=0;k<2*i-1;k++){ //字符数 
			printf("%c",A);
			printf("\n");
		}
	}
	for(i--;i>0;i--){ //下半层 
		for(j--;j>0;j--){  //同上，不多写= = 
			printf("%c",S);
		} 
		for(k--;k>0;k--){
			printf("%c",A);
		}
	}
	
	return 0;
}
