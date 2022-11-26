#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;
const int INF = 250;
int main(){
    int n,M1,M2,T;
    int dp[INF][INF];
    bool has_train[250][51][2];
    int arrive_time[51];
    scanf("%d",&n); // 车站数
    getchar();
    scanf("%d",&T); // 到达时刻T
    getchar();
    string s;
    getline(cin,s);
    stringstream input1(s);
    for(int i=0;i<n-1;i++)  input1 >> arrive_time[i];    // 从i到i+1站点的时间
    scanf("%d",&M1);    // 从1站到n站的车辆总数
    getchar();
    getline(cin,s);
    stringstream input2(s); // 读取M1个车的出发时间
    for(int i=0;i<M1;i++){  // 初始化某时某站点是否有车
        int d;
        input2 >> d;
        has_train[d][0][0] = true;  // 发车站点1
        for(int j=0;j<n;j++)    has_train[ d + arrive_time[j] ][j][0] = true;
    }
    scanf("%d",&M2);
    getchar();
    getline(cin,s);
    stringstream input3(s);
    for(int i=0; i<M2; i++){
        int d;
        input3 >> d;
        has_train[d][n-i-1][1] = true;
        for(int j=n-1;j>=0;j--) has_train[ d + arrive_time[j] ][j][1] = true;
    }
    for(int i=1;i<=n-1;i++) dp[T][i] = INF;
    dp[T][n] = n;

    for(int i=T-1;i>=0;i--){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i+1][j] + 1;
            if(j<n && has_train[i][j][0] && i+arrive_time[j] <= T)
                dp[i][j] = min(dp[i][j], dp[i+arrive_time[j]][j+1]);
            if(j>1 && has_train[i][j][1] && i+arrive_time[j-1] <= T)
                dp[i][j] = min(dp[i][j], dp[i+arrive_time[j-1]][j-1]);
        }
    }

    if(dp[0][1] >= INF) cout << "impossible\n";
    else    cout << dp[0][1] << endl;

    return 0;
}

/*
4
55
5 10 15
4
0 5 10 20
4
0 5 10 15

output: 5
*/