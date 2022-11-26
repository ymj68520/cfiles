#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

int partitionDisjoint(vector<int>& nums) {
    int n = nums.size();
    int right[n];
    right[n-1] = nums[n-1];
    for(int i=n-2;i>=0;i--)
        right[i] = min(nums[i],right[i+1]);
    int left=0;
    for(int i=0;i<n;i++){
        left = max(left,nums[i]);
        if(left <= right[i+1])    return i+1;
    }  
    return -1;  
}

int main(){
    vector<int> nums = {5,0,3,8,6};

    cout << partitionDisjoint(nums) << endl;

    return 0;
}