#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
    const int MOD = 1e9+7;
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),pow2[n];
        pow2[0] = 1;
        for(int i=1;i<n;++i){
            pow2[i] = pow2[i-1]*2 % MOD;
        }
        long ans = 0l;
        for(int i=0;i<n; ++i)
            ans += long(pow2[i]-pow2[n-1-i]) * nums[i];
        return (ans%MOD + MOD) % MOD;
    }
};

class Solution1 {
private:
    const int MOD = 1e9+7;
    unordered_set<int> s;
    vector<vector<int> > ans;
    void dfs(const vector<int>&nums,int len,int start, vector<int>&path){
        if(len==0){
            ans.push_back(path);
            return;
        }
        if(start+len > nums.size())  return;
        for(int i=0;i<nums.size()&&start+i<nums.size();++i){
            if(s.count(start+i))  continue;
            path.push_back(nums[start+i]);
            s.insert(start+i);
            dfs(nums,len-1,start+i,path);
            path.pop_back();
            s.erase(start+i);
        }

    }
public:
    int sumSubseqWidths(vector<int>& nums) {
        ans.clear();
        s.clear();
        int n = nums.size();
        vector<int> path;
        for(int i=1;i<=n;i++){
            dfs(nums,i,0,path);
        }
        int sums=0;
        int maxdiff=0;
        for(const auto &x:ans){
            if(x.size()==1) continue;
            if(x.size()==2){
                sums += abs(x[0]-x[1]) % MOD;
                sums %= MOD;
                continue;
            }
            int small = INT_MAX;
            int large = INT_MIN;
            for(const auto & y:x){
                small = min(small,y);
                large = max(large,y);
            }
            sums += (large-small) % MOD;
            sums %= MOD; 
        }


        return sums;
    }
};

int main(){
    vector<int> nums = {21,12,8,21,11,35,36,10,30,29,28,1,24,23,36,30,38,17,14,37};
    Solution sol;
    Solution1 sol1;
    // vector<vector<int>> ans = sol.sumSubseqWidths(nums);

    // for(auto &x:ans){
    //     for(auto &y:x)   cout << y;
    //     cout << endl;
    // }

    cout << sol1.sumSubseqWidths(nums) << endl;
    cout << sol.sumSubseqWidths(nums) << endl;

    return 0;
}