#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
    bool canArrive(int x,int y, int a, int b, vector<pair<int, int> > &route){
        int d = min((int)x/a, (int)y/b);
        x -= a*d;
        y -= b*d;
        for(auto &r : route){
            if(r.first == x && r.second == y)   return true;
        }
        return false;
    }
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        vector<pair<int,int> > route;
        route.push_back({0,0});
        int a=0,b=0;
        for(auto &c : command){
            if(c=='U')  b++;
            else    a++;
            route.push_back({a,b});
        }
        for(auto &o : obstacles){
            if(o[0] > x || o[1] > y)    continue;
            if(canArrive(o[0],o[1],a,b,route))
                return false;
        }
        if(!canArrive(x,y,a,b,route))   return false;
        return true;
    }
};