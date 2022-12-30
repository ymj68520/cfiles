#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <utility>

using namespace std;

int N;

int dist(const pair<int,int> &a){
        auto [l,r] = a;
        if(l==-1 || r==N)   return r-l-1;
        return (r-l) >> 1;
    }
struct cmp{
    bool operator () (const pair<int,int> &a, const pair<int,int> &b)const{
        int d1 = dist(a), d2 = dist(b);
        return d1==d2 ? a.first < b.first : d1 > d2; 
    }
};

class ExamRoom {
private:
    int n;

    set<pair<int,int>, cmp> st;
    unordered_map<int, int> right;
    unordered_map<int, int> left;
    
    void add(pair<int,int> a){
        st.insert(a);
        left[a.second] = a.first;
        right[a.first] = a.second;
    }

    void del(pair<int,int> b){
        st.erase(b);
        left.erase(b.second);
        right.erase(b.first);
    }

public:
    ExamRoom(int n) {
        N = n;
        this->n = n;
        add({-1,N});
    }
    
    int seat() {
        auto s = *st.begin();
        int pos = (s.first + s.second) >> 1;
        if(s.first == -1)   pos = 0;
        else if(s.second== n)    pos = n-1;
        del(s);
        add({s.first,pos});
        add({pos,s.second});
        return pos;  
    }
    
    void leave(int p) {
        int l = left[p], r=right[p];
        del({l,p});
        del({p,r});
        add({l,r});
    }
};
