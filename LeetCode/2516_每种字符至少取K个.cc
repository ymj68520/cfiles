#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution1
{
public:
    int takeCharacters(string s, int k)
    {
        int a(0), b(0), c(0), n(s.size());
        for (const char &ch : s)
            if (ch == 'a')
                a++;
            else if (ch == 'b')
                b++;
            else
                c++;
        if (a < k || b < k || c < k)
            return -1;
        a -= k, b -= k, c -= k;
        int nums[3]{0, 0, 0}, check[]{a, b, c};
        int ans = INT_MAX;
        for (int i = 0, j = 0; j < n; ++j)
        {
            nums[s[j] - 'a']++;
            if (nums[s[j] - 'a'] > check[s[j] - 'a'])
                while (nums[s[j] - 'a'] > check[s[j] - 'a'])
                {
                    nums[s[i] - 'a']--;
                    i++;
                }
            ans = min(n - j + i - 1, ans);
        }
        return ans;
    }
};

class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        int n = s.size();
        int target[3]{-k, -k, -k};
        for (auto i : s)
            target[i - 'a']++;
        if (target[0] < 0 || target[1] < 0 || target[2] < 0)
            return -1;
        int ans = INT_MAX;
        int copy[3]{0,0,0};
        for (int l = 0, r = 0; r < n; r++)
        {
            copy[s[r] - 'a']++;
            while (r < n && copy[s[r] - 'a'] > target[s[r] - 'a'])
            {
                copy[s[l++] - 'a']--;
            }
            ans = min(ans, (n - r + l - 1));
        }
        return ans;
    }
};