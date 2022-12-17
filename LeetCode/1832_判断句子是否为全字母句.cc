#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> alp(26,0);
        for(auto &ch : sentence){
            alp[ch-'a']++;
        }
        for(auto &n : alp)  if(n == 0)  return false;
        return true;
    }
};

int main(){
    string str = "hequickbrownfoxjumpsoverthelazydog";
    Solution sol;
    cout << sol.checkIfPangram(str) << endl;
    return 0;
}