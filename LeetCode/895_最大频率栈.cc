#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;


class FreqStack {
private:
    unordered_map<int,int> cnt;
    vector<stack<int>> sts;
public:
    FreqStack() {
        cnt.clear();
        sts.clear();
    }
    
    void push(int val) {
        if(cnt[val] == sts.size())  sts.push_back({});
        sts[cnt[val]].push(val);
        ++cnt[val];
    }
    
    int pop() {
        int val = sts.back().top();
        sts.back().pop();
        if(sts.back().empty())    sts.pop_back();
        --cnt[val];
        return val;
    }
};

int main(){
    FreqStack mys;
    mys.push(1);
    mys.push(2);
    mys.push(1);
    cout << mys.pop() << endl;
    mys.push(3);
    mys.push(3);
    mys.push(3);
    cout << mys.pop() << endl;
    cout << mys.pop() << endl;
    return 0;
}