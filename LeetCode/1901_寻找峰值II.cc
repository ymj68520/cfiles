#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int l=0, r=m-1;
        while(l<r){
            int mid = (l+r) >> 1;
            int m1 = *max_element(mat[mid].begin(), mat[mid].end());
            int m2 = *max_element(mat[mid+1].begin(), mat[mid+1].end());
            if(m1 > m2) r = mid;
            else l = mid + 1;
        }
        int index = max_element(mat[r].begin(),mat[r].end()) - mat[r].begin();
        return {r, index};
    }
};

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        srand(3214567);
        for(int i=rand()%n,j=rand()%m; i>=0 && j>=0 && i<n && j<m;) {// should not go out of bound
		    // we set -1 if we go out of bound for any direction
            int up    = (i-1<0)  ? -1 : mat[i-1][j];
            int right = (j+1>=m) ? -1 : mat[i][j+1];
            int down  = (i+1>=n) ? -1 : mat[i+1][j];
            int left  = (j-1<0)  ? -1 : mat[i][j-1];
		    //as soon we get any peak element we return it's coordinates
            if(mat[i][j]>up && mat[i][j]>left && mat[i][j]>down && mat[i][j]>right) return {i,j};         
		    //else we take max of all 4 directions
            int x=max({up,right,down,left});
		    // max was present in whichever direction we go to that respective coordinate
            if(up==x) i--;
            else if(right==x) j++;
            else if(down==x) i++;
            else j--;
        }
        return {}; // this case will never happen but as return type is vector we ned to return empty
    }
};