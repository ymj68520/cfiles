#include <stdio.h>

int main(){
    char number[9];
    for(int i=0;i<9;i++){
        scanf("%c",number+i);
        if(number[i]=='-')
            i--;
    }
    int sum=0;
    char n;
    scanf("%*c%c",&n);
    for(int i=0;i<9;i++)
        sum+=(number[i]-'0')*(i+1);
    int isbn = sum%11;
    char result;
    if(isbn == 10)
        result = 'X';
    else
        result = '0'+isbn;
    if(result == n)
        printf("Right");
    
    else{
        for(int i=0;i<9;i++){
            printf("%c",number[i]);
            if(i==0 || i==3)
                printf("-");
        }
        printf("-%c",result);
    }
    return 0;
}