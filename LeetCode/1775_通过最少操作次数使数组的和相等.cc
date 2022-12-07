#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if(6*nums1.size()<nums2.size() || 6*nums2.size()<nums1.size())
            return -1;
        int d = accumulate(nums2.begin(),nums2.end(),0)-accumulate(nums1.begin(),nums1.end(),0);
        if(d<0){
            d = -d;
            swap(nums1,nums2);
        }
        int cnt[6]{};
        for(const int &x: nums1)    ++cnt[6-x];
        for(const int &y: nums2)    ++cnt[y-1];
        for(int i=5,ans=0;;--i){
            if(i*cnt[i] >= d)   return ans+(d+i-1)/i;
            ans += cnt[i];
            d -= i*cnt[i];
        }
    }
};