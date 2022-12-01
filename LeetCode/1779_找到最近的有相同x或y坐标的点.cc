#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        int ans = -1;
        int minlen = INT_MAX;

        for(int i=0;i<n;++i){
            int x0 = points[i][0], y0 = points[i][1];
            int len = INT_MAX;
            if(x0==x)   len = abs(y-y0);
            if(y0==y)   len = abs(x-x0);
            if(len < minlen){
                minlen = len;
                ans = i;
            }            
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> p = {{1,2},{3,1},{2,4},{2,3},{4,4}};
    Solution sol;

    cout << sol.nearestValidPoint(3,4,p) << endl;

    return 0;
}