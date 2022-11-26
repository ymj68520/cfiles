#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        // 双指针，一个代表当前字符出现的第一个位置，一个表示修改后当前长度
        int left = 0, len = 0;
        for(int i = 0; i < n; i ++) {
            // 遇到临界点（最后一个位置，或者两字符分界处）
            if(i == n - 1 || chars[i] != chars[i + 1]) {
                chars[len ++] = chars[i];
                int nums = i - left + 1;
                if(nums > 1) {
                    // 把数字加到末尾
                    for(char num : to_string(nums)) {
                        chars[len ++] = num;
                    }
                }
                left = i + 1;
            }
        }
        return len;
    }
    
};

int main(){
    vector<char> chars = {'1','1','a','a','b','b','b','c','c','d'};
    Solution sol;
    int len = sol.compress(chars);
    cout << len << endl;
    for(int i=0;i<len;i++)  cout << chars[i];   
    cout << endl;

    return 0;
}