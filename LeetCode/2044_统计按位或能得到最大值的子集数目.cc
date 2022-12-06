#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:

    int count = 0,maxNumber = 0;
    //index代表目前需要判断的数字索引，curNumber代表目前的子集按位或结果
    void backtracking(vector<int>& nums,int index,int curNumber){
        if(curNumber == maxNumber){
            //剩下的元素怎么选择都行
            count += 1 << (nums.size() - index);
            return;
        }
        for(int i = index;i < nums.size();++i){
            backtracking(nums,i+1,curNumber | nums[i]);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        /*回溯（剪枝版本）
            核心点：1.全部元素的按位或结果就是按位或的最大值 2.如果已经可以知道一个子集的按位或结果就是最大值，那么剩下的元素取或者不取都不会影响结果
            我们考虑把二叉树回溯改成多叉树回溯，并且因为数值更大的元素更有可能对按位或最大值有更大的贡献，我们考虑把nums数组降序排列
        */
        for(int& num : nums){
            maxNumber |= num;
        }
        sort(nums.begin(),nums.end(),greater<int>());
        backtracking(nums,0,0);
        return count;
    }
};
