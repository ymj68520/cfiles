#include <iostream>
#include <vector>
using namespace std;
// 输入
// A:FB;B:GC;D:GC;F:AGH;E:HD
// #
vector<vector<int> > edg;
vector<int> vex;
vector<int> dis;
void inputSolver(){
    char c = getchar();
    while(c != '\n'){
        vex.push_back(c-'A');
        getchar();
        vector<int> t;
        c = getchar();
        while(c!=';' && c!='\n'){
            t.push_back(c-'A');
            c = getchar();
        }
        edg.push_back(t);
        if(c=='\n') return;
        c = getchar();
    }
    getchar();
}
void getdis(){
    
}

int main(){
    inputSolver();

    for(vector<int>::iterator i=vex.begin();i!=vex.end();i++)
        cout << *i << ' ';
    cout << endl;
    for(int i=0;i<edg.size();i++){
        cout << vex[i] << ": ";
        for(int j=0;j<edg[i].size();j++)
            cout << edg[i][j] << ' ';
        cout << endl;
    }
    cout <<endl;
    return 0;       
}

