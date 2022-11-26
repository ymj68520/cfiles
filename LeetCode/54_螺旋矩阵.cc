#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> ans; 
        bool flag[rows][cols];
        memset(flag,0,sizeof(flag));
        int i=0,j=0;
        while (ans.size() < rows*cols){
            while(j < cols && !flag[i][j]){
                flag[i][j] = 1;
                ans.push_back(matrix[i][j]);
                j++;
            }
            j--;i++;
            while(i < rows && !flag[i][j]){
                flag[i][j] = 1;
                ans.push_back(matrix[i][j]);
                i++;
            }
            i--;j--;
            while(j>=0 && !flag[i][j]){
                flag[i][j] = 1;
                ans.push_back(matrix[i][j]);
                j--;
            }
            j++;i--;
            while(i>=0 && !flag[i][j]){
                flag[i][j] = 1;
                ans.push_back(matrix[i][j]);
                i--;
            }
            i++;j++;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    // vector<vector<int>> ma = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int> > ma = {{1}};
    vector<int> ans = sol.spiralOrder(ma);
    for(auto &x:ans)    cout << x << " ";
    cout << endl;
    return 0;
}