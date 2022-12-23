#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(const auto &s : operations){
            if(s[1] == '+') ans++;
            else            ans--;
        }
        return ans;
    }
};