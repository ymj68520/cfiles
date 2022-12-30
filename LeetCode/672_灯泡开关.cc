#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int flipLights(int n, int presses) {
        if(presses == 0)    return 1;
        if(n       == 1)    return 2;
        else if(n  == 2)    return presses==1 ? 3 : 4;
        else /*n>=3*/       return presses==1 ? 4 : presses==2 ? 7 : 8;
    }
};