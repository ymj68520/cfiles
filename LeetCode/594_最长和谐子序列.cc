#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(const auto &x : nums)   mp[x]++;
        int ans = 0;
        for(const auto & [x,y] : mp){
            if(mp.count(x+1))   ans = max(ans,y+mp[x+1]);
        }
        return ans;
    }
};
//排序+滑动窗口
//枚举数组中的每一个元素，对于当前枚举的元素 i，它可以和 i + 1 组成和谐子序列。


class Solution {
public:
    int findLHS(vector<int>& nums) {
	// 对数组进行排序,检查相邻两个子序列的元素的之差是否为 1
	sort(nums.begin(), nums.end());
	// 使用双指针begin和end进行扫描
	int begin = 0;//第一个连续相同元素的子序列的第一个元素
    int end = 0;//第二个连续相同元素的子序列的末尾元素
	// 将长度保存至result
	int result = 0;
	for (end = 0; end < nums.size(); end++) {
        //不满足差为一
		while (nums[end] - nums[begin] > 1) {
			begin++;
		}
        //满足差为一
		if (nums[end] - nums[begin] == 1) {
			// 当前的和谐子序列的长度为end−begin+1
			result = max(result, end - begin + 1);
		}
	}
	return result;

    }
};