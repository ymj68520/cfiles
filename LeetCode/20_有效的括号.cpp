#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    char t;
    for(int i=0;i<s.size();i++){
        t = s[i];
        switch(t){
            case '(':
            case '[':
            case '{':
                st.push(t);
                break;
            case ')':
                if(st.size() && st.top()=='(' )   st.pop();
                else    return false;
                break;
            case ']':
                if(st.size() && st.top()=='[')   st.pop();
                else    return false;
                break;
            case '}':
                if(st.size() && st.top()=='{')   st.pop();
                else    return false;
                break;
        }
    }
    if(st.size()!=0)
        return false;
    return true;
}

int main(){
    string s = "}{";
    cout << isValid(s) << endl;

    return 0;
}