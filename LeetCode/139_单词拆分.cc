#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

bool wordBreak(string s,set<string>wordDict){
    int len = s.length();
    int dp[len+1];memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=len;i++){
        for(int j=0;j<i;j++){
            if(dp[j] && wordDict.count(s.substr(j,i)))  dp[i] = true;
        }
    }
    return dp[len];
}

int main(){
    string s = "LeetCodeLeet";
    set<string> words = {"leet","Code","Leet"};
    cout << wordBreak(s,words) << endl;

    return 0;
}