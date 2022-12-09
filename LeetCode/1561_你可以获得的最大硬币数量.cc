#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n = piles.size()-2;
        int s = 0;
        int ans=0;
        while (n>s){
            ans += piles[n];
            s++;
            n-=2;
        }
        return ans;

    }
};

int main(){
    Solution sol;
    vector<int> n = {2,4,1,2,7,8};

    cout << sol.maxCoins(n) << endl;

    return 0;
}