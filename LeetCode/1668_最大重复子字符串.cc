#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.length();
        int m = word.length();
        int ans;
        string s = sequence + word;
        int P = 1313131;
        int N = s.length();
        long h[N+10],p[N+10],f[n+10];
        p[0] = 1;
        for(int i=1;i<=N;i++){
            h[i] = h[i-1] * P + s[i-1];
            p[i] = p[i - 1] * P;
        }
        long phash = h[N] - h[N - m] * p[m];
        for (int i = 1; i <= n; i++) {
            if (i - m < 0) continue;
            long cur = h[i] - h[i - m] * p[m];
            if (cur == phash) f[i] = f[i - m] + 1;
            ans = max((long)ans, f[i]);
        }
        return ans;
    }
    // 枚举
    int maxRepeating2(string sequence, string word) {
        int ans = 0;
        string t = word;
        int x = sequence.size() / word.size();
        for (int k = 1; k <= x; ++k) {
            if (sequence.find(t) != string::npos) {
                ans = k;
            }
            t += word;
        }
        return ans;
    }

};

int main(){
    string s = "ababc";
    string w = "ab";
    Solution sol;
    cout << sol.maxRepeating(s,w) << endl;

    return 0;
}