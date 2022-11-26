#include <stdio.h>

void tobinary(int,int *);
int solution(int N);

int main (){
    int de;
    int n;
    scanf("%d",&n);
    de = solution(n);
    printf("%d",de);
    return 0;
}
void tobinary(int N,int *de){
    int i=0;
    int temp=N;
    while(temp>0){
        de[i] = temp%2;
        ++i;
        temp /=2;
    }
}
int solution(int N){
    int maxgap;             //最大间隔
    int source[100];        //目标数字的二进制存储器
    int i=0;                //初始化数组，使其与二进制数区别
    while(i<100){                 //非0,1
        source[i] = 2;
        i++;
    }
    tobinary(N,source);     //转换为二进制，倒序存储
    i = 0;                  //计数器——source
    while(*(source+i)!=1)   //清理二进制数末尾零
        i++;                //增加计数器，定位至第一个1
    
    int gaps[100]={0};          //存贮所有gap
    int j=0;                //计数器——sizeof（gap）
    while(*(source+i)!=2){   //遍历一遍数组，完成查找
        if(*(source+i)==1) //清理重复为1的位
        {    
            i++;
            continue;
        }
        
        while(source[i]==0){//每一个0使数组某一位加一
            gaps[j]++;
            i++;
        }
        j++;                 //定位至gaps下一个位置
    }
    //寻找最大gap
    maxgap = gaps[0];        //初始赋值
    for(i=0;gaps[i]!=0;i++){ //遍历查找
        if(gaps[i]>maxgap)   //比较赋值
            maxgap = gaps[i];//赋值
    }
    return maxgap;
}