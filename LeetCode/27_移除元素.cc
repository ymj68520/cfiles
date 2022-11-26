#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    // for(auto i = nums.begin();i!=nums.end();i++)
    //     if(*i == val)   nums.erase(i);

    // static int t = val;
    // nums.erase(remove_if(nums.begin(),nums.end(),
    // [](int num)->bool{return num == t;}),nums.end());

    int n = nums.size();
    if(n<1) return 0;
    int p(0),q(n-1),cnt(0);
    while(p < (n - cnt)){
        if(nums[p] == val){
            swap(nums[p],nums[q]);
            q--;cnt++;
        }
        else
            p++;
    }

    return n-cnt;
}

int main(){
    vector<int> nums = {1,2,3,1};
    cout << nums.size() << endl << removeElement(nums,1) << endl;

    return 0; 
}