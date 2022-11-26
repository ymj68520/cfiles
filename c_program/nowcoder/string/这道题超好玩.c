#include <stdio.h>
#include <math.h>

int main(){
    int zero_one[1000];
    int zero_len=0;
    while(~scanf("%d",zero_one+zero_len)){
        zero_len++;
    }
    int n=0;
    for(int i=0;i<zero_len;i++){
        n+=zero_one[i]*pow(2,zero_len-1);
    }
    int changed[1000];
    int i;
    for(i=0;n>0;i++){
        changed[i] = n%32;
        n = n/32;
    }
    for(i--;i>=0;i--){
        if(changed[i]>9)
            printf("%c",'A'+changed[i]-10);
        else
            printf("%d",changed[i]);
    }
    return 0;
}
/*
#include <stdio.h>
int main ()
{
	int i,j,k,t,b[1010];
	char a[1010];
	while(scanf("%s",a)!=EOF)
	{
		for(i=0;a[i]!='\0';i++) if(a[i]=='0') b[i]=0;else b[i]=1;
		k=i%5;
		if(k==1) t=b[0];
		else if(k==2) t=b[0]*2+b[1];
		else if(k==3) t=b[0]*4+b[1]*2+b[2];
		else if(k==4) t=b[0]*8+b[1]*4+b[2]*2+b[3];
		else if(k==0) {t=b[0]*16+b[1]*8+b[2]*4+b[3]*2+b[4];k=5;}
		printf("%c",(t>9)?('A'+t-10):('0'+t));
		for(j=k;j<i;j=j+5)
		{
			t=b[j]*16+b[j+1]*8+b[j+2]*4+b[j+3]*2+b[j+4];
			printf("%c",(t>9)?('A'+t-10):('0'+t));
		}
		printf("\n");
	}
    return 0;
}
*/