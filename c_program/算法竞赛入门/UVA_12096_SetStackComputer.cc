/*
有一个专门为了集合运算而设计的“集合栈”计算机。该机器有一个初始为空的栈，并且支持以下操作：
    1. PUSH：空集“{}”入栈
    2. DUP: 把当前栈顶元素复制一份后再入栈
    3. UNION：出栈两个集合，然后把二者的交集入栈
    4. INTERSECT：出栈两个集合，然后把二者的交集入栈
    5. ADD：出栈两个集合，然后把先出栈的集合加入到后出栈的集合中，把结果入栈
    每次操作后，输出栈顶集合的大小（元素个数）。
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#define ALL(x) x.begin(),x.end()        // 全迭代器
#define INS(x) inserter(x,x.begin())    // 插入迭代器

typedef std::set<int> Set;      // 集合的识别码（ID）的集合
std::map<Set,int> IDcache;      // 把集合映射为ID
std::vector<Set> Setcache;      // 根据ID取集合
// 对于任意集合s（上述定义的Set），IDcache[s]是它的ID，而Setcache[IDcache[s]]则是它本身

// 查找给定集合x的ID，如果没有则分配一个ID
int ID (const Set &x){
    if(IDcache.count(x))    return IDcache[x];  // x存在，返回其ID
    Setcache.push_back(x);  // 添加新集合，使用pushback时vector内部计数器会改变
    return IDcache[x] = Setcache.size()-1;  // 在IDcache中分配并返回 【（-1）从0开始】
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);    // 加速流
    std::stack<int> s;   // 题目中的栈--集合栈
    int N; std::cin >> N;   // 测试组数
    for(int l=0;l<N;l++){
        int n;  // 测试的操作数
        std::cin>>n;
        for(int i=0;i<n;i++){
            std::string op; // 操作字符串
            std::cin>>op;
            if(op[0]=='P')  s.push(ID(Set()));  // 空集合入栈
            else if(op[0]=='D')    s.push(s.top()); // 入栈栈顶元素
            else{
                Set x1 = Setcache[s.top()]; // 栈顶元素
                s.pop();   // 删除栈顶元素
                Set x2 = Setcache[s.top()];
                s.pop();
                Set x;  // 交并集合后的新集合
                if(op[0]=='U')  std::set_union(ALL(x1),ALL(x2),INS(x));
                if(op[0]=='I')  std::set_intersection(ALL(x1),ALL(x2),INS(x));
                if(op[0]=='A')  {
                    x = x2;
                    x.insert(ID(x1));
                }
                s.push(ID(x));
            }
            std::cout << Setcache[s.top()].size() << std::endl;
        }
    }
}