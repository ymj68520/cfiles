#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int cnt[n+10];
        int ans=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=0,j=0,tol=0;i<n;i++){
            if(++cnt[fruits[i]] == 1) tol++;
            while(tol > 2){
                if(--cnt[fruits[j++]] == 0) tol--;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};