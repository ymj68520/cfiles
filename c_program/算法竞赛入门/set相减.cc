#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
int main(){
    set<int> A,B,c;
    int m,n;
    cin >> m >> n;
    if(m==0){
        cout << 0 << ' ';
        return 0;
    }
    int temp;
    for(int i=0;i!=m;i++){
        cin >> temp;
        A.insert(temp);
    }
    for(int i=0;i!=n;++i){
        cin >> temp;
        B.insert(temp);
    }
    set_difference(A.begin(),A.end(),B.begin(),B.end(),insert_iterator<set<int>>(c, c.begin()));
    for(set<int>::iterator it=c.begin();it!=c.end();it++)
        cout << *it << ' ';
    return 0;
}