#include <iostream>
#include <fstream>
#include <thread>

using namespace std;
// using namespace this_thread;

int fact(int n){
    if(n == 0)  return 1;
    return n * fact(n-1);
}

int main(){
    ofstream out("/mnt/l/abcdefghijk.txt");
    if(out.is_open())
        for(int i=0;i<3200;i++)
            out << 'a';
    else
        cout << "Error\n";
    out.close();
    return 0;
}