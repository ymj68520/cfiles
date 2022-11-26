#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> findTopKinTwoSortedArray(vector<int>& arr1, vector<int>& arr2, int k) {
    // write code here
    int m = arr1.size();int n = arr2.size();
    // count == t
    int curmax,notmax,flag;
    if(arr1[m-1]>arr2[n-1]){
        curmax = arr1[m-1];
        notmax = arr2[n-1];
        flag = 0;
    }else{
        curmax = arr2[n-1];
        notmax = arr1[m-1];
        flag = 1;
    }
    vector<int> & p = (flag)? arr2 : arr1;
    vector<int> & q = (flag)? arr1 : arr2;
    vector<int> ret;
    notmax = q.size()-1;
    for(int i=p.size()-1;i>=0;i--){
        curmax = i;
        for(int j=q.size()-1;j>=0;j--){
            while(p[curmax]+q[j] > p[curmax-1]+q[notmax] && j){
                ret.push_back(p[curmax]+q[j]);
                j--;k--;
                if(!k)  return ret;
            }
            if(j==0)    continue;
            if(p[curmax]+q[j] == p[curmax-1]+q[notmax]){
                if(k-->1){ ret.push_back(p[curmax]+q[j]);ret.push_back(p[curmax]+q[j]);}
                else if(k-->0){ ret.push_back(p[curmax]+q[j]); return ret;}
            }
            while(p[curmax-1]+q[notmax] > p[curmax]+q[j]){
                ret.push_back(p[curmax-1]+q[notmax]);
                notmax--;k--;
                if(!k)  return ret;
            }
            if(j++ != 0)    continue;
        }
    }
    return ret;

}
vector<int> findTopKinTwoSortedArray1(vector<int>& arr1, vector<int>& arr2, int k){
    vector<int> ret;
    int maxsum=0;
    for(int i=arr1.size()-1;i>=0;i--){
        for(int j=arr2.size()-1;j>=0;j--){
            maxsum = max(maxsum,arr1[i]+arr2[j]);
        }
        ret.push_back(maxsum);
    }
    return ret;
}