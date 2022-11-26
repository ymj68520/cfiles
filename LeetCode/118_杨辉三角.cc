#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    for (int i = 0; i < numRows; ++i) {
            ans[i].resize(i + 1);
            ans[i][0] = ans[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
    return ans;
}

int main(){
    vector<vector<int>> nums = generate(5);
    for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++)
            cout << nums[i][j] << ' ';
        cout << endl;
    }
    return 0;
}

