#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool containsDuplicate(vector<int>& nums){
    unordered_set<int> map;
    for(int i=0;i<nums.size();i++){
        if(map.find(nums[i]) != map.end())  return true;
        else    map.insert(nums[i]);
    }
    return false;
}

int main(){
    vector<int> nums = {1,1,4,5,1,4};
    cout << containsDuplicate(nums) << endl;

    return 0;
}