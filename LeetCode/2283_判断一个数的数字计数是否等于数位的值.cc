#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool digitCount(string num)
    {
        vector<int> nums(10, 0);
        for (const char &c : num)
            nums[c - '0']++;
        for (int i = 0; i < num.size(); ++i)
        {
            if (nums[i] != num[i] - '0')
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "1210";
    cout << sol.digitCount(s) << endl;

    return 0;
}