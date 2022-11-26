/*
    核心函数 <cstdlib>中的rand();
    其生成区间【0，RAND_MAX】内的均匀随机数。（RAND_MAX至少为32767）
    若想生成0-n之间的随机数，则：（精度要求不高的话）
        使用rand()生成一个随机数，
        将这个随机数除以RAND_MAX，得到【0，1】上的实数，
        将这个实数乘以n，得到【0，n】上的随机数。
    使用随机数的程序在初始时需要执行srand(time(NULL));目的是初始化“随机种子”。
    如若不初始化种子，直接使用rand()，则默认执行srand(1),故每次生成随机数一样。
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

void file_random_int(vector<int> &v,int cnt){
    v.clear();
    for(int i=0;i<cnt;i++)
        v.push_back(rand());
}

int main(){
    int cnt = 100;
    vector<int> v;
    srand(time(NULL));
    file_random_int(v,cnt);
    for(int i=0;i<cnt;i++)
        cout << v[i] << ", ";
    cout << endl;
    return 0;
}