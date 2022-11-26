#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
// 测试输入：8 4 6 7 5 2
int main(){
    vector<int> bing;
    int maxnum,pos,t;
    string s;
    getline(cin,s);
    stringstream input(s);
    while(input >> t)   bing.push_back(t);
    
    int n = bing.size();
    for(int i=0;i<n-1;i++){
        maxnum=-1;pos=-1;
        for(int j=0;j<n-i;j++)
            if(maxnum<bing[j]){
                maxnum = bing[j];
                pos = j;
            }
        reverse(bing.begin(),bing.begin()+pos+1);
        reverse(bing.begin(),bing.end()-i);
        for(auto x:bing)    cout << x << ' '; cout << endl;
    }
    return 0;
}