#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

class MyStack {
public:
    queue<int> q0;
    queue<int> q1;
    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);
        while(!q0.empty()){
            q1.push(q0.front());
            q0.pop();
        }
        swap(q0,q1);
    }
    
    int pop() {
        int t = q0.front();
        q0.pop();
        return t;
    }
    
    int top() {
        return q0.front();
    }
    
    bool empty() {
        return q0.empty();
    }
};

class MyStack1{
    queue<int> q;
    MyStack1() {

    }
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i=0;i<size;i++){
            int t = q.front();
            q.pop();
            q.push(t);
        }
    }
    int pop(){
        int t = q.front();
        q.pop();
        return t;
    }
    int top(){
        return q.front();
    }
    bool empty(){
        return q.empty();
    }
};