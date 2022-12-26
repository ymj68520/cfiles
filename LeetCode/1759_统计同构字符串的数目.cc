#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
    const int MOD = 1e9+7;
public:
    int countHomogenous(string s) {
        int n = s.size();
        long ans = 0;
        for(int i=0,j=0; i<n; i=j){
            j=i;
            while(j<n && s[j] == s[i])  j++;
            int cnt = j - i;
            ans += (1ll * (1+cnt)*cnt )>> 1;
            ans %= MOD;
        }
        return ans;
    }
};
