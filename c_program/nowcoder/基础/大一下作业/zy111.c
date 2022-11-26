#include <stdio.h>

int main (){
    char  S1[1000];
    char  S2[1000];
    gets(S1);
    gets(S2);
    int times=0;
    int i=0,j=0,k=0;
    int len1=0,len2=0;
    int location[1000];
    while(S1[i]!='\0'){
        len1++;
        i++;
    }   
    while(S2[j]!='\0'){
        len2++;
        j++;
    }
    for(i=0;i<len1;++i){
        for(j=0;j<len2;++j)
            if(S2[j]!=S1[i+j])
                break;
        if(j == len2 && S2[j-1]==S1[i+j-1]){
            location[k] = i;
            k++;
        }
    }
    if(k==0){
        printf("NO");
        return 0;
    }
    printf("%dtimes,",k);
    for(i=0;i<k;i++)
        printf("%d,",location[i]);
    putchar('\b');
    return 0;
}