/*
    Input
    The input begins with a single positive integer on a line 
    by itself indicating the number of the cases following, 
    each of them as described below. This line is followed by a blank line, 
    and there is also a blank line between two consecutive inputs.

    The first line of the input file consists of seven integers separated by spaces.
    These integers specify (in order): the number of programs which follow, 
    the unit execution times for each of the five statements 
    (in the order given above), 
    and the number of time units comprising the time quantum.
    The remainder of the input consists of the programs, 
    which are correctly formed from statements 
    according to the rules described above.

    All program statements begin in the first column of a line. 
    Blanks appearing in a statement should be ignored. 
    Associated with each program is an identification number 
    based upon its location in the input data (the first program has ID = 1, 
    the second has ID = 2, etc.).
    
    Output
    For each test case, the output must follow the description below. 
    The outputs of two consecutive cases will be separated by a blank line.
    Your output will contain of the output generated 
    by the print statements as they occur during the simulation. 
    When a print statement is executed, your program should display the program ID,
    a colon, a space, and the value of the selected variable. 
    Output from separate print statements should appear on separate lines.
    A sample input and correct output are shown below.

    Sample Input
    1

    3 1 1 1 1 1 1
    a = 4
    print a
    lock
    b = 9
    print b
    unlock
    print b
    end
    a = 3
    print a
    lock
    b = 8
    print b 
    unlock
    print b
    end
    b = 5
    a = 17
    print a
    print b
    lock
    b = 21
    print b
    unlock
    print b
    end
    Sample Output
    1: 3
    2: 3
    3: 17
    3: 9
    1: 9
    1: 9
    2: 8
    2: 8
    3: 21
    3: 21
*/
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
#include<queue>
using namespace std;

const int MAXN=1000 + 10;
bool lock;
deque<int>qr;   // 等待队列
queue<int>qw;   // 阻止队列
vector<string> sta[MAXN];
int var[26],p[MAXN],t[MAXN];
int Q;
void run(int i)
{
    int rt=Q,v;
    string cur;
    while(rt>0){
        cur=sta[i][p[i]];
        if(cur[2]=='='){
            rt-=t[0];
            v=cur[4]-'0';
            if(cur.size()==6)v=v*10+cur[5]-'0';
            var[cur[0]-'a']=v;
        }
        else if(cur[2]=='i'){
            rt-=t[1];
            printf("%d: %d\n",i,var[cur[6]-'a']);
        }
        else if(cur[2]=='c'){
            rt-=t[2];
            if(lock){
                qw.push(i);
                return;
            }
            else lock=true;
        }
        else if(cur[2]=='l'){
            lock=false;
            rt-=t[3];
            if(!qw.empty()){
                v=qw.front();
                qw.pop();
                qr.push_front(v);
            }
        }
        else return;
        ++p[i];
    }
    qr.push_back(i);
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<5;i++)
            scanf("%d",&t[i]);
        scanf("%d",&Q);
        string s;
        for(int i=1;i<=n;i++){
            sta[i].clear();
            while(getline(cin,s)){
                if(s=="")continue;
                sta[i].push_back(s);
                if(sta[i].back()=="end")break;
            }
            qr.push_back(i);
        }
        memset(p,0,sizeof(p));
        memset(var,0,sizeof(var));
        while(!qr.empty()){
            int cur=qr.front();
            qr.pop_front();
            run(cur);
        }
        if(cas) printf("\n");
    }
    return 0;
}