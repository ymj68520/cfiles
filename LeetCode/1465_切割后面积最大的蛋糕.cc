#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        // 区域最后一块区域参与进来
        int maxH = max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.size()-1]);
        int maxW = max(verticalCuts[0], w - verticalCuts[verticalCuts.size()-1]);
        // 求差
        for(int i = 1; i < horizontalCuts.size(); i++) {
            maxH = max(horizontalCuts[i]-horizontalCuts[i-1], maxH);
        }
        for(int i = 1; i < verticalCuts.size(); i++) {
            maxW = max(verticalCuts[i]-verticalCuts[i-1], maxW);
        }
        return (unsigned long long)(maxH)*(unsigned long long)(maxW)%1000000007;
    }
};