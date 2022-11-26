/*
输入n，得到编号为0~n-1的木块，分别摆放在顺序排列编号为0~n-1的位置。现对这些木块进行操作，操作分为四种。

1、move a onto b：把木块a、b上的木块放回各自的原位，再把a放到b上；

2、move a over b：把a上的木块放回各自的原位，再把a发到含b的堆上；

3、pile a onto b：把b上的木块放回各自的原位，再把a连同a上的木块移到b上；

4、pile a over b：把a连同a上木块移到含b的堆上。

当输入quit时，结束操作并输出0~n-1的位置上的木块情况

Sample Input 
10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
quit
Sample Output 
 0: 0
 1: 1 9 2 4
 2:
 3: 3
 4:
 5: 5 8 7 6
 6:
 7:
 8:
 9:
*/
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int MAXN = 30;
int n;
vector <int> pile[MAXN];    // 相当于一个第二维变长的二维数组

// 找到木块A所在的堆 和 高(这个堆上有多少个木块) ，用引用的形式修改值(相当于传入指针)
void find_you(int a, int &p, int &h){
    for(p=0;p<n;++p)    // 寻找每一个堆
        for(h=0;h<pile[p].size();h++)   // 在每一个堆上查找A的位置
            if(pile[p][h] == a)
                return;
}

// 把第p堆高度为h的木块上方的所有木块移回原位
void move_back_above(int p, int h){
    for(int i=h+1;i<pile[p].size();++i){    // 遍历h以上的所有木块
        int b = pile[p][i];     // 标记当前块b的堆位置
        pile[b].push_back(b);   // 把木块b放回原位
    }// 每次循环不必删除元素，只需要给数组重新分配大小即可
    pile[p].resize(h+1);    // 数组重新分配大小，h以后的位置全部失效，相当于删除
}

// 把第p1堆高度为h即其上方的木块整体移动到p2堆的顶部
void move_onto_above(int p1,int h, int p2){
    for(int i=h; i<pile[p1].size();++i)
        pile[p2].push_back(pile[p1][i]);    // 从p1的h开始将其及其以上的部分移动到p2顶部    
    pile[p1].resize(h);   
}

// 输出函数
void print(){
    for(int i=0;i<n;i++){   // 每一堆
        printf("%d:",i);
        for(int j=0;j<pile[i].size();j++)   // 每一个元素
            printf(" %d",pile[i][j]);
        putchar('\n');
    }
}

int main(){
    int a,b;
    ios :: sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    string s1,s2;
    for(int i=0;i<n;++i)
        pile[i].push_back(i);   // 初始化，使得最初为每个块在每个堆上
    while(cin >>s1 && s1 !="quit"){
        cin  >> a >> s2 >> b;
        int pa,pb,ha,hb;
        find_you(a,pa,ha);
        find_you(b,pb,hb);
        if(pa == pb)    // 非法指令，应当跳过
            continue;
        /*
        if(s1 == "move"){
            move_back_above(pa,ha); // over 与 onto 都需要这步
            if(s2 == "onto")
                move_back_above(pb,hb); // onto 独有
            move_onto_above(pa,ha,pb);  // 将a块移动到b顶            
        }else if(s1 == "pile"){
            if(s2 == "onto")
                move_back_above(pb,hb);
            move_onto_above(pa,ha,pb);
        }*/ // 可行但是比较麻烦
        if(s2 == "onto") move_back_above(pb,hb);
        if(s1 == "move") move_back_above(pb,hb);
        move_onto_above(pa,ha,pb);
    }
    print();
}