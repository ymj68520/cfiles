/*
    整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。

例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。
更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，
那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。
如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。

给你一个整数数组 nums ，找出 nums 的下一个排列。

必须 原地 修改，只允许使用额外常数空间。

1 <= nums.length <= 100
0 <= nums[i] <= 100


链接：https://leetcode-cn.com/problems/next-permutation
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
inline bool com(const int &a, const int &b){
    return a>b;
}
// 36421 --> 41236
// 从后往前 后面部分子串可以重新排列为比当前大的最小数
void nextPermutation(vector<int>& nums) {
    // 可以重排列的条件
    // 从后往前找 找到一个不满足 nums[i]<nums[i-1] 的位置
    int i;
    for(i=nums.size()-1;i>0;i--){
        if(nums[i]>nums[i-1])
            break;
    }
    // 当前序列最大的处理
    if(i==0){
        sort(nums.begin(),nums.end());
        return;
    }
    // 在子串中找到一个比不满足位置的前一个元素大的最小元素
    int dis = nums[i-1];
    int target = 101;   // MAX = 100
    int index(0);
    for(int j=i;j<nums.size();j++){
        if(nums[j]>dis && nums[j] < target){
            target = nums[j];
            index = j;
        }
    }
    // 交换最小的较大元素后 重新排序
    // nums[i-1] ^= nums[index] ^= nums[i-1] ^= nums[index];
    swap(nums[i-1],nums[index]);
    sort(nums.begin()+i,nums.end());
}

int main(){
    vector<int> t = {3,2,1};
    nextPermutation(t);
    for(vector<int>::iterator i=t.begin();i!=t.end();i++)
        printf("%d ",*i);
    putchar('\n');

    return 0;
}