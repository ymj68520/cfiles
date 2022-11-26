#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string largestNumber(vector<int>& nums) {
    vector<string> temp;
    for(int x:nums)    temp.push_back(to_string(x));
    sort(temp.begin(),temp.end(), [](string &a, string &b){return a+b > b+a;});
    if(temp[0] == "0")  return "0";
    string ans = "";
    for(string x:temp)  ans += x;

    return ans;
}

int main(){
    vector<int> nums = {9,10,1,3,34,33};
    cout << largestNumber(nums) << endl;

    return 0;
}
