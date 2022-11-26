#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    if (nums[n - 1] < target) return n;
    int left = 0;
    int right = n-1;
    while(left < right){
        int pos = left + (right - left) / 2;
        if (nums[pos] < target) left = pos + 1;
        else right = pos;
    }
    return left;
}



int main(){
    vector<int> nums = {1,3,5,9};
    int target = 10;
    cout << searchInsert(nums, target) << endl;

    return 0;
}