/*
    给两个非递减排列的整数数组nums1 nums2, 
    另有两个整数m和n分别表示nums1和nums2的元素数目。
*/
#include <iostream>
using namespace std;

// algorithm里的sort，先合并然后在排序

// 双指针，每次都从数组的头部，各取出一个然后比较，将较小的放在结果数组中。

void merge_1(int nums1[],int nums2[],int m, int n){
    int k=m+n;
    int temp[k];
    for(int index = 0,nums1ndex=0,nums2index=0;index<k;index++){
        if(nums1ndex >= m)
            temp[index] = nums2[nums2index++];
        else if(nums2index >= n)
            temp[index] = nums1[nums1ndex++];
        else if(nums1[nums1ndex] < nums2[nums2index])
            temp[index] = nums1[nums1ndex++];
        else
            temp[index] = nums2[nums2index++];
    }
    for(int i=0;i<k;i++)
        nums1[i] = temp[i];
}
// 从结尾数组有效位置结尾开始比较，将大的放于末尾
void merge(int nums1[],int nums2[],int m, int n){
    int k = m+n;
    for(int index = k-1,nums1ndex=m,nums2index=n;index>=0;index--){
        if(nums1ndex<0)
            nums1[index] = nums2[nums2index--];
        else if(nums2index<0)
            nums1[index] = nums1[nums1ndex--];
        else if(nums1[nums1ndex] > nums2[nums2index])
            nums1[index] = nums1[nums1ndex--];
        else
            nums1[index] = nums2[nums2index--];
    }
}