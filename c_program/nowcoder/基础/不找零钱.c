#include <stdio.h>
#include <stdbool.h>

bool isintm(int a, int b, int c);
int main (){
    int a,b,c;
    bool isim;
    scanf("%d %d %d",&a,&b,&c);
    isim = isintm(a, b, c);
    if(isim)
        printf("Yes\n");
    else
        printf("No\n");
    
    return 0;    
}

bool isintm(int a,int b,int c){
    int i,j,k;
    bool is = false;
    for(i=0;i<=(int)(c/a);i++){
        for(j=0;j<=(int)(c/b);j++){
            if(i*a+j*b==c){
                is = true;
                break;
            }
        }
        if(i*a+j*b==c){
                is = true;
                break;
            }
    }
    return is;
}