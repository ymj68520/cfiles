#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        bool flag = false;
        int minn = abs(matrix[0][0]);
        long long ans=0;
        for(auto &x : matrix){
            for(auto y : x){
                if(y<0){
                    flag = !flag;
                    y = -y;
                }
                ans += y;
                minn = min(y, minn);  //记录最小值
            }
        }
        if(flag)    return ans - 2*minn;
        else return ans;
    }
};

int main(){
    vector<vector<int> > m = {{1,-1,1},{-1,1,1},{1,1,1}};
    Solution sol;

    cout << sol.maxMatrixSum(m) << endl;

    return 0;
}