#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int> a, vector<int> b)->bool{return a[1] > b[1];});
        
        int maxSize=0;
        for(int i=0;i<boxTypes.size() && truckSize>=0; ++i){
            int needSzie = (truckSize > boxTypes[i][0]) ? boxTypes[i][0] : truckSize;
            maxSize += needSzie * boxTypes[i][1];
            truckSize -= needSzie;
        }
        return maxSize;
    }
};

int main(){
    vector<vector<int> > box = {{1,3},{2,2}};
    int size = 4;
    Solution sol;
    cout << sol.maximumUnits(box,size) << endl;

    return 0;
}