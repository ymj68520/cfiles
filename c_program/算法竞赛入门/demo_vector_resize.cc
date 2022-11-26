#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> a;
    for(int i=0;i<3;i++)
        a.push_back(i); // 插入数据，大小自增
    for(vector<int>::iterator it=a.begin();it!=a.end();it++)    // 使用迭代器遍历
        cout << *it << ' ';
    cout << endl;
    a.resize(4);    // c重新设置大小，末尾未使用的部分用0填充
    for(vector<int>::iterator it=a.begin();it!=a.end();it++)
        cout << *it << ' ';
    cout << endl;
    a[3] = 3; // 修改末尾重新设定的大小
    for(vector<int>::iterator it=a.begin();it!=a.end();it++)
        cout << *it << ' ';
    cout << endl;
    a.resize(3);
    for(vector<int>::iterator it=a.begin();it!=a.end();it++) // 重设大小后原始数据并没有丢失
        cout << *it << ' ';
    cout << endl;
    cout << a[3] << endl;
    a[5] = 4;   // 可以直接使用后面未定义部分，但是无法用迭代器访问，可能存在未知问题
    cout << a[5] << a[6] << endl; // 未定义部分存储垃圾数据
    return 0;
}