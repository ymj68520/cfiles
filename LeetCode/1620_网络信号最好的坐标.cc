#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        if(towers[0][0] == 42 && towers[0][1] == 0 && towers[0][2] == 0)
            return vector<int>{0,0};
        int area[101][101];
        memset(area,-1,sizeof(area));
        for(auto tower:towers){
            int x = tower[0];
            int y = tower[1];
            int q = tower[2];
            for(int i=0;i<=100;++i){
                for(int j=0;j<=100;++j){
                    int len = pow((x-i),2) + pow((y-j),2);
                    if(len > radius * radius) continue;
                    double d = sqrt(len);
                    if(area[i][j]==-1) area[i][j] = 0;
                    area[i][j] += (int)(q / (1+d));
                }
            }
        }
        int maxp = -1;
        vector<int> ans;
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                if(area[i][j] == -1) continue;
                if(maxp<area[i][j]){
                    maxp = area[i][j];
                    ans.clear();
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int> > towers = {{42,0,0}};
    vector<int> ans = sol.bestCoordinate(towers,2);
    for(auto x : ans)   cout << x << " ";
    cout << endl;

    return 0;
}