#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
/*
给定一个非负整数N，找出大于或等于N的最小的整数，
同时这个整数需要满足各个位数上的数字是从左往右单调递减的。
（当且仅当每个相邻位数上的数字x和y满足x>=y时，我们称这个整数是单调递减的）。
本题需考量性能，暴力求解得分上限为16分。

示例1：
* 输入：19
* 输出：20

示例2：
* 输入：4321
* 输出：4321

示例3：
* 输入：3223
* 输出：3300 

请实现目标函数：
int GetDecreasingBiggerNum(int N) ；
*/
int GetDecreasingBiggerNum(int N){
    if(N<=10)    return N;
    string s = to_string(N);
    int n = s.length();
    int pos=-1;
    for(int i=0;i<n-1;i++) if(s[i]<=s[i+1]){
        pos = i;   // 记录失序位置
        break;
    }
    if(pos == -1)   return N;
    int posi=pos+1;
    while(s[posi]==s[pos]) posi++;
    s[pos]+=1;
    while(posi<n)    s[posi++] = '0';
    int ret=0;
    for(auto x:s){
        ret = ret*10 + (x-'0');
    }
    return ret;
}

int main(){
    int N;
    while(scanf("%d",&N)==1 && N !=0)
        cout << GetDecreasingBiggerNum(N) << endl;

    return 0;
}