#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool cmp(int a,int b){
        return !((a<0)^(b<0));
    }
    void trans(vector<int>& arr, int left, int right){
        while(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
public:
    vector<int> rearrangeArray3(vector<int>& nums){
        int step = 1; // step表示子数组的长度
        while(step < (int)nums.size()){
            step *= 2;
            for(int i = 0; i < nums.size(); i += step){
                // 待排序子数组为 [i, i + step) 或 [i, nums.size())
                // 一分为 2 ，左子数组为 [i, i + step / 2) 右子数组为[i + step / 2, i + step)
                // 归并过程也很简单，用三次翻转

                // 当右子数组没有内容时，直接返回
                if(i + step / 2 >= nums.size()) break;

                // 分别寻找左子数组第一个负数，及右子树组最后一个正数索引
                int left, right;
                for(left = i; left < i + step / 2; left++){
                    if(nums[left] < 0){
                        break;
                    } 
                }
                for(right = min(i + step, (int)nums.size()) - 1; right >= i + step / 2; right--){
                    if(nums[right] > 0){
                        break;
                    }
                }
                // 三次翻转
                trans(nums, left, i + step / 2 - 1);
                trans(nums, i + step / 2, right);
                trans(nums, left, right);
            }
        }
        return nums;
    }
    vector<int> rearrangeArray2(vector<int>& nums){
        vector<int>v(nums.size());
        int a=0,b=1;
        for (int i:nums)
        {
            if (i>0)
            {
                v[a]=i;
                a+=2;
            }
            else
            {
                v[b]=i;
                b+=2;
            }
        }
        return v;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        int posCur=0,posNex=posCur+1;
        int n = nums.size();
        if(n==2) return nums;
        while(posCur < n){
            if(cmp(nums[posCur],nums[posNex])){
                posNex++;
                while(cmp(nums[posCur],nums[posNex]))   posNex++;
                int t = nums[posNex];
                nums.erase(nums.begin() + posNex);
                nums.insert(nums.begin()+posCur+1,t);
            }else
                posCur ++;
            posNex = posCur + 1;
        }
        return nums;
    }
};

int main(){
    vector<int> nums = {1,2,3,-1,-2,-3};
    Solution sol;
    vector<int> ans = sol.rearrangeArray(nums);
    for(auto&x:ans)    cout << x << " ";
    cout <<endl;
    ans = sol.rearrangeArray2(nums);
    for(auto&x:ans) cout << x << " ";
    cout << endl;
    return 0;
}