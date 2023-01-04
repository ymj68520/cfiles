#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct node{
        int val,l,r;
    }t[740005];
    void build(int l,int r,int p){
        t[p].l = l,t[p].r = r;
        if(t[p].l==t[p].r)return;
        int m = (l+r)>>1;
        build(l,m,p<<1);
        build(m+1,r,p<<1|1);
    }
    void modify(int x,int p,int val){
        if(t[p].l==t[p].r){
            t[p].val = val;
            return ;
        }
        int m = (t[p].l+t[p].r)>>1;
        if(x<=m)modify(x,p<<1,val);
        else modify(x,p<<1|1,val);
        t[p].val = max(t[p<<1].val,t[p<<1|1].val);
    }
    int query(int l,int r,int p){
        if(l<=t[p].l&&t[p].r<=r){
            return t[p].val;
        }
        else{
            int res= 0;
            int m = (t[p].l+t[p].r)>>1;
            if(l<=m)res = query(l,r,p<<1);
            if(r>m)res = max(res,query(l,r,p<<1|1));
            return res;
        }
    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int> >o(n,vector<int>(2));
        for(int i = 0; i < n;++i){
            o[i][0] = obstacles[i];
            o[i][1] = i;
        }
        sort(o.begin(),o.end(),[&](auto& p1,auto& p2){
            return p1[0]<p2[0];
        });
        int key =  o[0][0];
        o[0][0] = 1;
        for(int i = 1; i < n;++i){
            
            if(o[i][0]>key){
                key = o[i][0];
                o[i][0] = o[i-1][0]+1;
            }
            else
                o[i][0] = o[i-1][0];
    
        }
        sort(o.begin(),o.end(),[&](auto& p1,auto& p2){
            return p1[1]<p2[1];
        });
        build(1,200005,1);
        vector<int>k(n);
        int res = 0;
        for(int i = 0; i < n;++i){
            int val = o[i][0];
            res = 1+query(1,val,1);
            k[i] = res;
            modify(val,1,res);
        }
        return k;
    }
};
