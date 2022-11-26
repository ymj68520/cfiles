#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int sumSubarrayMins(vector<int>& arr){
    constexpr int MOD = (int)1e9+7;
    int n = arr.size();
    vector<int> left(n,-1);
    vector<int> right(n,n);
    stack<int> stk;
    for(int i=0;i<n;i++){
        while(!stk.empty() && arr[stk.top()]>=arr[i])   stk.pop();
        if(!stk.empty())    left[i] = stk.top();
        stk.push(i);
    }
    stk = stack<int>();
    for(int i=n-1;i>=0;i--){
        while(!stk.empty() && arr[stk.top()]>arr[i])    stk.pop();
        if(!stk.empty())    right[i] = stk.top();
        stk.push(i);
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans += (i-left[i])*(right[i]-i)*arr[i] % MOD;
        ans %= MOD;
    }
    return ans;
}

int main(){
    vector<int> arr = {3,1,2,4};
    cout << sumSubarrayMins(arr) << endl;

    return 0;
}