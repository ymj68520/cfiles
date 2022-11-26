#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxlen = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(i <= maxlen){
            maxlen = max(maxlen,i+nums[i]);
            if(maxlen >= n-1)    return true;
        }
    }
    return false;
}

int main(){
    vector<int> nums = {2,3,1,1,4};
    cout << canJump(nums) << endl;

    return 1;
}
