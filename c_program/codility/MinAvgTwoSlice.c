#include <stdio.h>

int solution(int A[],int N);

int main () {
    int A[] = {4,2,2,5,1,5,8};
    register int t = solution(A,7);
    printf("%d\n",t);

    return 0;
}
/*
    对于一组数字的子列的均值问题，所有子列都可以拆分为长度为2或3的子列
    因此，子列单元为2或3长度的子列。
    证明：假定存在一个大于３个数的平均数是最小的平均数。假定是４个数的平均数。即：
    (a+b+c+d)/4 ≦(a+b)/2 并且　(a+b+c+d)/4 ≦(c+d)/2 ，
    但是(a+b+c+d)/4　＝　((a+b)/2 +(c+d)/2)/2 。
    也就是说　４个数的平均数　也就是分别两个平均数的平均数，根据平均数的定义可知，
    ４个数的平均数如果小于其中一个平均数，那么肯定大于另一个。
    也就是说，４个数的平均数最小的情况　就是和两个平均数分别相等。
    不可能小于其中任何一个。
    三个长度子列证明类似。
*/
int solution (int A[], int N){
    double min = (A[0]+A[1])/2;
    double temp2=0;
    double temp3=0;
    int i;
    int result=0;
    for(i=1;i+2<N;++i){
        temp2 = (A[i]+A[i+1])/2;
        if(temp2<min){
            min = temp2;
            result = i;
        }
        
        temp3 = (A[i]+A[i+1]+A[i+2])/3;
        if(temp3<min){
            min = temp3;
            result = i;
        }
    }
    return result;
}