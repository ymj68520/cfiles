#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int ans=0,t=0;
        for(const char &c : s){
            if(c=='(')  t++;
            else if(c == ')')   t--;
            ans = max(ans,t);
        }
        return ans;
    }
};