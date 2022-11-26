#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int cnt[50];memset(cnt,0,sizeof(cnt));
        int ans=0;
        for(int i=lowLimit;i<=highLimit;++i){
            int t = 0;
            for(int x=i;x;x/=10){
                t += x%10; 
            }
            cnt[t]++;
            ans = max(ans, cnt[t]);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    cout << sol.countBalls(1,100) << endl;

    return 0;
}