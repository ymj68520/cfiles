#include <stdio.h>

int main (){
    int n;
    int ii,i;
    if(scanf("%d",&n) == 1){
        if(n == -1){
            printf("error\n");
        }
        if(n == 1){
            printf("error\n");
        }
        for(i=2;i<=n;i++){
            for(ii=2;ii<=i;ii++){
			    if(i%ii==0){
				    break;
			    }
		    }
		    if(i==ii)
		        printf("%d,",i);
        }

    }
    else
    {
        printf("error\n");
    }
    

    return 0;
}