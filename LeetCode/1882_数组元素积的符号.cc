#include <iostream>
#include <vector>
using namespace std;

int arraySign(vector<int>& nums) {
    int sign = 1;
    for(auto const n:nums){
        if(n==0)   return 0;
        else if(n<0)    sign *= -1;
        else            sign *= 1;
    }
    return sign;
}
