#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance1(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int ans = 0, l,r,mid;
        for(int i=0;i<m;++i){
            l = i, r = n;
            while(l<r){
                mid = (l+r) >> 1;
                if(nums1[i] > nums2[mid])   r = mid;
                else    l = mid+1;
                ans = max(ans, r-i-1);
            }
        }
        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int l=0, r=0;
        while(l<m && r<n){
            if(nums1[l] > nums2[r]) l++;
            r++;
        }
        return r-l-1 > 0 ? r-l-1 : 0;

    }
};

int main(){
    vector<int> n1 = {1,2,2,2};
    vector<int> n2 = {10,10,10};
    Solution sol;

    cout << sol.maxDistance(n1,n2) << endl;

    return 0;
}