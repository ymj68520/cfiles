#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int n = nums.size(), cnt = 0;;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int t = nums[i] ^ nums[j];
                if(t<low || t > high)  continue;
                cnt++;
            }
        }
        return cnt;
    }
};


