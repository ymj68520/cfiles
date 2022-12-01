#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cnt = 0;
        for (int i = 0; i < 3; i ++ )
            for (int j = 0; j < 3; j ++ )
                if (board[i][j] != ' ') 
                    cnt += (board[i][j] == 'X') ? 1 : -1;
        if (cnt < 0 || cnt > 1) return false;

        bool flagX = check(board, 'X'), flagO = check(board, 'O');
        if (flagX && cnt <= 0) return false;
        if (flagO && cnt >= 1) return false;

        if (flagX && flagO) return false;
        return true;
    }

    bool check(vector<string>& board, char c)
    {
        bool flag = 0;
        for (int i = 0; i < 3; i ++ )
            if (board[i][0] == c && board[i][1] == c && board[i][2] == c) flag = 1;
        for (int i = 0; i < 3; i ++ )
            if (board[0][i] == c && board[1][i] == c && board[2][i] == c) flag = 1;
        if (board[0][0] == c && board[1][1] == c && board[2][2] == c) flag = 1;
        if (board[0][2] == c && board[1][1] == c && board[2][0] == c) flag = 1;
        return flag;
    }
};