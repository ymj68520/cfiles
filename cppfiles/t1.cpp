#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main (){
    int i(1);       //直接初始化
    int b = 6;
    vector<int> s(2,1);
    vector<int> a;

    cout << i << s[0]+i << endl;

    s.push_back(b);
    bool c = a.empty();
    cout << c<<endl;
    for(int j =0; j!=3;j++)
        cout<<s[j]<<endl;

    return 0;
}
