#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MODULO = 1000000007;
        int odd = 0, even = 1;
        int subarrays = 0;
        int sum = 0;
        int length = arr.size();
        for (int i = 0; i < length; i++) {
            sum += arr[i];
            subarrays = (subarrays + (sum % 2 == 0 ? odd : even)) % MODULO;
            if (sum % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        return subarrays;
    }
};

int main(){
    vector<int> arr = {1,3,5};
    Solution sol;
    cout << sol.numOfSubarrays(arr) << endl;

    return 0;
}