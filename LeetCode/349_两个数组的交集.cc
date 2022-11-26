#include <iostream>
#include <algorithm>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    vector<int> ans;
    int i=0,j=0;
    while(i!=nums1.size()-1 && j!=nums2.size()-1){
        if(nums1[i]==nums2[j]){
            ans.push_back(nums1[i]);
            while(nums1[i] == nums1[i+1])   i++;i++;
            while(nums2[j] == nums2[j+1])   j++;j++;
        }  
        else if(nums1[i]<nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int> n1={1,2,3,4,5,6,7,8,9};
    vector<int> n2={1,1,1,5,5,7,8,9};
    vector<int> as = intersection(n1,n2);

    for(auto x:as)  cout << x << ' ';
    cout << endl;

    return 0;
}