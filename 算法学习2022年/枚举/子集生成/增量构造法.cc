/* 
 * 在一个没有重复元素的集合中
 * 枚举所有可能的子集
 */
#include <iostream>
using namespace std;

void print_subset(int n, int *A, int cur){
    for(int i=0; i<cur; i++) printf("%d ",A[i]);
    printf("\n");
    int s = cur ? (A[cur-1]+1) : 0;
    for(int i=s; i<n; i++){
        A[cur] = i;
        print_subset(n,A,cur+1);
    }
}

int main(){
    int A[3];
    print_subset(3,A,0);

    return 0;
}