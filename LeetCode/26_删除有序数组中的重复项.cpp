#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0)    return 0;
    int i=0,j=1;
    while(j<nums.size()){
        if(nums[i] != nums[j]){
            if(j-i>1)   nums[i+1] = nums[j];
            i++;
        }
        j++;
    }
    return i+1;
}

int main(){
    vector<int> t = {0,0};
    int k = removeDuplicates(t);
    cout << k << endl;
    for(vector<int>::iterator i=t.begin();i!=t.end();i++)
        cout << *i << ", " << endl;
    return 0;
}