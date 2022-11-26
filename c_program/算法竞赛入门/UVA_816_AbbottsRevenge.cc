/*
    迷宫问题
    转换为BSF求解最短路径

    使用三元组（r,c,dir)表示位于(r,c)朝向dir，假设初始位于(r0,c0)
    则初始状态不是(r0,c0,dir0),而为(r1,c1,dir0),其中(r1,c1)为沿着dir0走一步后的坐标

    使用三维数组表示最短路径长度，三维数组表示某一个状态下的父节点

    Sample Input：
    SAMPLE
    3 1 N 3 3
    1 1 WL NR *
    1 2 WLF NR ER *
    1 3 NL ER *
    2 1 SL WR NF *
    2 2 SL WF ELF *
    2 3 SFR EL *
    0
    NOSOLUTION
    3 1 N 3 2
    1 1 WL NR *
    1 2 NL ER *
    2 1 SL WR NFR *
    2 2 SR EL *
    0
    END
    Sample Output
    SAMPLE
    (3,1) (2,1) (1,1) (1,2) (2,2) (2,3) (1,3) (1,2) (1,1) (2,1)
    (2,2) (1,2) (1,3) (2,3) (3,3)
    NOSOLUTION
    No Solution Possible
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

struct Node{
    int r,c;    // 坐标
    int dir;   // 方向
    Node():r(0),c(0),dir(0){}
    Node(int r0,int c0,int dir0):r(r0),c(c0),dir(dir0){}
};
int dir,turn,r0,c0,r1,c1,r2,c2;
int d[11][11][6];   // d[r][c][dir]初始状态到(r,c,dir)的最短路径
Node p[11][11][6];  // p[r][c][dir]状态(r,c,dir)在BFS树中的父节点
int has_edge[11][11][6][6]; // [r][c][dir][turn]表示当前状态是(r,c,dir)是否可以沿着方向turn转向
char casename[200];
// 输入过程
// 将四个方向和三种转向编号为0-3和0-2
const char dirs[] = "NESW"; // 上北0 右东1 下南2 左西3
const char turns[] = "FLR"; // 直走0 左拐1 右拐2
int dir_id(char c){ return strchr(dirs,c) - dirs; }
int turn_id(char c){ return strchr(turns,c) - turns; }
// 行走函数，根据当前状态和转弯方式，计算出后继状态
const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};
Node walk(const Node &u, int turn){
    int dir = u.dir;
    if(turn == 1)   dir = (dir+3)%4;    // 逆时针
    if(turn == 2)   dir = (dir+1)%4;    // 顺时针
    return Node(u.r+dr[dir],u.c+dc[dir],dir);
}
// 输入
bool input(){
    memset(has_edge,0,sizeof(has_edge));
    std::cin >> casename; 
    if(casename == "END")   return false;
    std::cout << casename << std::endl;
    char s[100];
    std::cin >> r0 >> c0 >> s >> r2 >> c2;
    r1 = r0 + dr[dir_id(s[0])];
    c1 = c1 + dc[dir_id(s[0])];
    dir = dir_id(s[0]);
    
    int r,c;
    while(scanf("%d",&r)==1 && r){
        scanf("%d",&c);
        while(cin >> s){
            if(s[0] == '*') break;
            int len = strlen(s);
            for(int i=1;i<len;i++)
                has_edge[r][c][dir_id(s[0])][turn_id(s[i])] = 1;
        }
    }
    return true;
}
void print_ans(Node u);
// BFS 主体
void solve(){
    std::queue<Node> q;
    memset(d,-1,sizeof(d));
    memset(p,0,sizeof(p));
    Node u(r1,c1,dir);
    d[u.r][u.c][u.dir] = 0;
    q.push(u);
    while(!q.empty()){
        Node u = q.front(); q.pop();
        if(u.r == r2 && u.c == c2){ print_ans(u); return; }
        for(int i=0; i<3; i++){
            Node v = walk(u,i);
            if(has_edge[u.r][u.c][u.dir][i] && d[v.r][v.c][v.dir] < 0){
                d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
                p[v.r][v.c][v.dir] = u;
                q.push(v);
            }
        }
    }
    printf("No Solution Possible\n");
}

void print_ans(Node u){
    std::vector<Node> nodes;
    while(1){
        nodes.push_back(u);
        if(d[u.r][u.c][u.dir] == 0) break;
        u = p[u.r][u.c][u.dir];
    }
    nodes.push_back(Node(r0,c0,dir));

    int cnt = 0;
    for(int i=nodes.size()-1; i>=0; i--){
        if(cnt%10 == 0) printf(" ");
        printf(" (%d, %d)",nodes[i].r,nodes[i].c);
        if(++cnt % 10 == 0) printf("\n");
    }

    if(nodes.size() % 10 !=0 )  printf("\n");
}