#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

set<string> dictionary; // 变长字符串类型的集合

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s,temp;
    while(cin >> s){
        for(int i=0;i<s.length();i++)
            if(isalpha(s[i]))
                s[i] = tolower(s[i]);
            else
                s[i] = ' ';
        stringstream ss(s); // 将s作为流输入
        while(ss >> temp)
            dictionary.insert(temp);    // 插入元素
    }
    for(set<string>::iterator it = dictionary.begin(); it !=dictionary.end();++it)
        cout << *it << endl;
    return 0;
}