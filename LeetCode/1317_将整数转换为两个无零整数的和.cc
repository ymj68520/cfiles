#include "LeetCode.h"

class Solution1 {
public:
    vector<int> getNoZeroIntegers(int n) {
        if(n<11)    return {1,n-1};
        string str = to_string(n);
        int ans = 0,i=0;
        i = str.find('0');
        if(i==-1){
            if(str[str.length()-1] == '1')
                i = str.find('1',1);
            if(i==-1)   return {1,n-1};
        }
        for(;i<str.length();++i){
            ans = ans*10 + str[i]-'0';
        }
        return {ans+1,n-ans-1};
    }
};

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        if(n<11)    return {1,n-1};
        int len = to_string(n).length()-1;
        
        int n1 = pow(10,len)-1; // 转换为最大的len位数字
        int n2 = n - n1;        // n1 与 n2 互补

        // 寻找n2中的0，然后补
        for(int temp=n2,i=1;temp>0;i*=10,temp/=10)
            if(temp%10 == 0) n1-=i,n2+=i;

        return {n1,n2};
    }
};

int main(){
    vector<int> ans;
    Solution sol;
    ans = sol.getNoZeroIntegers(69);
    for(auto x:ans) cout << x << " ";
    cout << endl;

    return 0;
}