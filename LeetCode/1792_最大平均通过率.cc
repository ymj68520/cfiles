#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>

using namespace std;
class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int>&t1, const pair<int,int>&t2){
            double k11 = 1.0 * t1.first / t1.second;
            double k1 = 1.0 * (t1.first+1) / (t1.second+1);
            double k22 = 1.0 * t2.first / t2.second;
            double k2 = 1.0 * (t2.first+1) / (t2.second+1);

            return k1 - k11 < k2 - k22;
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int,int>,vector<pair<int,int> >, cmp > q;
        for(auto &a : classes){
            q.push({a[0],a[1]});
        }
        while(extraStudents --){
            auto tp = q.top();
            q.pop();
            tp.first++;
            tp.second++;
            q.push(tp);
        }
        double ans = 0;
        while(!q.empty()){
            auto tp = q.top();
            q.pop();
            ans += 1.0 * tp.first / tp.second;
        }
        return ans/classes.size();
    }
};