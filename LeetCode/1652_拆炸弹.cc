#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n,0);
        if(k==0)    return ans;
        if(k>0){
            for(int i=0;i<n;i++){
                int pos=(i+1)%n,cnt=k;
                while(cnt-- > 0){
                    ans[i]+=code[pos];
                    pos = (pos+1)%n;
                }
            }
        }
        else{
            for(int j=0;j<n;j++){
                int pos=(j-1+n)%n,cnt=k;
                while(cnt++ < 0){
                    ans[j]+=code[pos];
                    pos = (pos-1+n)%n;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> code = {2,4,9,3};
    int k = -2;
    Solution sol;

    vector<int> ans = sol.decrypt(code,k);
    for(auto x:ans) cout << x << " ";
    cout << endl;
}