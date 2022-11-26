#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        string ans;
        int n = command.length();
        for(int i=0;i<n;){
            if(command[i] == 'G'){
                ans.push_back('G');
                i++;
            }
            else if(i+1<n && command[i+1] == ')'){
                ans.push_back('o');
                i+=2;
            }
            else{
                ans.append("al");
                i+=4;
            }
        }
        return ans;
    }
};