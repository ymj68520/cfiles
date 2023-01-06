#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int n = nums.size(), cnt = 0;;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int t = nums[i] ^ nums[j];
                if(t<low || t > high)  continue;
                cnt++;
            }
        }
        return cnt;
    }
};

const int N = 20005;
int trie[N * 15][2], cnt[N * 15], idx;
class Solution { 
public:
    int countPairs(vector<int>& nums, int low, int high) {
        return get(nums, high) - get(nums, low - 1);
    }
    int get(vector<int>& nums, int high) {
        idx = 0;
        memset(trie, 0, sizeof(trie));
        memset(cnt, 0, sizeof(cnt));
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += query(nums[i], high);
            add(nums[i]); 
        }
        return ans;
    }
    void add(int x) {
        int p = 0;
        for (int i = 14; i >= 0; i--) {
            int u = (x >> i)  & 1;
            if (trie[p][u] == 0) trie[p][u] = ++idx;
            p = trie[p][u]; //移动到下一个结点 
            cnt[p]++; // 个数增加，cnt[x]代表x结点出现的次数
        }
    }
    int query(int x, int high) {
        int sum = 0, p = 0;
        for(int i = 14; i >= 0; i--){
            int u = (x >> i) & 1;
            if (((high >> i) & 1) == 1) { //high当前i位为1, 那么x与以前数当前i位的异或可以位1或者0
                sum += cnt[trie[p][u]];//加上与x异或后当前i位为0的数量
                if (trie[p][u ^ 1] == 0) return sum; //没有结点可以继续走下去，直接返回
                p = trie[p][u ^ 1]; //继续往异或的结点走下去
            } else { //high当前i位为0, x与以前数异或的第i为必须为0
                if (trie[p][u] == 0) return sum; //没有结点走下去
                p = trie[p][u]; //寻找与x的第i位相同的进制，异或结果为0
            }
        }
        sum += cnt[p]; //加上走到最后的结点数
        return sum;
    }
};

