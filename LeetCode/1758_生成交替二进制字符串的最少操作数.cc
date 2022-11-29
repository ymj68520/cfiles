#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if(n == 1)  return 0;
        int cnt[2]; memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            
        }
        return min(cnt[0],cnt[1]);
    }
};