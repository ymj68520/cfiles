#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int findTheWinner(int n, int k) {
        bitset<500> bs;
        int pos = 0, d=k-1;
        while(bs.count() != n-1){
            pos += d;
            pos %= n;
            bs.set(pos,1);
        }
        return pos+1;
    }
};
/*
剩下最后一个数字的时候，总个数为 1，它的下标 pos=0。
那么它在上一轮也是安全的，总个数为 2，它的下标 pos=(0+m)%2； 
那么它在上上轮也是安全的，总个数为 3，它的下标 pos=((0+m)%2+m)%3；
那么它在上上上轮也是安全的，总个数为 4，它的下标 pos=(((0+m)%2+m)%3+m)%4;
 */
class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 2; i <= n; i++) ans = (ans + k) % i;
        return ans + 1;
    }
};

int main(){
    Solution sol;

    cout << sol.findTheWinner(5,3) << endl;
}