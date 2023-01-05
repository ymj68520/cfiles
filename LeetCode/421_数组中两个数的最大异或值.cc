#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int findMaximumXOR(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long maxValue = 0;
        for (int i = n -1; i >= 1; i--) {
            for (int j = i -1; j >= 0; j--) {
                if ((long long)(nums[i]) + nums[j] < maxValue) {
                    break;
                }
                maxValue = max(maxValue, (long long)(nums[i] ^ nums[j]));
            }
        }
        return maxValue;

    }
};

class Trie{
public:
    Trie* next[2];
    Trie(){
        memset(next, 0, sizeof(next));
    }
};
class Solution {
    Trie *root = new Trie, *node;
public:
    int findMaximumXOR(vector<int>& nums) {
        for(int &num : nums){
            node = root;
            for(int i=30; i>=0; --i){
                int b = (num >> i) & 1;
                if(node->next[b] == nullptr)    node->next[b] = new Trie;
                node = node->next[b];
            }
        }
        int ans = 0, sum;
        for(int &num : nums){
            node = root;
            sum = 0;
            for(int i=30; i>=0; --i){
                int b = (num >> i) & 1;
                if(b){
                    sum += node->next[0] ? 1<<i : 0;
                    node = node->next[0] ? node->next[0] : node->next[1];
                }
                else{
                    sum += node->next[1] ? 1<<i : 0;
                    node = node->next[1] ? node->next[1] : node->next[0];
                }
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};

