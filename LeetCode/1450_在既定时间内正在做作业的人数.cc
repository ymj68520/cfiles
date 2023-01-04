#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int cnt=0;
        for(int i=0;i<n;++i){
            if(startTime[i]<=queryTime && endTime[i]>=queryTime)
                cnt++;
        }
        return cnt;
    }
};