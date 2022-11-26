#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    vector<string> str;
    int n = strs.size();
    if(n < 1){
        str.push_back("");
        ans.push_back(str);
        return ans;
    }
    vector<string> sstrs;
    bool isin[n]; memset(isin,0,sizeof(isin));
    for(auto x:strs){    
        sort(x.begin(),x.end());
        sstrs.push_back(x);
    }

    for(int i=0;i<n;i++){
        if(isin[i]) continue;
        str.clear();
        for(int j=i;j<n;j++){
            if(sstrs[j] == sstrs[i]){
                str.push_back(strs[j]);
                isin[j] = true;
            }
        }
        ans.push_back(str);
    }
    return ans;
}

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for(auto i:ans){
        for(auto j:i){
            for(auto k:j)   cout << k;
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}