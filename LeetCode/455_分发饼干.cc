#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int i(0),j(0);
    int cnt=0;
    while(i<g.size() && j<s.size()){
        while(j<s.size() && s[j]<g[i])   j++;
        if(j<s.size()) cnt ++;
        j ++;
        i ++;
    }
    return cnt;
}

int main(){
    vector<int> g = {1,2,3};
    vector<int> s = {3};

    cout << findContentChildren(g,s) << endl;

    return 0;
}