#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

// 超时
int shortestSubarray_BAOLI(vector<int>& nums, int k) {
    int n = nums.size();
    if(n==1)    return nums[0]>=k ? 1 : -1;

    int minlen = INT_MAX;
    for(int i=0;i<n;i++){
        int i_jsum=0;
        for(int j=i;j<n;j++){
            i_jsum += nums[j];
            if(i_jsum >= k){
                minlen = min(minlen, j-i+1);
                break;
            }
        }
    }
    if(minlen == INT_MAX)
        minlen = -1;

    return minlen;
}
int shortestSubarray1(vector<int>& nums, int k){
    int n = nums.size();
    int ans = n+1;
    long sums[n+1];
    sums[0] = 0l;
    for(int i=0;i<n;i++)    sums[i+1] = sums[i]+nums[i];
    deque<int> q;
    for(int i=0;i<=n;i++){
        long cur_s = sums[i];
        // 当s[i] - s[j] >= k时，j这个位置有可能作为答案的左端点，
        // 但是也有可能后面会有更小的，所以记录当前这个值，
        // 并且将s[j]弹出队列
        while(!q.empty() && cur_s - sums[q.front()] >= k){
            ans = min(ans,i-q.front());
            q.pop_front();
        }
        // 当是s[i] <= s[j]时，假如i的后面有数字k满足s[k]-s[j]>=k
        // 那么一定有s[k]-s[i]>=k，即s[j]无用了，可以删除
        while(!q.empty() && sums[q.back()]>=cur_s){
            q.pop_back();
        }
        q.push_back(i);
    }
    return ans > n ? -1 : ans;
}


int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8};
    int k = 9;
    cout << shortestSubarray_BAOLI(nums,k) << endl;
    cout << shortestSubarray1(nums,k) << endl;
    return 0;
}