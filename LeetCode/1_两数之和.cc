#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> twosum(vector<int>& nums, int target){
    map<int, int> sum;
    int result[2];
    for(int i=0;i<nums.size();++i){
        int another = target - nums[i];
        int index = sum.count(another);
        if(0 != index){
            result[0] = sum[another];   // 此处需小心
            result[1] = i;
            break;
        }
        else
            sum[nums[i]] = i; 
    }
    vector<int> result_r = {result[0],result[1]};
    return result_r;
}

int main(){
    vector<int> temp = {3,2,4};
    int target = 5;
    temp = twosum(temp,target);

    for(vector<int>::iterator i=temp.begin();i!=temp.end();i++)
        cout << *i << ", ";
    

}