#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> zeros;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                zeros.push_back(cnt);
                cnt = -1;
            }
            cnt++;
        }
        zeros.push_back(cnt);
        n = zeros.size();
        for(int i=n-2;i>=1;i--){
            cnt = max(cnt,zeros[i]);
        }
        cnt = (cnt+1) >> 1;
        cnt = max(zeros[0],cnt);
        cnt = max(zeros[n-1],cnt);
        return cnt;
    }
};

int main(){
    Solution sol;
    vector<int> s = {1,0,0,1};
    cout << sol.maxDistToClosest(s) << endl;

    return 0;
}