#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n = cost.size();
        if(n==1)    return cost[0];
        if(n==2)    return cost[0]+cost[1];
        if(n==3)    return cost[1]+cost[2];
        for(int i=n-3;i>=0;i-=3)    cost[i] = 0;
        int ans=0;
        for(int i=0;i<n;i++)    ans += cost[i];
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> cost = {1,2,3,4,5,6};

    cout << sol.minimumCost(cost) << endl;

    return 0;
}