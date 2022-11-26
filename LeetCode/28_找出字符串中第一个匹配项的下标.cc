#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

void getnext(string &T, vector<int> &next){
    int i=0,j=-1;
    next.resize(T.length());
    next[0] = -1;
    while(i<T.length()-1){
        if(j==-1 || T[i]==T[j]){
            i++;j++;
            next[i]= j;
        }
        else
            j = next[j];
    }
}

int strStr(string haystack, string needle) {
    // int ls = haystack.length();
    // int lt = needle.length();
    // if(lt > ls) return -1;
    // vector<int> next;
    // getnext(needle, next);
    // int i=-1,j=0;
    // while(i<ls && j<lt){
    //     if(j==-1 || haystack[i] == needle[j]){
    //         i++;j++;
    //     }else
    //         j = next[j];
    // }
    // if(j>=lt)
    //     return i-lt;
    // return -1;

    int n = haystack.size(), m = needle.size();
    if(m == 0) return 0;
    //设置哨兵
    haystack.insert(haystack.begin(),' ');
    needle.insert(needle.begin(),' ');
    vector<int> next(m + 1,0);
    //预处理next数组
    for(int i = 2, j = 0; i <= m; i++){
        while(j && needle[i] != needle[j + 1]) j = next[j];
        if(needle[i] == needle[j + 1]) j++;
        next[i] = j;
    }
    //匹配过程
    for(int i = 1, j = 0; i <= n; i++){
        while(j && haystack[i] != needle[j + 1]) j = next[j];
        if(haystack[i] == needle[j + 1]) j++;
        if(j == m) return i - m;
    }
    return -1;
}

int main(){
    string s1 = "sadbutsad";
    string s2 = "adb";

    cout << strStr(s1,s2) << endl;

    return 0;
}