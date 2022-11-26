#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        if(n==1)    return 0;
        int lastLine(0),curLine(0),ans(0);
        int i=0;
        for(;i<n;i++){
            for(int j=bank[i].find('1');j!=-1 && j<bank[i].length();j++)
                if(bank[i][j] == '1')    lastLine ++;
            if(lastLine != 0){
                i++;
                break;
            }
        }
        if(i>=n) return 0;
        for(;i<n;i++){
            for(int j=bank[i].find('1');j!=-1 && j<bank[i].length();j++){
                if(bank[i][j]=='1') curLine++;
            }
            if(curLine != 0){
                ans += curLine * lastLine;
                lastLine = curLine;
                curLine = 0;
            }
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<string> bank = {"000000","011001","000000","010100","001000"};
    cout << sol.numberOfBeams(bank) << endl;
    return 0;
}