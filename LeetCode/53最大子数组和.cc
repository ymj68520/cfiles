#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray1(vector<int>& nums) {
    int n = nums.size();
    if(n==1)    return nums[0];
    int S[n+1];S[0]=0;
    int ans=nums[0];
    for(int i=1;i<=n;i++) S[i] = S[i-1] + nums[i];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            ans = max(ans,S[j]-S[i-1]);
    return ans;
}
int maxsum(vector<int>& A, int x, int y){
    if(y-x==1)  return A[x];
    int m = x+(y-x)/2;
    int maxs = max(maxsum(A,x,m),maxsum(A,m,y));
    int v,L,R;
    v=0; L=A[m-1];
    for(int i=m-1; i>=x; i--)   L=max(L, v+=A[i]);
    v=0; R=A[m];
    for(int i=m; i<y; i++)  R = max(R, v+=A[i]);
    return max(maxs, L+R);
}
int maxSubArray2(vector<int>& nums){
    return maxsum(nums,0,nums.size());
}
int main(){
    vector<int> nums = {1,-1,4,9,-2,-11};
    cout << maxSubArray1(nums) << endl;
    cout << maxSubArray2(nums) << endl;
    return 0;
}