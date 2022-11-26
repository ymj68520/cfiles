
/*给定一个正整数k和一个只包含正整数的非空数组。
请将这个数组分割成两个子集，使得k*A - B的绝对值最小，求出这个最小的绝对值，
其中A、B分别为两个子集的元素和。

Ps:

1 <= k <= 10

1 <= array.length <= 30

1 <= array[i] <= 1000



示例1：

输入：k=1, arr = [1, 1, 2, 7, 4, 8]

输出：1  （把4、7分一组和为11，把1、1、2、8分一组和为12，差值为1 * 12-11=1）

1
1 1 2 7 4 8
-1

示例2：

输入：k=2, arr = [1, 2, 2, 4, 5, 8]

输出：1  （把1、2、4分一组和为7，把2、5、8分一组和为15，差值为15 - 2 * 7=1）*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int solver(int k, vector<int>nums){
    int n = nums.size();
    if(n==0)    return 0;
    sort(nums.begin(),nums.end());
    // 动态规划 dp[i]为元素个数为i时的最优解 resilt[i]记录原始计算结果而非绝对值
    // [0]为+ [1]为-
    int dp[n];memset(dp,-1,sizeof(dp));
    dp[0]=nums[0];
    int result[n+1][2];
    result[0][0] = nums[0];
    result[0][1] =-nums[0];

    for(int i=1;i<n;i++){
        result[i][0] = min(result[i-1][0]+k*nums[i],result[i-1][1]+k*nums[i]);
        result[i][1] = min(result[i-1][0] - nums[i],result[i-1][1] - nums[i]);
        dp[i] = min(abs(result[i][0]),abs(result[i-1][1]));
    }
    return dp[n-1];
}
int main(){
    int k=1;
    vector<int> nums={1,1,2,7,4,8};
    cout << solver(k,nums) << endl;
    // while(scanf("%d",&k)&&k!=-1){
    //     string s;
    //     getline(cin,s);
    //     stringstream input(s);
    //     int t;
    //     while(input >> t)   nums.push_back(t);
    //     cout << solver(k,nums) << endl;
    // }
    return 0;
}