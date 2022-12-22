#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> map;
        for(const auto &j : jewels)  map.insert(j);
        int ans=0;
        for(const auto &s : stones) if(map.count(s))
            ans++;
        return ans;
    }
};