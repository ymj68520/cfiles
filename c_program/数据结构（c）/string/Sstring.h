//定长顺序储存
#include <string.h>

extern int printf(const char *__restrict__ __format, ...);

#define MAX_STR_LEN 40 // 用户可在255(1个字节)以内定义最大串长

typedef char SString[MAX_STR_LEN+1]; // 0号单元存放串的长度
typedef bool Status;

#define OK true
#define ERROR false
#define FALSE false
#define OVERFLOW 1

#define DestroyString ClearString // DestroyString()与ClearString()作用相同
//  生成一个其值等于chars的串T
Status StrAssign (SString T,char *chars){
//  串的首位置存储串长
    int i;
    if(strlen(chars)>MAX_STR_LEN)
        return ERROR;
    else{
        T[0] = strlen(chars);
        for(i=1; i<T[0]; ++i){
            T[i] = *(chars+i-1);
        }
        return OK;
    }
}
 //由串S，复制得串T
void StrCopy (SString T, SString S){
    for(int i=1; i<=S[0]; ++i){
        T[i] = S[i];
    }
}
// 若S为空串，则返回TRUE；否则返回FALSE
Status StrEmpty (SString T){
    if(T[0] == 0)
        return OK;
    else 
        return FALSE;
}
// 初始条件：串S和T存在。操作结果：若S>T，则返回值>0；若S=T，则返回值=0；若S<T，则返回值<0
int StrCompare (SString S, SString T){
    for(int i=1; i<=S[0] && i<=T[0]; ++i){
        if(S[i] != T[i]){
            return S[i]-T[i];
        }
    }    
}
// 返回串S的元素个数
int StrLength (SString S){
    return S[0];
}
// 初始条件：串S存在。操作结果：将S清为空串
void ClearString (SString S){
    S[0] = 0;
}
// 用T返回S1和S2联接而成的新串。若未截断，则返回TRUE；否则返回FALSE
Status Concat (SString T, SString S1, SString S2){
    int i;
    if(S1[0]+S2[0]<=MAX_STR_LEN){
        //未截断
        for(i=1;i<S1[0];++i)
            T[i] = S1[i];
        for(i=1;i<S2[0];++i)
            T[S1[0]+i] = S2[i];
        T[0] = S1[0] + S2[0];
        return OK;
    }
    else{
        //截断S2
        for(i=1;i<S1[0];++i)
            T[i] = S1[i];
        for(i=1;i<MAX_STR_LEN;++i)
            T[S1[0]+i] = S2[i];
        T[0] = MAX_STR_LEN;
        return FALSE;
    }
}
// 用Sub返回串S的自第pos个字符起长度为len的子串。
Status SubString(SString Sub, SString S, int pos, int len){
    int i;
    if(pos<1 || pos>S[0] || len<0 || len>S[0]-pos+1)
        return ERROR;
    for(i=1;i<=len;++i){
        Sub[i] = S[pos+i-1];
    }
    Sub[0] = len;
    return OK;
}
// 返回子串T在主串S中第pos个字符之后的位置.若不存在,则函数值为0其中,T非空,1≤pos≤StrLength(S)。
int Index (SString S, SString T, int pos){
    int i,j;
    if(1<=pos && pos <=S[0]){
        i = pos;
        j = 1;
        while (i<=S[0] && j<=T[0]){
            if(S[i]==T[j]){ // 继续比较
                ++i;
                ++j;
            }
            else{  //指针后退，重新匹配
                i = i-j+2;
                j = 1;
            }
        }
        if(j > T[0]){
            return i-T[0];
        }
        else
            return 0;

    }//if
    else
        return 0;
}
// 初始条件：串S和T存在， 1≤pos≤StrLength(S)+1
// 操作结果：在串S的第pos个字符之前插入串T。完全插入返回TRUE，部分插入返回FALSE
Status StrInsert(SString S,int pos,SString T){
    int i;
    if(pos<1||pos>S[0]+1)
    return ERROR;
    if(S[0]+T[0]<=MAX_STR_LEN){ 
        // 完全插入
        for(i=S[0];i>=pos;i--)
            S[i+T[0]]=S[i];
    for(i=pos;i<pos+T[0];i++)
        S[i]=T[i-pos+1];
    S[0]+=T[0];
    return OK;
    }
    else{
        //部分插入
        for(i=MAX_STR_LEN;i>=pos+T[0];i--)
            S[i]=S[i-T[0]];
        for(i=pos;i<pos+T[0]&&i<=MAX_STR_LEN;i++)
            S[i]=T[i-pos+1];
        S[0]=MAX_STR_LEN;
        return FALSE;
    }
}
// 初始条件：串S存在， 1≤pos≤StrLength(S)-len+1
// 操作结果：从串S中删除自第pos个字符起长度为len的子串
Status StrDelete(SString S,int pos,int len){
    int i;
    if(pos<1||pos>S[0]-len+1||len<0)
        return ERROR;
    for(i=pos+len;i<=S[0];i++)
        S[i-len]=S[i];
    S[0]-=len;
    return OK;
}
// 初始条件：串S， T和V存在， T是非空串
// 操作结果：用V替换主串S中出现的所有与T相等的不重叠的子串
Status Replace(SString S,SString T,SString V){
    //此函数与串的存储结构无关
    int i=1; // 从串S的第一个字符起查找串T
    Status k;
    if(StrEmpty(T)) // T是空串
        return ERROR;
    do{
        i=Index(S,T,i); // 结果i为从上一个i之后找到的子串T的位置
        if(i){          // 串S中存在串T
            StrDelete(S,i,StrLength(T)); // 删除该串T
            k=StrInsert(S,i,V); // 在原串T的位置插入串V
            if(!k) // 不能完全插入
                return ERROR;
            i+=StrLength(V); // 在插入的串V后面继续查找串T
        }
    }while(i);
    return OK;
}
// 输出字符串T。另加换行
void StrPrint(SString T){
    int i;
    for(i=1;i<=T[0];i++)
        printf("%c",T[i]);
    printf("\n");
}