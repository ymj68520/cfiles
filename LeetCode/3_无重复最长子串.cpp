// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
// 0 <= s.length <= 5 * 10^4
// s 由英文字母、数字、符号和空格组成

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if(s.length() == 0) return 0;  
    int maxl=1;
    for(int i=0;i<s.length();i++){
        set<char> temp;
        temp.insert(s[i]);
        for(int j=i+1;j<s.length();j++){
            if(temp.count(s[j]))
                break;
            char t = s[j];
            temp.insert(s[j]);
            maxl = max(maxl,j-i+1);
        }
    }
    return maxl;
}
int lengthOfLongestSubstring(string s,int qqq) {
    vector<int> m(10010,0);
    int ans = 0;
    int i = 0;
    for (int j = 0; j < s.size(); j++) {
        i = max(i, m[s[j]]);
        m[s[j]] = j + 1;
        ans = max(ans, j - i + 1);
    }
    return ans;
}
int main(){
    string s = {"bbbbbbb"};

    cout << lengthOfLongestSubstring(s,111) << endl;

    return 0;
}