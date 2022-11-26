/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。
    n == height.length
    2 <= n <= 105
    0 <= height[i] <= 104

链接：https://leetcode-cn.com/problems/container-with-most-water

*/
#include <iostream>
#include <vector>

using namespace std;

int maxn;

// int maxArea(vector<int>& height) {
//     int i=0,j=height.size()-1;
//     maxn = min(height[i],height[j])*(j-i);
    
//     while(i < j){
//         int temp = min(height[i+1],height[j])*(j-i-1);
//         maxn = max(maxn,temp);
//         temp = min(height[i],height[j-1])*(j-i-1);
//         maxn = max(maxn,temp);
//         if(height[i+1]<height[j])
//             i++;
//         else
//             j--;
//     }
//     return maxn;
// }

int maxArea(vector<int>& height){
    int i=0,j=height.size()-1,result=0;
    while(i<j){
        result = max(result, min(height[i],height[j])*(j-i));
        if(height[i]<height[j]) i++;
        else    j--;
    }
    return result;
}
int main(){
    vector<int> temp = {2,3,10,5,7,8,9};

    cout << maxArea(temp) << endl;

    return 0;
}