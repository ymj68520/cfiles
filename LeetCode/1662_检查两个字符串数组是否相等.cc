#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string s1 = "";
    string s2 = "";
    for(string x:word1)
        s1 += x;
    for(string y:word2)
        s2 += y;
    return s1==s2;
}