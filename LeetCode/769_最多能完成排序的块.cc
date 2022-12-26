#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), rb = -1, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i > rb) cnt++;
            if (arr[i] > rb) rb = arr[i];
        }
        return cnt;
    }
};