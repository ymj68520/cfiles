#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(); //网格规模
        vector<int> a; //记录每一行后缀0个数的数组
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = n - 1; j >= 0; j--)
            {
                if(grid[i][j] == 0) count++; //数每一行的后缀0
                else break;
            }
            a.push_back(count); 
        }
        int count = 0; //交换次数
        for(int i = 0; i < n - 1; i++)
        {
            if(a[i] >= n - i - 1) continue;//满足条件，该行直接跳过
            else{//不满足条件
                int j = i; //用新参数遍历找满足条件的后缀0
                for(; j < n; j++)
                {
                    if(a[j] >= n - i - 1) break;
                }
                if(j == n) return -1; //找不到，直接返回-1
                for(; j > i; j--) //找到了最先满足条件的后缀0个数 
                {
                    swap(a[j], a[j - 1]); //每一行交换上去
                    count++; //记录交换次数
                }
            }
        }
        return count;
    }
};