#include <stdio.h>
#include <math.h>

int main()
{
int a = 0;
int num = 0;
int k = 0;
scanf("%d", &num);
if (num <= 3)
{
printf("error");
scanf("%d",&num);
}
k = (int)sqrt ((double)num);
for(int i = 2; i <= k; i++){
if(num % i == 0){
a++; 
}
}
if(a == 0){
printf("yes");
}else{
printf("no");
}
return 0;

}