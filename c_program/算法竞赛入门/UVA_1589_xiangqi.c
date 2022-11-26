/*
http://acm.hdu.edu.cn/showproblem.php?pid=4121
Description
Xiangqi is one of the most popular two-player board games in China. 
The game represents a battle between two armies with the goal of capturing the enemy’s “general” piece. 
In this problem, you are given a situation of later stage in the game. 
Besides, the red side has already “delivered a check”. 
Your work is to check whether the situation is “checkmate”.

Now we introduce some basic rules of Xiangqi. 
Xiangqi is played on a 10×9 board and the pieces are placed on the intersections (points). 
The top left point is (1,1) and the bottom right point is (10,9). 
There are two groups of pieces marked by black or red Chinese characters, 
belonging to the two players separately. 
During the game, each player in turn moves one piece from the point it occupies to another point. 
No two pieces can occupy the same point at the same time. 
A piece can be moved onto a point occupied by an enemy piece, 
in which case the enemy piece is “captured” and removed from the board. 
When the general is in danger of being captured by the enemy player on the enemy player’s next move, 
the enemy player is said to have “delivered a check”. If the general’s player can make no move 
to prevent the general’s capture by next enemy move, the situation is called “checkmate”.

We only use 4 kinds of pieces introducing as follows:
General: the generals can move and capture one point either vertically or 
horizontally and cannot leave the “palace” unless the situation called “flying general” 
(see the figure above). “Flying general” means that one general can “fly” across the 
board to capture the enemy general if they stand on the same line without intervening pieces.

Chariot: the chariots can move and capture vertically and horizontally 
by any distance, but may not jump over intervening pieces

Cannon: the cannons move like the chariots, horizontally and vertically, 
but capture by jumping exactly one piece (whether it is friendly or enemy) over to its target.

Horse: the horses have 8 kinds of jumps to move and capture shown in the left figure. However, 
if there is any pieces lying on a point away from the horse horizontally or vertically 
it cannot move or capture in that direction (see the figure below), 
which is called “hobbling the horse`s leg”.

Now you are given a situation only containing a black general, a red general and several red chariots, 
cannons and horses, and the red side has delivered a check. Now it turns to black side’s move. 
Your job is to determine that whether this situation is “checkmate”.

Input
The input contains no more than 40 test cases. For each test case, 
the first line contains three integers representing the number of red pieces N (2<=N<=7) 
and the position of the black general. The following n lines contain details of N red pieces. 
For each line, there are a char and two integers representing the type and 
position of the piece (type char ‘G’ for general, ‘R’ for chariot, ‘H’ for horse and ‘C’ for cannon). 
We guarantee that the situation is legal and the red side has delivered the check.

There is a blank line between two test cases. The input ends by 0 0 0.

Sample Input
2 1 4
G 10 5
R 6 4

3 1 5
H 4 5
G 10 5
C 7 5

0 0 0

Sample Output
YES
NO
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_R(char **b,int x1,int y1,int x2,int y2){
    if(x1!=x2){     // 俥与bg不在一条横线
        if(y1!=y2){
            return false;   // 俥与gb横竖坐标都不在一条线
        }
        else    // 俥与bg竖坐标在一条线
        {
            if(x1<x2){   // 俥在bg下方
                for(int i=x1+1;i<x2;i++)
                    if(b[i][y1]  !='\0'){
                        return false; 
                    }
            }
            else{    // 俥在bg上方
                for(int i=x2+1;i<x1;i++)
                    if(b[i][y1] !='\0')
                        return false;
            }
        }
    }else{
        // 俥与bg在一条横线上 且 y1!=y2 一定的
        if(y1<y2)   // 俥在bg右侧
        {   for(int i=y1+1;i<y2;i++)
                if(b[x1][i] !='\0')
                    return false;
        }
        else    // 俥在bg左侧
            for(int i=y2+1;i<y1;i++)
                if(b[x1][i] !='\0')
                    return false;
    }
    return true;
}
bool is_H(char **b,int x1,int y1,int x2,int y2){
    if(x1<x2)   // bg在马的上侧
    {
        if(y1<y2)   // bg在马的左侧 即 左上侧
        {   // 左上侧时马在上方至少有一行可以走即左上走日字时一定可以走 上左走日字需要判断位置
            // 左上走日字
            if(y2>0)
            if((b[x2][y2-1] =='\0') && (x2-1==x1 && y2-2 == y1))    // 左侧没有别马腿
                return true; 
            if(x2>0)
            if(b[x2-1][y2]  == '\0' && (x2-2 == x1 && y2-1 == y1))
                return true;
        }
        else    // bg在马的右上侧
        {
            if(x2>0)
            if(b[x2-1][y2] =='\0' && (x2-2==x1 && y2+1==y1))    // 上侧没有蹩马腿
                    return true;
            if(y2<8)
            if(b[x2][y2+1] =='\0' && y2+2 == y1 && x2-1==x1)  // 右侧没有蹩马腿
                    return true;
        }
    }
    else    // bg在马的下侧 x1>x2
    {
        if(y1<y2)   // bg在马的左侧 即 左下侧
        {   // 走下左日
            if(x2<9)
            if(b[x2+1][y2] =='\0' && x2+2==x1 && y2-1==y1)    // 位置正确 没有别马腿
                    return true;
            if(y2>0)
            if(b[x2][y2-1] =='\0' && x2+1 == x1 && y2-2 == y1)   // 走左下日  没有别马腿
                    return true;
        }
        else    // x1>x2 y1>y2 bg在马的右下方
        {
            if(y2<8)
            if(b[x2][y2+1] =='\0' && x2+1==x1 && y2+2==y1)    // 走右下日 没有别马腿
                    return true;
            if(x2<9)
            if(b[x2+1][y2] =='\0' && x2+2==x1 && y2+1 == y1)  // 走下右日 没有别马腿
                    return true;
        }
    }
    return false;
}
bool is_C(char **b,int x1,int y1,int x2,int y2){
    int count=0;
    if(x1!=x2)  // 红炮与bg不在一条横线上
    {
        if(y1!=y2)  // 炮与bg不在一列
            return false;
        else    // 炮与bg在一列
        {
            if(x1<x2)   // 炮在bg下方
            {    for(int i=x1+1;i<x2;i++)
                    if(b[i][y1] !='\0')
                        count++;
            }else   // 炮在bg上方
            {
                for(int i=x2+1;i<x1;i++)
                    if(b[i][y1] !='\0')
                        count++;
            }
        }
    }else   // 炮与bg在一条横线上
    {   // y1 != y2
        if(y1<y2)   // bg在炮上方
        {    for(int i=y1+1;i<y2;i++)
                if(b[x1][i] !='\0')
                    count++;
        }
        else{
            for(int i=y2+1;i<y1;i++)
                if(b[x1][i] !='\0')
                    count++;
        }  
    }
    if(count!=1)
        return false;
    else
        return true;
}
bool is_true(char **b,int x1,int y1,int x2,int y2,char type){
    switch(type){  
        case 'G':
        case 'R':
            if(!is_R(b,x1,y1,x2,y2))
                return false;
            break;
        case 'H':
            if(!is_H(b,x1,y1,x2,y2))
                return false;
            break;
        case 'C':
            if(!is_C(b,x1,y1,x2,y2))
                return false;
            break;
        default:
            break;
    }
    return true;
}
bool is_checkmate(char **b,int N,int **position){
    for(int shuai=1;shuai<=N;shuai++)
        if(b[position[shuai][0]][position[shuai][1]]=='G')
            if(is_R(b,position[0][0],position[0][1],position[shuai][0],position[shuai][1]))
                return false;
    for(int i=1;i<=4;i++){
        int n=N;
        char **temp = (char **)malloc(10*sizeof(char *));
        for(int k=0;k<10;k++)
            temp[k] = (char*)malloc(9*sizeof(char));
        for(int i=0;i<10;++i)
            for(int j=0;j<9;j++)
                temp[i][j] = b[i][j];
        // i=1,2,3,4 代表上下左右
        bool flag = false;
        switch(i){  // 遍历红子时，如果有一个将军则为将死局
            case 1: // bg向上移
                    if(position[0][0]==0)   
                        continue;   // bg在最上边无法移动 或者 bg上面有棋子
                    if(b[position[0][0]-1][position[0][1]]!='\0'){  // 吃子 = =
                        for(int whoareyou=1;whoareyou<=N;whoareyou++)
                            if(position[whoareyou][0]==position[0][0]-1&&position[whoareyou][1]==position[0][1])
                                while(whoareyou<N){
                                    position[whoareyou][0] = position[whoareyou+1][0];
                                    position[whoareyou][1] = position[whoareyou+1][1];
                                    whoareyou++;
                                }
                        n--;         
                    }
                    // 在棋盘上移动bg
                    temp[position[0][0]-1][position[0][1]] = temp[position[0][0]][position[0][1]];
                    temp[position[0][0]][position[0][1]]  = '\0';
                    for(int i=1;i<=n;i++){
                        // 依次遍历红子 如果有一个棋子将死则就将死
                        if(is_true(temp,position[0][0]-1,position[0][1],position[i][0],position[i][1],
                        temp[position[i][0]][position[i][1]] )){
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                        return false;
                    break;
            case 2: // bg向左移动
                    if(position[0][1]==3)
                        continue;   // bg 在自己的九宫格内的最左边（x=3）或者左侧有子
                    if(b[position[0][0]][position[0][1]-1]!='\0'){  // 吃子 = =
                        for(int whoareyou=1;whoareyou<=N;whoareyou++)
                            if(position[whoareyou][0]==position[0][0]&&position[whoareyou][1]==position[0][1]-1)
                                while(whoareyou<N){
                                    position[whoareyou][0] = position[whoareyou+1][0];
                                    position[whoareyou][1] = position[whoareyou+1][1];
                                    whoareyou++;
                                }
                        n--;
                    }
                    // 移动bg
                    temp[position[0][0]][position[0][1]-1] = temp[position[0][0]][position[0][1]];
                    temp[position[0][0]][position[0][1]]  = '\0';
                    for(int i=1;i<=n;++i){
                        if(is_true(temp,position[0][0],position[0][1]-1,position[i][0],position[i][1],
                        temp[position[i][0]][position[i][1]] )){
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                        return false;
                    break;
            case 3: // bg向下移动
                    if(position[0][0]==2 /*|| b[position[0][0]+1][position[0][1]] !='\0'*/)
                        continue;  // bg 在九宫格最下面（y=2）或者下侧有棋子
                    if(b[position[0][0]+1][position[0][1]]!='\0'){  // 吃子 = =
                        for(int whoareyou=1;whoareyou<=N;whoareyou++)
                            if(position[whoareyou][0]==position[0][0]+1&&position[whoareyou][1]==position[0][1])
                                while(whoareyou<N){
                                    position[whoareyou][0] = position[whoareyou+1][0];
                                    position[whoareyou][1] = position[whoareyou+1][1];
                                    whoareyou++;
                                }
                        n--;
                    }
                    temp[position[0][0]+1][position[0][1]] = temp[position[0][0]][position[0][1]];
                    temp[position[0][0]][position[0][1]]  = '\0';
                    for(int i=1;i<=n;++i){
                        if(is_true(temp,position[0][0]+1,position[0][1],position[i][0],position[i][1],
                        temp[position[i][0]][position[i][1]] )){
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                        return false;
                    break;
            case 4: // bg向右移动
                    if(position[0][1]==5 /*|| b[position[0][0]][position[0][1]+1] !='\0'*/)
                        continue;   // bg在九宫格最右边（x=5）或者右侧有棋子
                    if(b[position[0][0]][position[0][1]+1]!='\0'){  // 吃子 = =
                        for(int whoareyou=1;whoareyou<=N;whoareyou++)
                            if(position[whoareyou][0]==position[0][0]&&position[whoareyou][1]==position[0][1]+1)
                                while(whoareyou<N){
                                    position[whoareyou][0] = position[whoareyou+1][0];
                                    position[whoareyou][1] = position[whoareyou+1][1];
                                    whoareyou++;
                                }
                        n--;
                    }
                    temp[position[0][0]][position[0][1]+1] = temp[position[0][0]][position[0][1]];
                    temp[position[0][0]][position[0][1]]  = '\0';
                    for(int i=1;i<=n;++i){
                        if(is_true(temp,position[0][0],position[0][1]+1,position[i][0],position[i][1],
                        temp[position[i][0]][position[i][1]] )){
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                        return false;
                    break;
        }
        free(temp);
    }
    return true;
}
void ffread(int *x,int *y){
    scanf("%d%*c%d%*c",x,y);
}
int main(){
    int N=1,x=1,y=1;
    while(0!=N){
        char **b;
        b = (char**)malloc(10*sizeof(char*));
        for(int i=0;i<10;i++){
            b[i] = (char *)malloc(9*sizeof(char));
            for(int j=0;j<9;j++)
                b[i][j]= '\0'; 
        }
        scanf("%d%*c",&N);
        ffread(&x,&y);
        if(N==0)
            break;
        int **position;
        position = (int**)malloc((N+1)*sizeof(int*));
        for(int i=0;i<N+1;i++)
            position[i] =(int *)malloc(2*sizeof(int));
        position[0][0] = x-1;position[0][1] = y-1;
        b[x-1][y-1] = 'g';   // 小g为黑将 G为红帅
        for(int i=0;i<N;i++){
            char ch = getchar();
            ffread(&x,&y);
            position[i+1][0] = x-1;
            position[i+1][1] = y-1;
            b[x-1][y-1]= ch;
        }
        FILE * fp = fopen("4-1","a+");
        if(is_checkmate(b,N,position))
            fprintf(fp,"YES\n");
            //puts("YES");
        else
            fprintf(fp,"NO\n");
        fclose(fp);
    }
    return 0;
}

