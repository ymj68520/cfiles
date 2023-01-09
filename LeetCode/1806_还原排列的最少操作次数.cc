#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int reinitializePermutation(int n) { 
        vector<int> prem(n), arr(n);
        for (int i = 0; i < n; i++) prem[i] = i;
        int i, step = 1;
        while (true) {
            for (i = 0; i < n; i++) arr[i] = i % 2 == 0 ? prem[i / 2] : prem[(n - 1 + i) / 2];
            for (i = 0; i < n && arr[i] == i; i++); 
            if (i == n) return step;
            for (i = 0; i < n; i++) prem[i] = arr[i];
            step++;
        }
        return 0;
    }
};

class Solution {
public:
    int reinitializePermutation(int n){
        int i=1,step=1;
        while(1){
            i = i%2 ? (n+i-1)>>1 : i>>1;
            if(i==1)    return step;
            step++;
        }
        return 0;
    }
};