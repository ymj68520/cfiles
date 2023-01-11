#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution1 {    // 错误解答，连着1或者-1的时候出错
public:
    int captureForts(vector<int>& forts) {
        int p=0,q=0,n=forts.size();
        int ans = 0;
        while(p<n && q<n){
            while(p<n && forts[p]!=1) p++;
            q = p+1;
            while(q<n && forts[q]!=-1) q++;
            ans = max(ans, q-p-1);
            p++,q++;
        }
        p = q = 0;
        while(p<n && q<n){
            while(p<n && forts[p]!=-1)  p++;
            q = p+1;
            while(q<n && forts[q]!=1)   q++;
            ans = max(ans,q-p-1);
            p++,q++;
        }
        return ans;
    }
};

class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans=0;
        for(int i=0;i<forts.size();i++){
            if(forts[i]!=1) continue;
            int left=0;
            int right=0,j;
            for(j=i-1;j>=0&&forts[j]==0;j--);
            if(j>=0&&forts[j]==-1)
                left=i-j-1;
            for(j=i+1;j<forts.size()&&forts[j]==0;j++);
            if(j<forts.size()&&forts[j]==-1)
                right=j-i-1;
            ans=max(max(left,right),ans);
        }
        return ans;
    }
};

int main(){
    vector<int> num = {1,0,0,-1,0,0,0,0,1};
    Solution sol;
    cout << sol.captureForts(num) << endl;

    return 0;
}