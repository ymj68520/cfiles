#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

class MinStack {
public:
    // 定义两个栈容器
    stack<int> st;
    stack<int> minStack;

    // 构造函数清空栈容器
    MinStack() {
        while(!st.empty()) {
            st.pop();
        }
        while(!minStack.empty()) {
            minStack.pop();
        }
        // 初始化最小栈的栈顶元素为最大值为了防止top访问空指针报错
        minStack.push(INT_MAX);
    }
    
    void push(int x) {
        st.push(x);
        // 比较最小栈的栈顶的值和当前值val的大小，将最小值押入最小栈也就是记录了当前st栈的最小值为栈顶元素
        int minVal = std::min(minStack.top(), x);
        // 将最小值押入最小栈
        minStack.push(minVal);
    }
    
    void pop() {
        // 弹出两个栈的栈顶元素
        st.pop();
        minStack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        // 取最小栈的栈顶元素就是此时st栈的最小值
        return minStack.top();
    }
};
