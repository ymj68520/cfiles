#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

string longestPalindrome1(string s) {
    int len = s.size();
    if(len < 2) return s;
    int start = 0, max_len = 1;
    vector<vector<int>>  dp(len,vector<int>(len));
    for(int i=0;i<len;i++){
        dp[i][i]=1;
        if(i<len-1&&s[i]==s[i+1]){
            dp[i][i+1]=1;
            max_len = 2;
            start=i;
        }
    }
    for(int l=3;l<=len;l++){
        //l表示检索的子串长度，等于3表示先检索长度为3的子串
        for(int i=0;i+l-1<len;i++){
            int j=i+l-1;//终止字符位置
            if(s[i]==s[j]&&dp[i+1][j-1]==1){    //起始终止位相同且去除这两位的子串也是回文串
                //状态转移
                dp[i][j]=1;
                start=i;
                max_len=l;
            }
        }
    }
    return s.substr(start,max_len);//获取最长回文子串
}
string longestPalindrome(string s){
    int len = s.size();
    if(len < 2) return s;
    int dp[len][len];   // 状态转移矩阵
    memset(dp,0,sizeof(dp));    // 初始化为false，即没有从i到j这个长度的回文串
    for(int i=0;i<len;i++)  dp[i][i] = 1;   // 最短的回文子串的长度应该为1，即i-i的dp应为1
    int start=0,maxLen=1;   // 初始化起始位置和最大长度，最初长度为1.
    for(int i=len-1;i>=0;i--){
        for(int j=i;j<len;j++){
            if(s[i]==s[j]){ // 当 当前i，j位置的字符相等时
                if(j-i<2)   dp[i][j] = 1;   // 异常处理
                else if(dp[i+1][j-1])   dp[i][j] = 1;   // 去处这两个字符的前置子串是回文串
                if(dp[i][j] && j-i+1 > maxLen){ // 根据以上判断的是否为回文子串，且长度大于之前的最大长度
                    maxLen = j-i+1; // 更新
                    start = i;
                }
            }
        }
    }
    return s.substr(start,maxLen);  // 返回从start开始到maxLen的左闭右开子串。
}

int main(){
    string s = "aaaaaaaaaababd";
    cout << longestPalindrome(s) << endl;

    return 0;
}