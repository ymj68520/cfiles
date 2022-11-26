#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Sstring.h"

// 一般方法，处理一般字符为O(m+n)，然而处理01串为O(n*m)
//  串的首位置存储串长
int Index_S (SString S,SString T,int pos){
    int i,j;
    i = pos;
    j=1;
    while(i<= S[0] && j <= T[0]){
        if(S[i] == T[i]){
            ++i;    // 继续比较后继
            ++j;
        }
        else{
            i = i-j+2;  // 指针后退重新开始匹配,指针后退至前一次的pos+1
            j = 1;      // +2 -> j 从1开始，i-j为前一次pos的前一个位置
        }
    }
    if(j>T[0])
        return i-T[0];
    else 
        return 0;
}// Index
// 一般方法缺点在于每次都需要回溯指针i，在串相同的字符较多时，效率低

// 改进：(KMP 克努特——莫里斯——普拉特算法)
// 算法：
//     假设主串为S[i]，模式串为P[j]
//   一次匹配之后，设第j个字符匹配失败
//   则一定会有如下关系式：
//      P[1]P[2]...P[K-1] = S[i-k+1]S[i-k+2]...S[i-1]
//   部分匹配结果为：
//      P[j-K+1]P[j-K+2]...P[j-1] = S[i-k+1]S[i-k+2]...S[i-1]
//   联立上式，消去主串，得到：
//      P[1]P[2]...P[K-1] = P[j-K+1]P[j-K+2]...P[j-1]

//   即为，主串中第i位于模式串中第k(k<j)位对齐，

//   即，匹配仅需从模式串中第k个字符和主串中第i个字符比较起继续进行。
//   
//   为了确定K，需要一个next(){next(j)=k}来存储模式串的每一个字符对应的K
//   define next():
//      令next[j]=k，则next[j]表明当前模式中第j个字符与主串中相应字符“失配”时
//      在模式中需重新和主串中该字符进行比较的字符的位置。


//   next[j] = 
//      if(j==1)    0
//      else if(Max{K|1<k<j && p[1]...p[k-1]=p[j-k+1]...p[j-1]}) // Max集合非空
//                  Max{K|1<k<j && p[1]...p[k-1]=p[j-k+1]...p[j-1]  // 赋值
//      else        1       // 其他情况
//   





// 求模式串T的next函数值并存入数组next。
void get_next(SString T,int next[]){
    int i=1,j=0;
    next[1] = 0;
    while(i<T[0])
        if(j==0 || T[i]==T[j]){
            ++i;
            ++j;
            next[i] = j;
        }
        else
        j = next[j];
}
// 求模式串T的next函数修正值并存入数组nextval。
void get_nextval(SString T,int nextval[]){
    int i=1;
    int j=0;
    nextval[1] = 0;
    while(i<T[0])
        if(j == 0 || T[i] == T[j]){
            ++i;
            ++j;
            if(T[i]!=T[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        }
        else
            j = nextval[j];
}
// KMP 匹配
// 其中， T非空， 1≤pos≤StrLength(S)。
int Index_KMP(SString S,SString T,int pos,int next[]){
    int i=pos,j=1;
    while(i<=S[0] && j<=T[0])
        if(j==0 || S[i]==T[j]){     //继续比较后继
            ++i;
            ++j;
        }
        else{   //串向右滑动
            j = next[j];
        }
        if(j>T[0])  // 匹配成功
            return i-T[0];
        else
            return 0;

}   

void main(){
    int i,*p;
    SString s1,s2; 
    StrAssign(s1,"aaabaaaab");
    printf("主串为");
    StrPrint(s1);
    StrAssign(s2,"aaaab");
    printf("子串为");
    StrPrint(s2);
    p=(int*)malloc((StrLength(s2)+1)*sizeof(int)); // 生成s2的next数组空间
    get_next(s2,p); // 求得next数组，存于p中
    printf("子串的next数组为");
    for(i=1;i<=StrLength(s2);i++)
        printf("%d ",*(p+i));
    printf("\n");
    i=Index_KMP(s1,s2,1,p); // 求串s2在s1中首次匹配的位置i
    if(i)
        printf("主串和子串在第%d个字符处首次匹配\n",i);
    else
        printf("主串和子串匹配不成功\n");
    get_nextval(s2,p); // 利用算法4.8，求得next数组，存于p中
    printf("子串的nextval数组为");
    for(i=1;i<=StrLength(s2);i++)
        printf("%d ",*(p+i));
    printf("\n");
    printf("主串和子串在第%d个字符处首次匹配\n",Index_KMP(s1,s2,1,p));
}


