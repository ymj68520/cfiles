#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rows(m,0),cols(n,0);
        for(auto & arr : indices)
            rows[arr[0]]++,cols[arr[1]]++;
        int cnt=0;
        for(auto & r : rows)    for(auto & c : cols)
            if((r+c) & 1)   cnt++;
        return cnt;
    }
};