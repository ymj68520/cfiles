#include <iostream>
#include <algorithm>
using namespace std;
vector<int> nums = {0,1,2,0,1,2};
void sortColors(vector<int>& nums) {
    int ptr=0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i] == 0){
            swap(nums[i], nums[ptr]);
            ptr++;
        }
    }
    for(int i = ptr; i < n; ++i){
        if(nums[i] == 1){
            swap(nums[i], nums[ptr]);
            ptr++;
        }
    }
}

int main(){
    sortColors(nums);
    for(int i=0;i<nums.size();i++)
        cout << nums[i] << ' ';
    cout << endl;
}