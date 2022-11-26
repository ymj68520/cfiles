#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int i=0,j=n-1;
    while(i<m && target < matrix[i][0]) ++i;
    if(i==m)    return false;
    if(target > matrix[i][j] && i+1<m && target <matrix[i+1][0]) return false;
    while(j>=0 && target < matrix[i][j]) j--;
    if(j==-1)   return false;
    if(target == matrix[i][j])  return true;
    return false;
}
bool searchMatrix2(vector<vector<int>>& matrix, int target){
    int m = matrix.size();
    int n = matrix[0].size();
    int i=0,j=n-1;
    while(i<m && j>=0){
        if(target == matrix[i][j])  return true;
        if(target < matrix[i][j])   i++;
        if(target > matrix[i][j])   j--;
    }
    return false;
}
bool searchMatrix3(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
    // 右上角开始查找
    for(int i = 0, j = col-1; i < row && j >= 0;) {
        if(matrix[i][j] == target) 
            return true;
        else if(matrix[i][j] > target) 
            j--;
        else if(matrix[i][j] < target)
            i++;
    }
    return false;
}
int main(){
    vector<vector<int> > matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    // vector<vector<int> > matrix = {{1}};
    int target = 3;
    cout << searchMatrix(matrix,target) << endl;

    return 0; 
}