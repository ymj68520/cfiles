#include <iostream>

using namespace std;

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves=0;
        while(target > 1){
            if(maxDoubles == 0){
                return moves + target - 1;
            }
            if(target % 2){
                target --;
                maxDoubles--;
                moves ++;
            }
            else{
                target /= 2;
                moves ++;
            }
        }
        return moves;
    }
};