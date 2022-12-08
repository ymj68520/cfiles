#include <iostream>
#include <vector>
#include <cstring>
#include <numeric>
#include <algorithm>

using namespace std;

const int X = 1e5;
int prime[10000],prp=0, d[X+1], dv[X+1], r[X+1], rk[X+1],maxrk;
int _ = []{
    for(int i=2;i<=X;++i){
        if(d[i]==0)
            d[i] = dv[i] = prime[prp++] = i;
        for(int j=0;j<prp&&prime[j]*i<=X;++j){
            d[prime[j]*i] = prime[j];
            dv[prime[j]*i] = (d[i]==prime[j])?(d[i]*dv[i]) : prime[j];
            if(i*prime[j] == 0) break;
        }
    }
    return 0;
}();

class Solution {
private:
    int find(int x){
        return r[x] == x? x : (r[x] = find(r[x]));
    }
    void unite(int x, int y){
        int a = find(x), b = find(y);
        if(a == b)  return;
        if(rk[a] < rk[b])   swap(a,b);
        r[b] = a;
        rk[a] += rk[b];
        maxrk = max(maxrk,rk[a]);
    }
public:
    int largestComponentSize(vector<int>& nums){
        int e = ( *max_element(nums.begin(),nums.end()) ) + 1;
        iota(r,r+e,0);
        memset(rk,0,sizeof(int)*e);
        maxrk = 1;
        for(const int &x : nums)  rk[x] = 1;
        for(const int &y : nums){
            int t = y;
            while(t>1){
                unite(y,d[t]);
                t/=dv[t];
            }
        }
        return maxrk;
    }
};