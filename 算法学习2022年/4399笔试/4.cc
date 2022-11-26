#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int maxDistance(vector<int>& arr) {
    // write code here
    sort(arr.begin(),arr.end());
    int maxdis = 0;
    for(int i=1;i<arr.size();i++){
        maxdis = max(arr[i]-arr[i-1],maxdis);
    }
    return maxdis; 
}

int main(){

}