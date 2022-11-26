#include <stdio.h>
#include <string.h>

struct book{
    int a;
    char b[100];
    double c;
};

int main(){
    struct book d = {.a=0, 
                    .b = "asdhakushfkaudsfhoa",
                    .c = 1.0 };
    struct book * him;
    him = &d;
    printf("%lf\n",him->c);
    printf("%d\n",(*him).a);
    printf("%s\n",d.b);
    double * e = &d.c;
    char * ret_val;
    char * find;
    char * st;
    ret_val = fgets(st, 20, stdin);
    find = strchr(st,'a');
    if(find){
        puts("feikong");
    }
    else{
        puts("kong");
    }

    return 0 ;
}