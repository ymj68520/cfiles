#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class OrderedStream {
public:
    vector<string> stream;
    int ptr;
    OrderedStream(int n): ptr(1) {
        stream.resize(n + 1);
    }
    
    vector<string> insert(int idKey, string value) {
        stream[idKey] = value;
        if (idKey == ptr) {
            int right = idKey;
            for (int n = stream.size(); right < n; ++right) {
                if (stream[right] == "") break;
            }
            ptr = right;
            return vector<string> (stream.begin() + idKey, stream.begin() + right);
        }
        return vector<string> ();
    }
};