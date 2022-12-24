#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<int,vector<string> > ans;
        int m = list1.size(), n = list2.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(list1[i] == list2[j])
                    ans[i+j].push_back(list1[i]);
            }
        }
        return ans.begin()->second;
    }
};