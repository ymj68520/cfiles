#include <iostream>
#include <climits>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
private:
    int yinshu[3] = {2,3,5};
public:
    int nthUglyNumber(int n) {
        priority_queue<int,vector<int>,greater<int> > q;
        unordered_set<int> s;
        q.push(1);s.insert(1);
        while(n-->1){
            int t = q.top();q.pop();
            for(auto &x:yinshu){
                if(x<=INT_MAX/t && s.count(x*t)==0){
                    q.push(x*t);
                    s.insert(x*t);
                }
            }
        }
        return q.top();
    }
};

int main(){
    Solution sol;
    cout << sol.nthUglyNumber(1690) << endl;

    return 0;
}