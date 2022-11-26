#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int count(vector<int> A, int n) {
    // write code here
    int t=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(A[i]>A[j])   t++;
        } 
    }
    return t;
}
int main(){
    vector<int> A = {1,2,0};
    cout << count(A,3) << endl;

    return 0;
}