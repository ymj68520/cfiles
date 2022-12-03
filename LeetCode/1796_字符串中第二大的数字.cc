#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        priority_queue<int,vector<int>,greater<int>>    q;
        unordered_set<int> st;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                if(st.count(s[i]))  continue;
                st.insert(s[i]);
                q.push(s[i]);
            }
        }
        if(st.size() < 2) return -1;
        q.pop();
        return q.top() - '0';
    }
};