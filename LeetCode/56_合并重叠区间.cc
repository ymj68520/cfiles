#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static bool cmp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size()<2)  return intervals;
    sort(intervals.begin(),intervals.end(), cmp);
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<=intervals[i-1][1]){
            intervals[i-1][1] = max(intervals[i][1],intervals[i-1][1]);
            intervals.erase(intervals.begin()+i);
            i--;
        }
    }
    return intervals;
}

int main(){
    vector<vector<int> > d = {{1,4},{0,2},{3,5},{15,18}};
    d = merge(d);
    for(int i=0;i<d.size();i++)
        cout << d[i][0] << ',' << d[i][1] << endl;

    return 0;
}