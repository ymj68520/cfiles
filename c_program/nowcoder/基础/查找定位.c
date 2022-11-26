#include<stdio.h>

int main()
{
int m,n,i,a[20],c=0;
  while((scanf("%d",&n))!=EOF){ 
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(i=0;i<n;i++){
            if(m==a[i]){ 
                c=0;
                break;
            }
	        else 
                c=1;
	}
	 if(c==1) 
        printf("No\n");
	 else
        printf("%d\n",i); 
	
  }
    return 0;
}