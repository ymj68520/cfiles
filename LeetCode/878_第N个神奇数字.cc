#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;
using ll = long long;
class Solution {
private:
    const int MOD = 1e9+7;
public:
    // int nthMagicalNumber(int n, int a, int b) {
    //     priority_queue<int,vector<int>,greater<int> > q;
    //     unordered_set<int> s;
    //     q.push(a);q.push(b);
    //     s.insert(a);s.insert(b);
    //     while(n-->1){
    //         int t = q.top();
    //         q.push((t*a)%MOD);
    //         q.push((t*b)%MOD);
    //         q.pop();
    //     }
    //     return q.top();
    // }
    int gcd(int a, int b){
        return b==0?a:gcd(b,a%b);
    }
    int nthMagicalNumber(int n, int a, int b) {
        int c = a*b/gcd(a,b);
        long l=0,r=(long)1e18;
        while(l<r){
            long mid = (l + r) >> 1;
            if(check(mid,a,b,c) >= n)   r = mid;
            else  l = mid + 1;
        }
        return (int)(r%MOD);
    }
    long check(long x,int a,int b, int c){
        return x/a + x/b - x/c;
    }
};
    int gcd(int a, int b){
        return b==0?a:gcd(b,a%b);
    }
    int lcm(int a,int b){
        return a*b/gcd(a,b);
    }
class Solution1 {
public:
    using ll = long long;
    const int mod = 1e9 + 7;

    int nthMagicalNumber(int n, int a, int b) {
        int c = lcm(a, b);
        ll l = 0, r = 1ll * (a + b) * n;
        while (l < r) {
            ll mid = (l + r) >> 1;
            if (mid / a + mid / b - mid / c >= n) r = mid;
            else l = mid + 1;
        }
        return l % mod;
    }
};

int main(){
    Solution sol;
    cout << sol.nthMagicalNumber(5,2,3) << endl;

    for(int i=1;i<20;i++)
        cout << sol.nthMagicalNumber(i,2,3) << " ";
    cout << endl;
}