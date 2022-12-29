#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        int pos = -1;
        while(k-- > 0){
            pos = s.find(' ',pos+1);
            if(pos == -1)   return s;
        }
        return s.substr(0,pos);
    }
};