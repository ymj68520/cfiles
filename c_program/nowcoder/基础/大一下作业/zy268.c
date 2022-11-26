#include <stdio.h>
#include <ctype.h>

int main(){
  double n1=0,n2=0,s=0;
  char op,ch='y';
  int be = 1;

  while(ch == 'y'){
    scanf("%lf %c %lf",&n1,&op,&n2);
    while(getchar()!='\n'){
        continue;
    }
    if(n2==0){
      printf("error\n");
      ch=tolower(getchar());
      continue;
    }
    if(-10000000<n1<10000000 && -10000000<n2<10000000){
      if(op =='+' || op=='-' || op=='*' || op=='/' || op=='%'){
        switch (op)
        {
        case '+':s = n1 + n2; be = 1;
          break;
        case '-':s = n1 - n2; be = 1;
          break;
        case '*':s = n1 * n2; be = 1;
          break;
        case '/': s = n1 / n2; be = 1;
          break;
        default: printf("error\n");be = 0;
          break;
        }
        if(be)
          printf("%.2lf %c %.2lf = %.2lf\n",n1,op,n2,s);
      }
    }
    else
    {
      printf("error\n");
    }
  
  scanf("%c",&ch);
  ch = tolower(ch);
  }

  return 0;
}