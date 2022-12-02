#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans;
        for(int i=0;i<n;++i){
            int steps(0);
            for(int j=0;j<n;++j){
                if(boxes[j] == '1') steps += abs(j-i);
            }
            ans.push_back(steps);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> ans;
    string B = "110";
    ans = sol.minOperations(B);
    for(auto & x: ans)  cout << x << " ";
    cout << endl;

    return 0;
}