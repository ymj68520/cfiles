#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> alChar;
        int cnt=0;
        for(auto &x:allowed){
            if(alChar.count(x) == 0)
                alChar.insert(x);
        }
        for(const auto &word : words){
            bool flag = true;
            for(const auto &ch : word){
                if(alChar.count(ch) == 0){
                    flag = false;
                    break;
                }
            }
            if(flag)    cnt++;
        }
        return cnt;
    }
};