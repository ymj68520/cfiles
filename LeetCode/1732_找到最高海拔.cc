#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int curAltitude = 0;
        for(auto &x : gain){
            curAltitude += x;
            maxAltitude = max(curAltitude,maxAltitude);
        }
        return maxAltitude;
    }
};

int main(){
    vector<int> gain = {1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    Solution sol;

    cout << sol.largestAltitude(gain) << endl;

    return 0;
}