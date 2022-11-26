#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n<1) return 0;
    int dp[n+1];memset(dp,0,sizeof(dp));
    dp[0] = 1;
    sort(nums.begin(),nums.end());
    int maxl =1;
    for(int i=1;i<n;i++){
        if(nums[i] == nums[i-1]+1)
            dp[i] = dp[i-1] + 1;
        else if(nums[i] == nums[i-1])
            dp[i] = dp[i-1];
        else
            dp[i] = 1;
        maxl = max(maxl,dp[i]);
    }
    return maxl;
}
vector<int> parent;
int findp(int x){
    return parent[x]==x? x : parent[x] = findp(parent[x]);
}
void mergep(int x, int y){
    x = findp(x);
    y = findp(y);
    if(x!=y) parent[x] = y;
}
int longestConsecutive2(vector<int>& nums){
    // 并查集
    int n = nums.size();
    if(n<1) return 0;
    parent.resize(n);
    for(int i=0;i<n;i++)    parent[i] = i;
    // sort(nums.begin(),nums.end());
    for(int i=0;i<n-1;i++) if(nums[i]<nums[i+1])
        mergep(i,i+1);
    // 转换N叉树
    for(int i=0;i<n;i++) findp(i);
    int ans=0;
    map<int,int> pmap;
    for(int i=0;i<n;i++){
        pmap[parent[i]]++;
        if(ans < pmap[parent[i]]) ans = pmap[parent[i]];
    }
    return ans;
}

int main(){
    vector<int> nums = {0,0,0,3,7,2,5,8,4,6,0,1};
    cout << longestConsecutive(nums) << endl << longestConsecutive2(nums) <<endl;
    return 0;
}