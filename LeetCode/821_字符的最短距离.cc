#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ans(n,n+1);
        for(int i=0,j=-1;i<n;i++){
            if(s[i] == c)   j = i;
            if(j!= -1)  ans[i] = i - j;
        }
        for(int i=n-1,j=-1;i>=0;--i){
            if(s[i] == c)   j = i;
            if(j!=-1)   ans[i] = min(ans[i],j-i);
        }
        return ans;
    }
};