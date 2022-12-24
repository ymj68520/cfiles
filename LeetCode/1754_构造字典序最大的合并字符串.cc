#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        int p = 0, q = 0;
        string ans;
        while (p < len1 && q < len2) {
            ans += (word1.substr(p) > word2.substr(q)) ? word1[p++] : word2[q++];
        }
        ans += word1.substr(p);
        ans += word2.substr(q);
        return ans;
    }
};


int main(){
    string w1 = "cabaa",w2="bcaaa";
    Solution sol;

    cout << sol.largestMerge(w1,w2) << endl;

    return 0;
}