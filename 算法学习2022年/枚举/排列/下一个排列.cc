#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,p[10];
    scanf("%d",&n);
    for(int i=0; i<n; i++)  scanf("%d",p+i);
    sort(p,p+n);
    do{
        for(int i=0; i<n; i++)  printf("%d ",p[i]);
        printf("\n");
    }while(next_permutation(p,p+n));    // 起始位及结束位
    return 0;
}

// next_permutation实现：
bool my_next_permutation(int n, int a[]){
    int k = n;
    while(a[k-1] > a[k])
	    k--;
    int t = k;
    while(a[t+1] > a[k-1])
	    t++;
    swap(a[k-1],a[t]);
    reverse(a+k,a+n+1);
}
/*
 * ①从后往前找原数组中第一个a[i] < a[i+1]的地方，其后面全是降序，说明已经排好了，
 * 所以我们就要将a[i]的值改大一点。
 * ②将a[i]和其后面所有数中大于他的最小的数交换位置，则a[i]后面的数仍是个降序。
 * ③然后将其后面这些降序的元素翻转，就得到了原排列的下一个增序排列了。
 * 例如：对于排列2431来说，①我们先找到2和4处，然后交换2和3的位置，就得到了3421；
 * 然后翻转421，就得到了3124，则3124就是2431的下一个排列
 */