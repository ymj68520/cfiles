#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(int &x : nums) mp[x] = 0;
        for(int &x : nums) mp[x] = !mp[x];
        for(auto i=mp.begin();i!=mp.end();++i)  if((*i).second)
            return false;
        return true;
    }
};