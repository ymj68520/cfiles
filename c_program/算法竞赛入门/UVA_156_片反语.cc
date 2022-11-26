// 输入一些单词(以#号结尾)，找出满足条件的单词：
// 该单词不能通过字母重排序得到输入文本中的另一个单词

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string,int> cnt;
vector<string> words;

// 将单词统一化为小写, 然后按字典序排序
string repr(const string &s){   // 常量引用，提高效率
    string ans = s;     // 初始化ans，防止后续使用时出错
    for(int i=0;i<ans.length();++i) // 每一位都转换为小写
        ans[i] = tolower(ans[i]);
    sort(ans.begin(),ans.end());    // 将字符串按字典序排序
    return ans;
}

int main(){
    int n = 0;
    string s;   // 临时变量
    while(cin >> s){    // 通过输入时遍历所有单词得到结果
        if(s[0]=='#')   break;  // 结尾标志
        words.push_back(s); // 将每一个单词放入words中
        string r = repr(s); // 标准化每一个单词
        if(!cnt.count(r)) cnt[r] = 0; // 如果map中不存在r，则创建一个，并赋值为0
        cnt[r]++;   // 计数加一，不管map中之前是否存在r，都需要个数加一
    }// map中存的是所有单词的标准化字符。
    vector<string> ans; // 待输出结果
    for(int i=0;i<words.size();++i) // 遍历每一个单词
        if(cnt[repr(words[i])]==1)  ans.push_back(words[i]);    // 如果该单词只有一次
    sort(ans.begin(),ans.end()); // 为输出结果按字典序排序
    for(int i=0;i<ans.size();++i)
        cout << ans[i] << endl;     // 输出
    return 0;
}