#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution1 {
    int gcd(int a, int b){
        return b==0 ? a : gcd(b,a%b);
    }
    template <typename T>
    struct triple{
        T i,j,gcd;
        triple(int _i, int _j, int _gcd){
            i=_i;
            j=_j;
            gcd=_gcd;
        }
        bool operator < (triple t){
            return gcd > t.gcd;
        }
    };
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<triple<int> > pairs;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pairs.push_back({i,j,gcd(nums[i],nums[j])});
            }
        }
        
        sort(pairs.begin(),pairs.end());
        vector<bool> vis(n,1);
        n/=2;
        int ans=0;
        for(const auto &p : pairs){
            if(n && vis[p.i] && vis[p.j]){
                ans += n * p.gcd;
                vis[p.i] = 0;
                vis[p.j] = 0;
                n--;
            }
        }
        return ans;
    }
};

class Solution {
    int n;
    vector<int> dp;
    vector<vector<int>> gcds;
    int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
    int dfs(int x, int mask, int sum, vector<int>& nums) { 
        if (x == n / 2 + 1) return sum;
        if (dp[mask] > 0) return sum + dp[mask]; // // sum为已经选取的数获得的分数 + 未选取的数能够获得的最大分数
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (((1 << i) & mask) == 0) continue;
            for (int j = i + 1; j < n; j++) {
                if (((1 << j) & mask) == 0) continue;
                int next = mask ^ (1 << i) ^ (1 << j); 
                ans = max(ans, dfs(x + 1,  next, sum + x * gcds[i][j], nums));
            }
        }
        dp[mask] = ans - sum; //ans为能够获得的总分数 减去sum后才是maks状态获得的最大分数
        return ans;
    }
public:
    int maxScore(vector<int>& nums) {
        n = nums.size();
        dp.resize(1 << n, 0);
        gcds.resize(n, vector<int>(n, 0)); 
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) gcds[i][j]= gcd(nums[i], nums[j]);
        }
        return dfs(1, (1 << n) - 1, 0, nums);
    }
    
};


int main(){
    vector<int> ans = {415,230,471,705,902,87};
    Solution sol;
    cout << sol.maxScore(ans) << endl;

    return 0;
}
