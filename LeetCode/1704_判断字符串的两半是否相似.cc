#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int p=0,q=s.length()-1;
        int cntP=0,cntQ=0;
        while(p<q){
            if(isYvanyin(s[p++])) cntP++;
            if(isYvanyin(s[q--])) cntQ++;
        }
        return cntP == cntQ;
    }
    bool isYvanyin(char c){
        switch(c){
            case 'A':
            case 'a':
            case 'e':
            case 'E':
            case 'I':
            case 'i':
            case 'o':
            case 'O':
            case 'U':
            case 'u':
                return true;
            default :
                return false;
        }
    }
};

int main(){
    string s = "text";
    Solution sol;
    cout << sol.halvesAreAlike(s) << endl;

    return 0;
}