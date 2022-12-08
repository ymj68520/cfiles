#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        short c1 = coordinates[0]%2;
        short c2 = coordinates[1]%2;
        if(c1^c2)   return true;
        else    return false;
    }
};

int main(){
    string cc = "a1";
    Solution sol;
    cout << sol.squareIsWhite(cc) << endl;

    return 0;
}