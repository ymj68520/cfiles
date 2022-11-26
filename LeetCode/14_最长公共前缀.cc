#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string ans;
    if(strs.empty() || strs.size()==1)    return strs[0];
    char ch='\0';
    int n = strs.size();
    int pos=0;
    while(1){
        ch = strs[0][pos];
        for(int i=1;i<n;i++){
            if(pos==strs[i].size() || ch != strs[i][pos])
                return ans;
        }
        ans.push_back(ch);
        pos++;
    }
}

int main(){
    vector<string> strs = {"flower","flow","flight"};
    string ans = longestCommonPrefix(strs);
    for(auto s : ans)    cout << s;
    cout << endl;

    return 0;
}