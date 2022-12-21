#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans=0;
        vector<int> res = {a,b,c};
        sort(res.begin(),res.end());
        while(res[0]!=0 || res[1]!=0){
            ans ++;
            res[1]--;
            res[2]--;
            sort(res.begin(),res.end());
        }
        return ans;
    }
};