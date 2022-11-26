#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// string 慢 sstring 更慢 谨慎使用
int main(){
    string line;	// 无需指定大小
    while(getline(cin,line)){	// getline()的一种重载，cin作为参数，从标准输入读取一行到参数2（line），相当于fgets()
        int sum = 0,x;
        stringstream ss(line);	// 创建一个字符串流，将string当做流进行读写 ss相当于cin
        while(ss>>x) sum+=x;	// 从创建的string流中读数据
        cout << sum << "\n";
    }
    return 0;
}