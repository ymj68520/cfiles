#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    bool r0 = false;
    for(int i=0;i<col;i++)  if(matrix[0][i] == 0){r0=true;break;}   
    bool c0 = false;
    for(int i=0;i<row;i++)  if(matrix[i][0] == 0){c0=true;break;}

    for(int i=1;i<row;i++)  for(int j=1;j<col;j++)
        if(matrix[i][j]==0){
            matrix[i][0] = 0;
            matrix[0][j] = 0;
        }

    for(int i=1;i<row;i++)  if(matrix[i][0] == 0)
        for(int j=0;j<col;j++)
            matrix[i][j] = 0;
    for(int j=1;j<col;j++)  if(matrix[0][j] == 0)
        for(int i=0;i<row;i++)
            matrix[i][j] = 0;

    if(r0)  for(int j=0;j<col;j++)
        matrix[0][j] = 0;
    if(c0)  for(int i=0;i<row;i++)
        matrix[i][0] = 0;
}

int main(){
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(matrix);
    for(auto x:matrix){
        for(auto y:x){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}