#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001);
        int max_stop = 0;
        for (auto& trip : trips) {
            int num = trip[0], from = trip[1], to = trip[2];
            diff[from] += num;
            diff[to] -= num;
            max_stop = max(max_stop, to);
        }
        if (diff[0] > capacity) return false;
        for (int i = 1; i <= max_stop; i++) {
            diff[i] += diff[i-1];
            if (diff[i] > capacity)
                return false;
        }
        return true;
    }
};

int main(){
    vector<vector<int> > t = {{2,1,5},{3,3,7}};
    int ca = 4;
    Solution sol;
    cout << sol.carPooling(t,ca) << endl;

    return 0;
}