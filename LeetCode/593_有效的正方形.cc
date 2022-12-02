#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <array>
#include <unordered_set>


using namespace std;

#define Cen2Ori(p) {p[0]*4-cenX, p[1]*4-cenY} 
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // 中心点，缩放 4 倍，避免除法
        int cenX = p1[0] + p2[0] + p3[0] + p4[0]; 
        int cenY = p1[1] + p2[1] + p3[1] + p4[1];
        // 将中心点移动到坐标原点
        vector<array<int, 2>> pts = {Cen2Ori(p1), Cen2Ori(p2), Cen2Ori(p3), Cen2Ori(p4)};
        // 将四个顶点存入哈希表
        auto arrayHash = [fn = hash<long>{}] (const array<int, 2>& arr) -> size_t { // 哈希函数
            return fn(*((long const*)arr.data()));
        };
        unordered_set<array<int, 2>, decltype(arrayHash)> pts_set(pts.begin(), pts.end(), 0, arrayHash);
        if(pts_set.size() < 4) return false;
        // 检查每个点旋转 90 度以后的点是否在哈希表中
        for(auto &pt: pts){  
            if(!pts_set.count({-pt[1], pt[0]})) return false;
        }
        return true;
    }
};

int main(){
    vector<int> p1={1,0},p2={-1,0},p3={0,1},p4={0,-1};
    Solution sol;
    cout << sol.validSquare(p1,p2,p3,p4) << endl;

    return 0;
}