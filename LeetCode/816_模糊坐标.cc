#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<string> getNums(string num){
        vector<string> list;
        int i=1;
        string left,right;
        while(i<=num.length()){
            left = num.substr(0,i);
            right = num.substr(i++);
            // if( (!(left.length() == 1 && left[0]=='0') && left[0] == '0')
            //     ||(right.length()!=0 && right[right.length()-1]!='0') )
            if((!(left.length() == 1 && left[0] == '0') && left[0] == '0') 
            || (right.length() != 0 && right[right.length() - 1] == '0'))
                continue;
            if(right.length()==0)
                list.push_back(left);
            else
                list.push_back(left+"."+right);
        }
        return list;
    }
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        s = s.substr(1,s.length()-2);
        for(int i=1; i<s.length();i++){
            for(const string &x:getNums(s.substr(0,i)))
                for(const string &y:getNums(s.substr(i)))
                    ans.push_back("("+x+","+y+")");
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "(123)";
    for(auto &x : sol.ambiguousCoordinates(s)){
        cout << x;
        cout << endl;
    }
}