/*
    有t个团队的人正在排一个长队。每次新来一个人时，如果他有队友在排队，
    那么这个新人会插到最后一个队友的身后。如果没有任何一个队友在排队，则他会排到长队的队尾。
    输入每个团队中所有队员的编号，要求支持如下三种指令（前两种可以穿插进行）。
        ENQUEUE x: 编号为x的人进入长队。
        DEQUEUE：长队的队首出队。
        STOP：停止模拟。
    对于每个DEQUEUE指令，输出出队的人的编号。
*/
#include <iostream>
#include <queue>
#include <map>
using namespace std;

const int maxt = 1000+10;   // 最大团队数

int main(){
    int t, kase = 0;
    while(scanf("%d",&t)==1 && t){
        printf("Scenario #%d\n",++kase);

        // 记录所有人的团队编号
        map<int,int> team;  // team[x]表示编号为x的人所在的团队编号
        for(int i=0;i<t;i++){
            int n,x;
            scanf("%d",&n);
            while(--n){
                scanf("%d",&x);
                team[x] = i;
            }
        }

        // 模拟
        queue<int> q,q2[maxt];  // q是团队的队列，q2[i]是团队i成员的队列
        while(1){
            int x;
            char cmd[10];   // 不用string是因为它慢啊
            scanf("%s",cmd);
            if(cmd[0]=='S') break;
            else if(cmd[0]=='D'){
                int t = q.front();
                printf("%d\n",q2[t].front()); q2[t].pop();
                if(q2[t].empty()) q.pop();  // 团队队列出队
            }
            else if(cmd[0]=='E'){
                scanf("%d",&x);
                int t = team[x];
                if(q2[t].empty())   q.push(t);  // 团队t进入队列
                q2[t].push(x);
            }
        }
        putchar('\n');
    }

    return 0;
}