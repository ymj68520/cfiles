#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
/*
请编写程序，输入Excel中的行与列的索引值，求其对应的单元格编号。
示例：
* 行1，列1，编号：A1
* 行2，列2，编号：B2
* 行11，列3，编号：C11
* 行12，列27，编号：AA12
* 行13，列28，编号：AB13
如果行或列的索引小于1，返回"error"
*/
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)==2){
        if(m<1 || n <1){cout << "error"; return -1;}
        int a_count = n/26;
        int a_left = n%26;
        string ret = "";
        while(a_count > 0){ret += "A"; a_count--;}
        ret += 'A'+a_left-1;
        ret += to_string(m);
        cout << ret;
    }
    return 0;
}