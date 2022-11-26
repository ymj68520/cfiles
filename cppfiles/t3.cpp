#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int temp(0);
    cout << "请输入一串数字，将找出最大数。" << endl;
    vector<int> array;
    while(cin >> temp){
        getchar();
        array.push_back(temp);
    }
    cout << "您输入的数字有：";
    for(vector<int>::size_type i=0; i != array.size(); ++i){
        cout << array[i];
        putchar(' ');
    }
    putchar('\n');
    for(vector<int>::size_type i=0; i!=array.size();++i){
        for(vector<int>::size_type j=i+1;j!=array.size();++j){
            if(array[i]>array[j])
                temp = array[i];
                array[i] = array[j];
                array[j] = array[i];
        }
    }
    vector<int>::iterator mid = (array.begin() + array.end())/2;
}