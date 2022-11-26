#include <stdio.h>

int main(void)
 {
	int n,div,c,i;
	div=2;
	
	scanf("%d",&n);
	
		if(n<=3)
		printf("error");
		else
		{ 
			i=0;
			while(div<n)
				{
					c=n%div;
					div++;
					
			
				
					if(c=0)
					{
					
						i++;
					}
				}
				
			if(i==0)
			printf("yes");
			else
			printf("no"); 
		} 
		
	
	return 0;
}
