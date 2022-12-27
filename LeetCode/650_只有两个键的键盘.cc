#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if(n==1)    return 0;
        int t = 1;
        for(int i=2;i<=sqrt(n);++i){
            if(n%i == 0){
                t = i;
                break;
            }
        }
        if(t == 1)  return n;
        return t + minSteps(n/t);
    }
};