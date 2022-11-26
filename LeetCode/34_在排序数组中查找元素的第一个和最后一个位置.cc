#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int bsearch(vector<int> &nums, int target){
    int l=0,r=nums.size();
    while(l<r){
        int mid = (l+r)/2;
        if(nums[mid]>=target)   // 确保这个位置是大于等于target的第一个位置
            r = mid;
        else
            l = mid+1;
    }
    return l;
}

vector<int> searchRange(vector<int>& nums, int target) {
    // 寻找大于*等于*target的第一个位置
    int pos1 = bsearch(nums,target); 
    // 寻找大于 target 的第一个位置
    int pos2 = bsearch(nums,target+1);
    // 如果找不到（数组整体小，或者找到的那个起始位置不等于target
    if(pos1 == nums.size()||nums[pos1] != target)
        return vector<int> {-1, -1};
    // 因为pos2是大于target的第一个位置，因此需要减一
    // 当到达这里时，确保存在一个值等于target，所以pos2-1即可。
    return vector<int> {pos1,pos2-1};
}
