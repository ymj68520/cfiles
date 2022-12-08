#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        while(num.size() && num.back()%2==0)   num.pop_back();
        return num;
    }
};