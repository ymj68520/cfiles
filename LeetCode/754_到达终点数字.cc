#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int s = 0, n = 0;
        while(s<target || (s-target)%2)
            s += ++n;
        return n;
    }
};

int main(){
    Solution sol;

    cout << sol.reachNumber(1919810114) << endl;
}