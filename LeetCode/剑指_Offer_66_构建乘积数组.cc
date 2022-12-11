#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        if(n <= 1)  return a;
        int left[n],right[n];
        left[0] = a[0];
        right[n-1] = a[n-1];
        for(int i=1;i<n;++i)
            left[i] = left[i-1] * a[i];  
        for(int j=n-2;j>=0;--j)
            right[j] = right[j+1] * a[j];
        vector<int> b(n);
        for(int i=0;i<n;++i){
            int l = (i==0)   ? 1 : left [i-1];
            int r = (i==n-1) ? 1 : right[i+1];
            b[i] = l * r;
        }
        return b;
    }
};