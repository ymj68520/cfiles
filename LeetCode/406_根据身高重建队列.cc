#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(),people.end(),[](vector<int>&p1, vector<int>&p2){
        return p1[0]==p2[0] ? p1[1]<p2[1] : p1[0]>p2[0];
    });
    vector<vector<int>> ans;
    for (vector<int>& p : people)
        ans.insert(ans.begin() + p[1], p);
    return ans;
}

