#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode{
    char sign;
    int coefficient;
    int exponent;
    struct LinkNode *next;
}polynomial;

int main(){
    polynomial H;
    scanf("%d%*c",&(H.coefficient));
    polynomial *p,*q;
    int i=0;
    p = &H;
    while(i<=H.coefficient){
        q = (polynomial*)malloc(sizeof(polynomial));
        int temp;
        scanf("%d",&temp);
        if(temp>=0){
            q->sign = '+';
            q->coefficient = temp;
        }
        else{
            q->sign = '-';
            q->coefficient = -temp;
        }
        q->exponent = H.coefficient - i;
        p->next = q;
        p = p->next;
        i++;
    }
    p = H.next;
    for(int j=0;j<=H.coefficient;j++){
        if(p->coefficient==0 && p->exponent == 0)
            if(j==0)
                printf("0");
            else
                printf("+0");
        if(j==0 && p->coefficient ==0){
            j--;
            H.coefficient--;
        }
        if(j==0 && p->sign == '+'){
            if(p->coefficient != 1)
                printf("%dx^%d",p->coefficient,p->exponent);
            else
                printf("x^%d",p->exponent);
            p=p->next;
            continue;
        }
        if(p->coefficient == 0){
            p = p->next;
            continue;
        }
        if(p->coefficient == 1 && p->exponent!=0){
            printf("%cx^%d",p->sign,p->exponent);
            p = p->next;
            continue;
        }
        if(p->exponent==1){
            printf("%c%dx",p->sign,p->coefficient);
            p = p->next;
            continue;
        }
        if(p->exponent==0){
            printf("%c%d",p->sign,p->coefficient);
            p = p->next;
            continue;
        }
        printf("%c%dx^%d",p->sign,p->coefficient,p->exponent);
        p = p->next;
    }
    return 0;
}

/*
#include <stdio.h>
#include <math.h>
void fuhao(int a,char *c){
    if(a>0){
        *c='+';
    } else if(a<0){
        *c='-';
    }
}

int main() {

    int n,j=1,k;
    scanf("%d",&n);
    k=n;
    int a[n+2];
    char c='+';
    for (int i = 1; i <n+2 ; i++) {
        scanf("%d",&a[i]);
    }
    if (n==0){
        printf("%d",a[j]);
        return 0;
    }
    if(n>1){
        while (1){
            if(a[j]==0){
                j++;n--;
                continue;
            }
            if (j==k+3){
                printf("0");
                return 0;
            }
             if(abs(a[j])!=1)printf("%dx^%d",a[j++],n);
             else if (a[j]==1){
                if(n>1) printf("x^%d",n);
                 if (n==1) printf("x");
                 if (n==0)printf("1");
                 j++;
             } else if(a[j]==-1){
                 if(n>1) printf("-x^%d",n);
                 if (n==1) printf("-x");
                 if (n==0)printf("-1");
                 j++;
             }
            break;
        }
    } else if (n==1){
        if (a[1]!=0&&a[1]!=1&&a[1]!=-1){if(a[2]>0){
           printf("%dx+%d",a[1],a[2]);
       }else if(a[2]<0){
           printf("%dx-%d",a[1],a[2]);
       } else if(a[2]==0){
           printf("%dx",a[1]);
       }
        return 0;} else if(a[1]==0){
            printf("%d",a[2]);
            return 0;
        } else if(a[1]==1){
            if(a[2]>0){
                printf("x+%d",a[2]);
            }else if(a[2]<0){
                printf("x-%d",a[2]);
            } else if(a[2]==0){
                printf("x");
            }
            return 0;
        } else if (a[1]==-1){
            if(a[2]>0){
                printf("-x+%d",a[2]);
            }else if(a[2]<0){
                printf("-x%d",a[2]);
            } else if(a[2]==0){
                printf("-x");
            }
            return 0;
        }
    }
    for(int i=n-1;i>=0;i--,j++){
        if(a[j]==0) continue;
        if(i>1){
               fuhao(a[j],&c);
        if(abs(a[j])!=1){
                printf("%c%dx^%d",c,abs(a[j]),i);
           } else if(a[j]==1){
            printf("+x^%d",i);
        } else if(a[j]==-1){
            printf("-x^%d",i);
        }
        } else if(i==0){
            fuhao(a[j],&c);
            printf("%c%d",c,abs(a[j]));
        } else if(i==1){
            if(a[j]!=1&&a[j]!=-1){fuhao(a[j],&c);
            printf("%c%dx",c,abs(a[j]));}
            if(a[j]==1){
                printf("+x");
            }if(a[j]==-1){
                printf("-x");
            }
        }

    }
    return 0;
}

*/