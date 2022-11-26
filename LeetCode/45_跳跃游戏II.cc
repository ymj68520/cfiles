#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int jump(vector<int>& nums) {
    int start=0;
    int end  =1;
    int ans  =0;
    while (end < nums.size()){
        int maxPos = 0;
        for(int i=start;i<end;i++)
            maxPos = max(maxPos,i+nums[i]);
        start = end;
        end = maxPos+1;
        ans ++;
    }
    return ans;
}
int jump1(vector<int> &nums){
    int maxPos=0;
    int end = 0;
    int ans = 0;
    for(int i=0;i<nums.size()-1;i++){
        maxPos = max(maxPos,i+nums[i]);
        if(i==end){
            end = maxPos;
            ans ++;
        }
    }
    return ans;
}


int main(){
    vector<int> nums = {2,0,3,1,1,1,2,1,1,4};
    cout << jump(nums) << endl << jump1(nums) << endl;

    return 0;
}