#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        int pos1(version1.find('.')),pos2(version2.find('.'));
        v1.push_back(stoi(version1.substr(0,pos1)));
        v2.push_back(stoi(version2.substr(0,pos2)));
        int t = version1.find('.',pos1+1);
        while(t != -1){
            v1.push_back(stoi(version1.substr(pos1+1,t)));
            pos1 = t;
            t = version1.find('.',pos1+1);
        }
        v1.push_back(stoi(version1.substr(pos1+1)));
        t = version2.find('.',pos2+1);
        while(t != -1){
            v2.push_back(stoi(version2.substr(pos2+1,t)));
            pos2 = t;
            t = version2.find('.',pos2+1);
        }
        v2.push_back(stoi(version2.substr(pos2+1)));
        if(v1.size()>v2.size())
            for(pos1=v2.size(),v2.resize(v1.size());pos1<v1.size();pos1++)
                v2[pos1] = 0;
        if(v1.size()<v2.size())
            for(pos1=v1.size(),v1.resize(v2.size());pos1<v2.size();pos1++)
                v1[pos1] = 0;
        for(pos2=0;pos2<v1.size();pos2++){
            if(v1[pos2]>v2[pos2])   return 1;
            if(v1[pos2]<v2[pos2])   return -1;
        }
        return 0;
    }
    int compareVersion2(string version1, string version2){
        int i = 0, j = 0;
        while( i<version1.size() || j<version2.size() ) {
            long long v1 = 0, v2 = 0;
            while(i<version1.size()&&version1[i]!='.') 
                v1 = v1*10 + version1[i]-'0', ++i;
            while(j<version2.size()&&version2[j]!='.') 
                v2 = v2*10 + version2[j]-'0', ++j;
            if(v1 != v2) return v1>v2? 1: -1;
            ++i, ++j;
        }
        return 0;
    }
};

int main(){
    Solution sol;
    string v1 = "1.0.1";
    string v2 = "1";
    cout << sol.compareVersion2(v1,v2) << endl;

    return 0;
}