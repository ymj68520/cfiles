/*
    给一个数组，将所有0移动到数组末尾，保持其余元素位置不变。
    空间复杂度只能为O(n)即不能使用辅助数组
*/

#include <iostream>
using namespace std;

// 双指针
void movezero(int nums[],int numsSize){
    if(nums == NULL || numsSize == 0)
        return;
    int j=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=0)
            nums[j++] = nums[i];
    }
    for(int i=j;i<numsSize;i++)
        nums[i] = 0;
}
// 
void movezero_1(int nums[], int numsSize){
    if(nums == NULL || numsSize == 0)
        return;
    int j=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] != 0){
            if(i != j){
                nums[j] = nums[i];
                nums[i] = 0;
            }
            j++;
        }
    }
}