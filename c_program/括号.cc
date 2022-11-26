#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int main (){

}
int match(char *exp){
    int len = strlen(exp);
    int da=0,zhong=0,xiao=0;
    for(int i=0;i<len;i++)
        switch(exp[i]){
            case '(':
                xiao++;break;
            case ')':
                xiao--;  
                break;
            case '[':
                zhong++;break;
            case ']':
                zhong--;
                break;
            case '{':
                da++;break;
            case '}':
                da--;break;
            default:
                break;
        }
        if(da==0 || zhong ==0 || xiao ==0)
            return 1;
        return 0;
}