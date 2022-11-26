#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int spareGas = 0;
        int minSpare = INT_MAX;
        int minIndex = 0;

        for(int i=0;i<len;++i){
            spareGas += gas[i]-cost[i];
            if(spareGas < minSpare){
                minSpare = spareGas;
                minIndex = i;
            }
        }
        return spareGas < 0 ? -1 : (minIndex+1)%len;
    }
};

int main(){
    vector<int> gas = {1,2,4};

    Solution sol;

    cout << sol.canCompleteCircuit(gas,gas) << endl;

    return 0;
}