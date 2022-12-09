#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n == 1)  return true;
        int mod = n%3;
        switch(mod){
            case 2:
                return false;
            case 0:
                n = n/3;
                return checkPowersOfThree(n);
            case 1:
                n = n-1;
                return checkPowersOfThree(n);
        }
        return false;
    }
};

int main(){
    Solution sol;
    cout << sol.checkPowersOfThree(91) << endl;

    return 0;
}