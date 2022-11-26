#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<string> generateParenthesis(int n) {
    if(n==0)    return {};
    if(n==1)    return {"()"};
    vector<vector<string>>  dp(n+1);    // 需要0状态，因此为n+1
    dp[0] = {""};
    dp[1] = {"()"};
    for(int i=2;i<=n;i++){   // 从n=2开始向上计算
        for(int j=0;j<i;j++){
            for(string x:dp[j]) for(string y:dp[i-1-j]){
                string str = "(" + x + ")" + y; // 从第0层开始套壳追加n-j-1的变量。
                dp[i].push_back(str);
            }
        }
    }
    return dp[n];
}

int main(){
    int n = 4;
    vector<string> str = generateParenthesis(n);
    for(int i=0;i<str.size();i++)
        cout << str[i] << ", ";
    cout << endl;

    return 0;
}