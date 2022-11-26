#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    int len = 0;
    int pos = s.length()-1;
    while(pos>=0 && s[pos]==' ' )
        pos--;
    while(pos>=0 && s[pos]!=' ' ){
        len++;
        pos--;
    }
    return len;
}

int main(){
    string s = "a";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}
