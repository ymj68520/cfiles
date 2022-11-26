#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main (){
    int temp(4);
    vector<int> a(4,1);
    temp = a.size();
    cout << temp <<endl;
    a.push_back(2);
    temp = a.size();
    cout << temp << endl;
    for(vector<int>::size_type i=0;i != a.size();++i){
        cout << a[i] << endl;
    }
    string st("abc");
    st += "def";
    for(string::size_type i=0; i != st.size(); ++i){
        cout << st[i] <<endl;
    }
    string str;
    getline(cin,str);
    for(string::iterator i = str.begin(); i!=str.end(); ++i){
        cout << *i <<endl;
        
    }

    return 0;
}