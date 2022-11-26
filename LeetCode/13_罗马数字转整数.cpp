#include <iostream>
#include <string>
using namespace std;

int which(char ch) {
    switch(ch) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        case 'a': return 4;
        case 'b': return 9;
        case 'c': return 40;
        case 'd': return 90;
        case 'e': return 400;
        case 'f': return 900;
    }
    return 0;
}

int romanToInt(string s) {
    while(s.find("IV")!=string::npos)
        s = s.replace(s.find("IV"),2,"a");
    while(s.find("IX")!=string::npos)
        s = s.replace(s.find("IX"),2,"b");
    while(s.find("XL")!=string::npos)
        s = s.replace(s.find("XL"),2,"c");
    while(s.find("XC")!=string::npos)
        s = s.replace(s.find("XC"),2,"d");
    while(s.find("CD")!=string::npos)
        s = s.replace(s.find("CD"),2,"e");
    while(s.find("CM")!=string::npos)
        s = s.replace(s.find("CM"),2,"f");
    int result = 0;
    for (int i=0; i<s.length(); i++) {
        result += which(s[i]);
    }
    return result;
}

int main(){
    string s = "IX";
    cout << romanToInt(s) << endl;

    return 0;
}
