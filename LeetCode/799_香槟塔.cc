#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        const int n = query_row+10;
        double f[n][n];
        f[0][0] = poured;
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                if(f[i][j]<=1)   continue;
                f[i+1][j] +=(f[i][j]-1)/2;
                f[i+1][j+1]+=(f[i][j]-1)/2;
            }
        }
        return min(f[query_row][query_glass],1.0);
    }
};

int main(){
    Solution sol;
    cout << sol.champagneTower(3,1,1) << endl;

    return 0;
}