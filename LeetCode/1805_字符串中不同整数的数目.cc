#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            if (isdigit(word[i])) {
                while (i < n && word[i] == '0') ++i;
                int j = i;
                while (j < n && isdigit(word[j])) ++j;
                s.insert(word.substr(i, j - i));
                i = j;
            }
        }
        return s.size();
    }
};
int main(){
    string s = "a123bc34d8ef34";
    Solution sol;

    cout << sol.numDifferentIntegers(s) << endl;

    return 0;
}