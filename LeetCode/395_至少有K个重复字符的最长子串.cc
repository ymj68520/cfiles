#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <functional>

using namespace std;

class Solution {
public:
    int longestSubstring2(string s, int k) {
        function<int(int,int)> dfs = [&](int l, int r) {
            if(r < l) return 0;
            int m[127] = {0};
            for(int i=l; i<=r; ++i) m[s[i]]++;
            for(int i=l; i<=r; ++i) if(m[s[i]] < k) {
                return max(dfs(l, i-1), dfs(i+1, r));
            }
            return r - l + 1;
        };
        return dfs(0, s.length()-1);
    }
    int longestSubstring(string s, int k) {
        int ans=0;
        int record[26];
        for(int i=1;i<=26;++i){
            memset(record,0,sizeof(record));
            int left(0),right(0);
            int diff_count(0), count(0);
            while(right < s.length()){
                int add_index = s[right++] - 'a';
                record[add_index] ++;
                if(record[add_index]==1)    diff_count++;
                if(record[add_index]==k)    count++;

                while(left < right && diff_count > i){
                    int del_index = s[left++] - 'a';
                    if(record[del_index] == k)  count--;
                    if(record[del_index] == 1)  diff_count--;
                    record[del_index] --;
                }
                if(diff_count == i && diff_count == count)
                    ans = max(ans,right-left);
            }
        }
        return ans;
    }
};

int main(){
    string s = "qabaabcdefasfhsdkfgsliitgfyuafsgdyjagfilskkdjtgfukyasgfdskjhlgbblisdgyfuusgdlikfjgssdzkujfayilugsfuiksdgfiusaegf";
    int k = 2;
    Solution sol;

    cout << sol.longestSubstring(s,k) << endl;
    cout << sol.longestSubstring2(s,k) << endl;

    return 0;
}