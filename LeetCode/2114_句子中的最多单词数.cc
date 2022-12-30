#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(const string &s : sentences){
            int blanks=0;
            for(int pos=1; pos !=0; ++pos)
            {
                pos = s.find(' ',pos);
                blanks ++;
            }
            ans = max(ans, blanks);
        }
        return ans;
    }
};