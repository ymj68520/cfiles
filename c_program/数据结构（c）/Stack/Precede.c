#include "Preceed_stack.h"
#include <stdio.h>

char Precede(SElemType t1,SElemType t2)
{ // 根据教科书表3.1，判断t1， t2两符号的优先关系(′ #′用′ \n′代替)
    char f;
    switch(t2)
    {
        case '+' :
        case '-' :
            if(t1=='(' ||t1=='\n' )
                f='<' ; // t1<t2
            else
                f='>' ; // t1>t2
            break;
        case '*' :
        case '/' :
            if(t1=='*' ||t1=='/' ||t1==')' )
                f='>' ; // t1>t2
            else
                f='<' ; // t1<t2
            break;
        case '(' :
            if(t1==')' )
            {
                printf("括号不匹配\n");
                exit(ERROR);
            }
            else
            f='<' ; // t1<t2
            break;
        case ')' :
            switch(t1)
            {
                case '(':
                    f='=' ; // t1=t2
                    break;
                case '\n' :
                    printf("缺乏左括号\n");
                    exit(ERROR);
                default :f='>' ; // t1>t2
            }
        break;
        case '\n' :
            switch(t1)
            {
                case '\n' :
                    f='='; // t1=t2
                    break;
                case '(' :
                    printf("缺乏右括号\n");
                    exit(ERROR);
                default :f='>' ; // t1>t2
            }//switch
    }//switch
return f;
}//precede
status In(SElemType c)
{ // 判断c是否为7种运算符之一
    switch(c)
    {
        case '+' :
        case '-' :
        case '*' :
        case '/' :
        case '(' :
        case ')' :
        case '\n' :
            return true;
        default :
            return false;
    }
}
SElemType Operate(SElemType a,SElemType theta,SElemType b)
{ // 做四则运算a theta b，返回运算结果
    switch(theta)
    {
        case '+' :return a+b;
        case '-' :return a-b;
        case '*' :return a*b;
    }
    return a/b;  //Arithmetic exception
}

SElemType EvaluateExpression(){
    struct SqStack OPTR,OPND;
    SElemType a,b,c,x;
    InitStack(&OPND);
    InitStack(&OPTR);
    Push(&OPTR,'\n');
    c = getchar();
    GetTop(OPTR,&x);
    while(c!='\n' || x!= '\n'){
        if(In(c))
            switch (Precede(x,c)){
                case '<' :
                    Push(&OPTR,c);
                    c = getchar();
                    break;
                case '>' :
                    Pop(&OPTR,&x);
                    Pop(&OPND,&b);
                    Pop(&OPND,&a);
                    Push(&OPND,Operate(a,x,b));
            }
        else if(c>='0'&&c<='9'){
            Push(&OPND,c-48);
            c = getchar();
        }
        else{
            printf("出现非法字符！\n");
            exit(EXIT_FAILURE);
        }
        GetTop(OPND,&x);
    }
    Pop(&OPND,&x);
    if(!StackEmpty(OPND)){
        puts("表达式不正确！");
        exit(EXIT_FAILURE);
    }

    return x;
}

int main (){
    printf("请输入算术表达式(输入的值要在0～9之间、中间运算值和输出结果在-128～127之间)\n");
    printf("%d\n",EvaluateExpression()); // 返回值(8位二进制， 1个字节)按整型格式输出
}