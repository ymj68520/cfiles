#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <queue>
#include <algorithm>
#include <cctype>
using namespace std;




void mainMenu(){
	// 主界面
	cout << "===================================" << endl;
	cout << "|       1.转换为顺序表存储        |" << endl;
	cout << "|       2.单链表尾插入法          |" << endl;
	cout << "|       3.单链表头插入法          |" << endl;
	cout << "|       4.转换为栈储存            |" << endl;
	cout << "|       5.转换为队列储存          |" << endl;
	cout << "|       6.退出                    |" << endl;
	cout << "===================================" << endl;
	cout << "请输入菜单号（0-6）：" << endl;
}

class Student{
public:
    string id;
    string name;
    float score;
    Student(){
        id = name = "";
        score = 0.0;
    }
    Student(string _id, string _name, float s){
        id = _id, name = _name, score = s;
    }
};

class Node {
    public: Student stu;
    public: Node *next;
    Node(){
        memset(&stu,0,sizeof(stu));
        next = nullptr;
    }
};

vector<Student> stu;
// 顺序表
void func1(){
    ifstream scores("/mnt/e/cfiles/somefxxk/score.txt");
    if(!scores.is_open()){
        cout << "file open error!" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "文件打开成功！\n";
    char buf[512 + 1]; // 最大512附加一个'\0'
    scores.getline(buf,512);
    int count = 0;
    for(const auto &s : buf){
        if(s == '\r')   break;
        count = count*10 + s-'0';
    }
    cout << "总数：" << count << endl;
    stu.resize(count);
    while(!scores.eof()){
        scores.getline(buf,512);
        stringstream input(buf);
        input >> stu[--count].id >> stu[count].name >> stu[count].score;
    }
    // 这里是打印顺序表的函数
    auto print = [](){
        for(auto i = stu.begin();i!=stu.end();++i){
            // 修饰信息我没写，你自己写
            cout << i->id << ' ' << i->name << " " << i->score << endl;
        }
    };
    cout << "========显示顺序表的所有内容========" << endl;
    cout << "id\tname\tscore" << endl;
    print();
}
// 头插法单链表
void func2(){
    Node *root = new Node;
    for(const auto &s : stu){
        Node *p = new Node;
        p->stu = s;
        p->next = root->next;
        root->next = p;
    }
    cout << "========头插法链表========" << endl;
    cout << "头插法单链表生成成功\n";
    auto print = [=](){ // 捕捉父函数变量，值传递
        Node *p = root;
        while(p!=nullptr){
            // 修饰输出没写，自己写
            cout << p->stu.id << " " << p->stu.name << " " << p->stu.score << endl;
            p=p->next;
        }
    };
    cout << "========显示头插链表的所有内容========" << endl;
    cout << "id\tname\tscore" << endl;
    print();
}

// 尾插法
void func3(){
    Node *root = new Node;
    Node *p = root,*q;
    for(const auto &s : stu){
        q = new Node;
        q->stu = s;
        p->next = q;
        p = p->next;
    }
    cout << "========尾插法链表========" << endl;
    cout << "尾插法单链表生成成功\n";
    auto print = [=](){
        auto p = root->next;
        while(p!=nullptr){
            cout << p->stu.id << " " << p->stu.name << " " << p->stu.score << endl;
            p=p->next;
        }
    };
    cout << "========显示尾插链表的所有内容========" << endl;
    cout << "id\tname\tscore" << endl;
    print();
}

void func4(){
    int stackSize = stu.size();
    vector<Student> stk(stackSize + 3);
    int base = 0,top = 0;
    cout << "栈初始化成功！" << endl;
    auto stkEmpty = [&](){
        return top == base;
    };
    auto stkInsert = [&](Student s){
        stk[top++] = s;
    };
    auto stkPop = [&](){
        return stk[--top];
    };
    cout << "请输入入栈的数量：  ";
    int count;
    cin >> count;
    for(int i=0;i<count;++i)    stkInsert(stu[i]);
    cout << "top = " << top << endl;
    cout << "入栈成功!" << endl << "请输入出栈的数量：  ";
    cin >> count;
    vector<Student> out(count);
    for(int i=0;i<count;i++)    out[i] = stkPop();
    auto print = [=](){
        for(const auto &x : out){
            cout << x.id << " " << x.name << " " << x.score << endl;
        }
    };
    cout << "出栈的内容如下：" << endl;
    cout << "id\tname\tscore" << endl;
    print();    
}

void func5(){
    int front = 0, back = 0;
    vector<Student> queVec(stu.size()+3);
    auto queEmpty = [&](){
        return back == front;
    };
    auto queInsert = [&](Student &s){
        queVec[++back] = s;
    };
    auto quePop = [&](){
        return queVec[front++];
    };
    for(auto &s : stu) queInsert(s);
    cout << "入队操作成功！" << endl << "front = " << front << "  back = " << back << endl;
    cout << "显示队列的所有内容：" << endl;
    cout << "id\tname\tscore" << endl;
    while(queEmpty()!=true){
        auto p = quePop();
        cout << p.id << " " << p.name << " " << p.score << endl;
    }
}

int main(){
    bool isOrderedList = false;
    while(true){
        fflush(stdout);
        // system("clear");
        mainMenu();
        int funOrder;
        cin >> funOrder;
        if(funOrder<1 || funOrder>6)
            continue;
        switch(funOrder){
            case 1:
                isOrderedList = true;
                func1();
                break;
            case 2:
                if(!isOrderedList)  break;
                func3();
                break;
            case 3:
                if(!isOrderedList)  break;
                func2();
                break;
            case 4:
                if(!isOrderedList)  break;
                func4();
                break;
            case 5:
                if(!isOrderedList)  break;
                func5();
                break;
            case 6:
                cout << "GoodBye!" << endl;
                return 0;
        }
    }

}