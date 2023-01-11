#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string str = "123456789";
        int minLen = to_string(low) .size(),
            maxLen = to_string(high).size();
        while(minLen <= maxLen){
            int temp;
            for(int i=0;i<=9-minLen;++i){
                temp = stoi(str.substr(i,minLen));
                if(temp < low)  continue;
                if(temp > high) break;
                ans.push_back(temp);
            }
            minLen++;
        }
        return ans;
    }
};