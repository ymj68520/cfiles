#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 1010;  // 最大的结点个数
const int INF = 999999; // 假设的边的最大值

class floyd{
public:
    int n,m;
    int d[MAXN][MAXN],u[MAXN],v[MAXN],w[MAXN];
    void Floyd(){
        for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++)
            d[i][j] = min(d[i][j],d[i][k]+d[k][j]);                    
    }
    void Floyd1(){
        for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++)
            if(d[i][j] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
    }
};