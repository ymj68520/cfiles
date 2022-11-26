#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int>a, vector<int>b)->bool{return a[0]<b[0];});
        int maxWi = 0;
        for(int i=1;i<points.size();++i){
            maxWi = max(maxWi,points[i][0]-points[i-1][0]);
        }
        return maxWi;
    }
};

int main(){
    vector<vector<int> > p = {{8,7},{9,9},{7,4},{9,7}};
    Solution sol;

    cout << sol.maxWidthOfVerticalArea(p) << endl;

    return 0;
}