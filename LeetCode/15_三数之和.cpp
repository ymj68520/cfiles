// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
// 使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。
// 0 <= nums.length <= 3000
// -10^5 <= nums[i] <= 10^5

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
// 以下是buffer溢出版本。。
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> > result;
    if(nums.size() < 3)
        return result;

    // 固定三元组第一个元素 剩下两个元素随后使用映射寻找
    // 首先排序
    sort(nums.begin(),nums.end());
    // 固定第一个元素 查找后面的元素
    for(int i=0;i<nums.size()-2;i++){
        // 如果第一个元素都大于0 后面就不可能存在两个正数的和为负数
        if(nums[i]>0)
            break;
        int j=i+1,k=nums.size()-1;
        while(j<k){
            long long x = static_cast<long long>(nums[i]);
            long long y = static_cast<long long>(nums[j]);
            long long z = static_cast<long long>(nums[k]);
            if(x+y+z>0)
                k--;
            else if(x+y+z<0)
                j++;
            else{
                result.push_back({nums[i],nums[j],nums[k]});
                while(j<k && nums[j]==nums[j+1])
                    j++;
                while(j<k && nums[k-1]==nums[k])
                    k--;
                j++;k--;
            }
        }
        while(nums[i]==nums[i+1])
            i++;
    }
    return result;
}
// 别人的解法，没有溢出
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        sort(nums.begin(), nums.end());
        if(nums[0]>0) return ans;
        int i = 0;
        while(i<nums.size()){
            if(nums[i]>0) break;        // 1楼网友指正，将这个if语句放这里提前终止循环
            int left = i+1, right = nums.size()-1;
            while(left< right){
               
                // 转换为long long避免加法过程中溢出
                long long y = static_cast<long long>(nums[i]);
                long long x = static_cast<long long>(nums[left]);
                long long z = static_cast<long long>(nums[right]);
                if(x + y >0-z)
                    right--;
                else if(x + y <0-z)
                    left++;
                else{
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // 相同的left和right不应该再次出现，因此跳过
                    while(left<right&&nums[left]==nums[left+1])
                        left++;
                    while(left<right&&nums[right] == nums[right-1])
                        right--;
                    left++;
                    right--;
                }
            }
            // 避免nums[i]作为第一个数重复出现
            while(i+1<nums.size()&&nums[i] == nums[i+1])
                i++;
            i++;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int> > temp = threeSum(nums);

    for(vector<vector<int> >::iterator i=temp.begin();i!=temp.end();i++){
        for(vector<int>::iterator j=(*i).begin();j!=(*i).end();j++)
            cout << *j << " ";
        cout << endl;
    }
    
    return 0;
}