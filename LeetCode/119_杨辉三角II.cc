#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> getRow(int rowIndex) {
    int n = rowIndex + 1;
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; ++i) {
            ans[i].resize(i + 1);
            ans[i][0] = ans[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
    return ans[rowIndex];
}

int main(){
    vector<int> nums = getRow(5);
    for(int i=0;i<5;i++)
        cout << nums[i] << ' ';
    cout << endl;
    return 0;
}