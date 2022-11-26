#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        if (n <= 3) {
            return true;
        }
        return (!canWinNim(n-1)) || (!canWinNim(n-2)) || (!canWinNim(n-3));
    }
};

int main(){
    int n = 8;
    Solution sol;
    cout << sol.canWinNim(n) << endl;
    return 0;
}