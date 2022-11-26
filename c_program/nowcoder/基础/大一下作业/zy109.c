#include <stdio.h>
#include <string.h>
#define SIZE 2560
int main()
{
    char str[SIZE]={'\0'};
    int count=0;
    gets(str);
    int length = strlen(str);
    for (int i=0;i<length;i++)
    {   
        if(str[i]!=' ')
        {
            count++;
            while(str[i]!=' '&&str[i]!='\0')
            {
                i++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
} 