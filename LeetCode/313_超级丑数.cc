#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<unsigned int,vector<unsigned int>,greater<unsigned int> > q;
        // set<unsigned int> s;s.insert(1);
        q.push(1);
        while(n-- > 0){
            int t = q.top();
            q.pop();
            if(n==0)    return t;
            for(auto & p:primes){
                if(p<=__INT_MAX__/t)    q.push(p*t);
                if(t%p == 0)    break;
                // s.insert(p*t);
            }
        }
        return q.top();
    }
    int nthSuperUglyNumber2(int n, vector<int>& primes) {
        vector<int> dp(n+1);
        dp[1] = 1;
        int m = primes.size();
        vector<int> nums(m);
        vector<int> pointers(m,1);
        for(int i=2;i<=n;i++){
            int minn = __INT_MAX__;
            for(int j=0;j<m;j++){
                nums[j] = dp[pointers[j] * primes[j]];
                minn = min(minn,nums[j]);
            }
            dp[i] = minn;
            for(int j=0;j<m;j++)    if(minn == nums[j])
                pointers[j]++;
        }
        return dp[n];
    }
};

int main(){
    vector<int> prime = {7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};
    int n = 1000;
    Solution sol;
    cout << sol.nthSuperUglyNumber(n,prime) << endl;
    cout << sol.nthSuperUglyNumber2(n,prime) << endl;
    return 0;
}