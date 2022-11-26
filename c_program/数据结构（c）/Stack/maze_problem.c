
#define MAXLEN 25       //地图最大宽度

#define PASS 0      // 假定可通过是0
#define FAIL 1      // 墙是1
#define MARK -1     // 不可通过标志-1

#include <stdio.h>
#include "maze_stack.h"      //重新定义SElenmType

//方向定义
enum dir {up=1,right,down,left}; 

//地图
typedef int Mazetype[MAXLEN][MAXLEN];
//start end
PosType start,end;
//map
Mazetype Map = {0}; //全部设定为可通过
//验证当前位置是否可通
bool pass(PosType cupos,Mazetype map){
    if(map[cupos.x][cupos.y]==0)
        return true;
    else
        return false;
}
//输出轨迹
void print(struct SqStack S){
    int n = StackLength(S);
    printf("共有%d步\n",n);
    while(S.base != S.top){
        printf("第%d步，位置坐标为（%d，%d）\n",
        S.base->ord,S.base->seat.x,S.base->seat.y);
        S.base++;
    }
}
//初始化地图
void inimap(Mazetype map){
    //初始化边界
    for(int i=0;i<MAXLEN;i++) map[0][i] = 1;
    for(int j=1;j<MAXLEN;j++) map[j][0] = 1;
    for(int i=1;i<MAXLEN;i++) map[MAXLEN-1][i] = 1;
    for(int j=1;j<MAXLEN-1;j++) map[j][MAXLEN-1] = 1;
    //用户输入墙的位置
    printf("地图的大小限制为：%d X %d\n",MAXLEN-1, MAXLEN-1);
    puts("初始化地图，输入你想让地图中位置变为墙的序号：");
    puts("空行结束输入！");
    int x,y;    //横纵坐标
    while(2 == scanf("%d,%d",&x,&y))
        map[x][y] = 1;
    bool wethtrue = true;
    puts("请输入起始位置坐标：");
    while(wethtrue){
        scanf("%d %d",&start.x,&start.y);
        if(start.x==1 && start.y==1)
            puts("这个位置是墙，请重新输入！");
        else
            wethtrue = false;
    }
    wethtrue = true;
    puts("请输入结束位置坐标：");
    while(wethtrue){
        scanf("%d %d",&start.x,&start.y);
        if(start.x==1 && start.y==1)
            puts("这个位置是墙，请重新输入！");
        else
            wethtrue = false;
    }
    puts("地图初始化完毕！");

    return;
}
//下一步,1=上,2=右,3=下,4=左;
PosType Nextpos(PosType pos,int dir){
    switch(dir){
        case up :
            pos.y++;
            break;
        case right :
            pos.x++;
            break;
        case down :
            pos.y--;
            break;
        case left :
            pos.x--;
            break;
    }
}

//创建一个空栈
    struct SqStack S;
    InitStack(&S);

status Mazepath(Mazetype map,PosType start, PosType end){
    //若迷宫maze中存在入口start到出口end的通道，则求得一条
    //存在的路径放入栈中（从栈底到栈顶）,并返回OK，否则返回error

    //创建指代当前位置的变量
    PosType curpos = start;

    int curstep = 1;    //第一步探索
    //开始探索
    do{
        SElemType e;
        if(pass(curpos,Map)){   //当前位置可通
            //留下足迹
            Map[curpos.x][curpos.y] = curstep;

            //为临时变量e赋值
            e.ord = curstep;
            e.seat = curpos;
            e.dir = 1;

            Push(&S,e);     //加入路径
            curstep++;
            if(curpos.x == end.x && curpos.y == end.y) 
                return OK; //已经到达终点
            curpos = Nextpos(curpos,e.dir);
            
        }//if
        else //不能通行
        {   
            SElemType temp; //补全函数参数的媒介(useless)
            if(!StackEmpty(S)){
                Pop(&S,&temp); //删去这一步
                curstep--;
                while(e.dir == 4 && !StackEmpty(S)){
                    //留下不能通行的标记
                    Map[curpos.x][curpos.y] = -1;
                    Pop(&S,&temp);
                    curstep--;
                }//while
                if(e.dir<4){
                    e.dir++;
                    Push(&S,e);
                    curstep++;
                    curpos = e.seat;
                    curpos = Nextpos(e.seat,e.dir);
                }//if
            }//if
        }//else
    }while(!StackEmpty(S));
    return ERROR;

}//Mazepath

int main(){
    inimap(Map);
    if(Mazepath(Map,start,end)){
        puts("此迷宫的一条通路如下：");
        print(S);
    }
    else
        puts("此迷宫没有通路！");
    return 0;
}