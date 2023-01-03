#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream sin(s);
        int maxn = -1;
        while(sin >> s){
            if(s[0] > '0'+11)   continue;
            if(stoi(s) < maxn)  return false;
            maxn = stoi(s);
        }
        return true;
    }
};