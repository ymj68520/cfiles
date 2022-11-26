/*
    给定一个整数数组，和一个整数目标值，
    找出数组中和为目标值的两个整数，并返回其数组下标。
*/

#include <iostream>
using namespace std;

int * BFtwosum(int nums[], int target){
    int result[2];
    for(int i=0;i<sizeof(nums)/sizeof(int);i++){
        for(int j=i+1;j<sizeof(nums)/sizeof(int);j++){
            if(nums[i]+nums[j]==target){
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return nullptr;
}
#include <map>
int * Hashtwosum(int nums[], int target){
    map<int, int > sum;
    int result[2];
    for(int i=0;i<sizeof(nums)/sizeof(int);i++){
        int another = target - nums[i];
        int index = sum.count(another);
        if(0 != index){
            result[0] = index;
            result[1] = i;
            break;
        }
        else
            sum[nums[i]] = i; 
    }
    return result;
}
int main(){
    int numbs[] = {7,2,8,4,546354,454,6341,213,545};
    int target = 9;
}