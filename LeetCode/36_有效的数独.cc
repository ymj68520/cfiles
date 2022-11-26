#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    bool rows[9][10];memset(rows,0,sizeof(rows));
    bool cols[9][10];memset(cols,0,sizeof(cols));
    bool boxs[9][10];memset(boxs,0,sizeof(boxs));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j] == '.')  continue;
            int num = board[i][j] - '0';
            if(rows[i][num] || cols[j][num] || boxs[j/3+(i/3)*3][num])    return false;
            rows[i][num] = cols[j][num] = boxs[j/3+(i/3)*3][num] = true;
        }
    }
    return true;
}
