#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <array>
#include <ctime>

using namespace std; 
const int Len = 66;
const int Divs = 6;
void subdivides(char ar[], int low, int high, int level);
char * test(char*,int);

int main (){
    /*
    int a {1};
    cout << a <<endl;
    char str[] {"abcdefg"};
    cout << "I have "<< strlen(str) << " chateractor"<<endl;
    cin.getline(str,strlen(str));
    cout << str <<endl;
    cin.clear(); // 恢复空行读取后的无效位
    cin.get(str, strlen(str)).get(str, strlen(str)).get();
    cout << str <<endl;
    string str1 =  "qweqweqweqwe";
    cout << str1.size() << endl;
    //cin >> str1;
    cout <<str1 << endl;
    getline(cin,str1);
    cout << str1;
    cout << R"++(Jim is a "boy" so (???\n) you dont do it)++" << endl;
    struct demo{
        int int_n;
        double double_n;
    };
    demo stu;
    cin >> stu.double_n;
    int * test;
    test = new int[100];
    test[99] = 100;
    cout << sizeof(test) << endl;
    int ar[10];
    cout << sizeof(ar)/sizeof(int) << endl;
    cout << test[99] <<endl;
    cout << test <<endl;
    delete [] test;
    cout << sizeof(test) << endl;
    */
   /*
    vector<int> v_int(4);
    v_int[0] = 1;
    cout << v_int[0] << endl;
    int n = 5;
    array<int, 4> a_int = {1,2,3,4}; 
    vector<int> a(4,4);
    cout.setf(ios_base::boolalpha);
    cout << (n<10) << endl;
    cout.unsetf(ios_base::boolalpha);
    string str;
    getline(cin,str);
    for(int i=str.size();i>=0;i--)
        cout << str[i];
    cout <<endl;
    cout << str <<endl;
    time_t t;
    t =  clock()/CLOCKS_PER_SEC;
    cout << t <<endl;
    for (int x : a_int)
        cout << x << ' ';
    cout << endl;
    char ar[3]{'q','w','e'};
    char *arr = test(ar,3);
    cout << ar[0] << '\n' << arr[0] <<endl;
    */
   /*
    char ruler[Len];
    int i;
    for(i=1;i<Len-2;i++)
        ruler[i] = ' ';
    ruler[Len-1] = '\0';
    int max = Len - 2;
    int min = 0;
    ruler[min] = ruler[max] = '|';
    cout <<ruler << endl;
    for(i=1; i<=Divs;i++){
        subdivides(ruler,min,max,i);
        cout << ruler << endl;
        for(int j=1; j<Len-2; j++)
            ruler[j] = ' ';
    }
    */
   /*
    char ar[3]{'q','w','e'};
    auto p1 = test; // 单值初始化
    char *(*p2[3])(char ar[],int n){test,test,test};
    auto p3 = &p2;
    (*p3)[2](ar,3);
    // 函数指针可以脱一层*运算符使用
    */
   /*
    int v1 = 10;
    int *p1 = &v1;
    int &v2 = *p1;
    cout << v1 << ' ' << *p1 << ' ';
    cout << v2 << endl;
    int v3 = 11;
    v1 = v3;
    cout << v1 << ' ' << *p1 << ' ';
    cout << v2 << endl;
    */
    // 引用相当于const限定的指针
    // 函数按引用传递时，可以直接传进去原值而不用特意定义引用变量
    
    

    return 0;
}

char * test(char ar[],int n){
    ar[0] = '1';
    return ar;
}
void subdivides(char ar[], int low, int high, int level){
    if(!level)
        return;
    int mid = (high+low)/2;
    ar[mid] = '|';
    subdivides(ar,low,mid,level-1);
    subdivides(ar,mid,high,level-1);
}