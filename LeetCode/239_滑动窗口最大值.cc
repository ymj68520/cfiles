#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int curMax = INT_MIN;
        int curPos=0;
        for(int i=0;i<k;i++)
            if(curMax < nums[i]){
                curMax = nums[i];
                curPos = i;
            }
        ans.push_back(curMax);
        for(int j=k;j<nums.size();++j){
            if(curMax<nums[j]){
                curMax = nums[j];
                ans.push_back(curMax);
                curPos = j;
            }
            else if(curPos == j-k){
                curMax = INT_MIN;
                for(int l=curPos+1;l<=j;l++){
                    if(curMax < nums[l]){
                        curMax = nums[l];
                        curPos = l;
                    }
                }
                ans.push_back(curMax);
            }
            else
                ans.push_back(curMax);
        }
        return ans;
    }
    vector<int> maxSlidingWindow_q(vector<int>& nums, int k){
        if(nums.size() == 1)    return nums;
        deque<int> q;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(!q.empty() && q.front() == i-k)
                q.pop_front();
            while(!q.empty() && nums[i]>nums[q.back()])
                q.pop_back();
            q.push_back(i);
            if(i>=k-1)  ans.push_back(nums[q.front()]);            
        }
        return ans;
    }
};
int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution sol;
    vector<int> ans;
    ans = sol.maxSlidingWindow(nums,k);
    for(auto x:ans) cout << x << " ";
    cout << endl;
    ans = sol.maxSlidingWindow_q(nums,k);
    for(auto x:ans) cout << x << " ";
    cout << endl;
    return 0;
}