/*
    丑数是指不能被2 3 5以外的其他素数整除的数。把丑数从小到大排列起来，结果如下：
        1,2,3,4,5,6,8,9,10,12,15……
    求第1500个丑数。

    最小的丑数为“1”。而对于任意的丑数a,2a,3a,5a均为丑数。（可以用素数性质证明）
    使用优先队列保存已生成的丑数，每次取出最小的丑数，生成三个新的丑数。
    因为可能存在重复生成的问题，因此需要判断。

*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long LL;
const int coeff[3] = {2,3,5};

int main(){
    priority_queue<LL,vector<LL>,greater<LL> > pq;  // greater 表示越小越优先
    set<LL> s;
    pq.push(1);
    s.insert(1);
    for(int i=1;;i++){
        LL x = pq.top();pq.pop();
        if(i==1500){
            cout << "The 1500`th ugly number is: " << x << endl;
            break;
        }
        for(int j=0;j<3;j++){
            LL x2 = x*coeff[j];
            if(!s.count(x2)){s.insert(x2);pq.push(x2);}
        }
    }
    return 0;
}
