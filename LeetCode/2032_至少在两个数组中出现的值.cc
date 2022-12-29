#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> s1,s2,s3;
        vector<int> ans;
        auto gt = [](vector<int> &ar){
            vector<int> cnt(101);
            for(int & a:ar) cnt[a] = 1;
            return cnt;
        };
        s1 = gt(nums1), s2 = gt(nums2), s3 = gt(nums3);
        for(int i=0;i<101;++i){
            if(s1[i]+s2[i]+s3[i]>1)
                ans.push_back(i);
        }
        return ans;
    }
};