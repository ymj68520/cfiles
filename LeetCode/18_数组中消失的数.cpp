/* 
    给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。
    请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
    
    n == nums.length    
    1 <= n <= 105
    1 <= nums[i] <= n
    
    进阶：你能在不使用额外空间且时间复杂度为 O(n) 的情况下解决这个问题吗? 你可以假定返回的数组不算在额外空间内。

*/

#include <iostream>
#include <vector>
using namespace std;
// 遍历一遍数组 将每一位存的数据对应的位置的数据进行修改（变负）最后为正数的位置即为缺失的位置
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result;
    for(int i=0;i<nums.size();i++){
        int target;
        if(nums[i]>0)
            target = nums[i]-1;
        else
            target = -nums[i]-1;
        
        if(nums[target]>0)   
            nums[target] = 0-nums[target];
    }
    for(int i=0;i<nums.size();i++)
        if(nums[i]>0)
            result.push_back(i+1);
    return result;
}

int main(){
    vector<int> temp = {4,3,2,7,8,2,3,1};
    temp = findDisappearedNumbers(temp);

    for(vector<int>::iterator i=temp.begin();i!=temp.end();i++)
        cout << *i << ' ';
    cout << endl;

    return 0;
}