#include<iostream>
#include<fstream>
using namespace std;
struct qizhi
{
    char kind;
    int row;
    int column;
};

int panduan(int b_row, int b_column, int size, const qizhi*  p)   //用来判断黑将走某一步会不会被将死,如果会死返回0，不会返回1
{
    for (int i = 0; i < size; ++i)
    {
        switch (p[i].kind)
        {
        case 'G':
            if (p[i].column == b_column)
            {
                int key = 0;   //标记，
                for (int j = 0; j < size; ++j)    //如果黑将和红帅在同列，判断中间有没有其他的旗子
                {
                    if (j == i)
                        continue;
                    if (p[j].column == p[i].column&&p[j].row > b_row&&p[j].row < p[i].row)
                    {
                        key = 1;
                        break;
                    }
                }
                if (0 == key)
                    return 0;            //如果key为0，表面被将死直接返回0
            }
            break;
        case 'R':
            if (p[i].column == b_column)
            {
                int key = 0, key1;   //标记，
                p[i].row > b_row ? key1 = 1 : key1 = 0;
                for (int j = 0; j < size; ++j)    //如果黑将和车在同列，判断中间有没有其他的旗子
                {
                    if (j == i)
                        continue;
                    if (key1 == 1)
                    {
                        if (p[j].column == p[i].column&&p[j].row > b_row&&p[j].row < p[i].row)
                        {
                            key = 1;
                            break;
                        }
                    }
                    else
                    {
                        if (p[j].column == p[i].column&&p[j].row <b_row&&p[j].row > p[i].row)
                        {
                            key = 1;
                            break;
                        }
                    }

                }
                if (0 == key)
                    return 0;            //如果key为0，表明被将死直接返回0
            }
            if (p[i].row == b_row)
            {
                int key = 0, key1;   //标记，
                p[i].column > b_column ? key1 = 1 : key1 = 0;
                for (int j = 0; j < size; ++j)    //如果黑将和车在同行，判断中间有没有其他的旗子
                {
                    if (j == i)
                        continue;
                    if (key1 == 1)
                    {
                        if (p[j].row == p[i].row&&p[j].column > b_column&&p[j].column < p[i].column)
                        {
                            key = 1;
                            break;
                        }
                    }
                    else
                    {
                        if (p[j].row == p[i].row&&p[j].column < b_column&&p[j].column > p[i].column)
                        {
                            key = 1;
                            break;
                        }
                    }

                }
                if (0 == key)
                    return 0;            //如果key为0，表明被将死直接返回0
            }
            break;
        case 'C':
            if (p[i].column == b_column)
            {
                int key = 0, key1;   //标记，
                p[i].row > b_row ? key1 = 1 : key1 = 0;
                for (int j = 0; j < size; ++j)    //如果黑将和炮在同列，判断中间有多少个旗子
                {
                    if (j == i)
                        continue;
                    if (1 == key1)
                    {
                        if (p[j].column == p[i].column&&p[j].row > b_row&&p[j].row < p[i].row)
                        {
                            key += 1;
                        }
                    }
                    else
                    {
                        if (p[j].column == p[i].column&&p[j].row<b_row&&p[j].row>p[i].row)
                        {
                            key += 1;
                        }
                    }

                }
                if (1 == key)
                    return 0;            //如果key为1，表明被将死直接返回0
            }
            if (p[i].row == b_row)
            {
                int key = 0, key1;   //标记，
                p[i].column > b_column ? key1 = 1 : key1 = 0;
                for (int j = 0; j < size; ++j)    //如果黑将和炮在同行，判断中间有多少个旗子
                {
                    if (j == i)
                        continue;
                    if (1 == key1)
                    {
                        if (p[j].row == p[i].row&&p[j].column > b_column&&p[j].column < p[i].column)
                        {
                            key += 1;
                        }
                    }
                    else
                    {
                        if (p[j].row == p[i].row&&p[j].column<b_column&&p[j].column>p[i].column)
                        {
                            key += 1;
                        }
                    }
                }
                if (1 == key)
                    return 0;            //如果key为1，表明被将死直接返回0
            }
            break;
         case 'H':
            int up = 0, down = 0, left = 0, right = 0;
            for (int j = 0; j < size; ++j)    //判断向上是否会别马脚
            {
                if (j == i)
                    continue;
                if (p[j].row == p[i].row - 1 && p[j].column == p[i].column)
                {
                    up = 1;
                    break;                          //如果别马脚，就结束
                }
            }
            if (0 == up)
            {
                if (p[i].column - 1 == b_column&&p[i].row - 2 == b_row)
                    return 0;
                else if (p[i].column + 1 == b_column&&p[i].row - 2 == b_row)
                    return 0;
            }
            for (int j = 0; j < size; ++j)    //判断向左是否会别马脚
            {
                if (j == i)
                    continue;
                if (p[j].row == p[i].row && p[j].column == p[i].column - 1)
                {
                    left = 1;
                    break;                          //如果别马脚，就结束
                }
            }
            if (0 == left)
            {
                if (p[i].column - 2 == b_column&&p[i].row - 1 == b_row)
                    return 0;
                else if (p[i].column - 2 == b_column&&p[i].row + 1 == b_row)
                    return 0;
            }
            for (int j = 0; j < size; ++j)    //判断向右是否会别马脚
            {
                if (j == i)
                    continue;
                if (p[j].row == p[i].row && p[j].column == p[i].column + 1)
                {
                    right = 1;
                    break;                          //如果别马脚，就结束
                }

            }
            if (0 == right)
            {
                if (p[i].column + 2 == b_column&&p[i].row - 1 == b_row)
                    return 0;
                else if (p[i].column + 2 == b_column&&p[i].row + 1 == b_row)
                    return 0;
            }
            for (int j = 0; j < size; ++j)    //判断向下是否会别马脚
            {
                if (j == i)
                    continue;
                if (p[j].row == p[i].row + 1 && p[j].column == p[i].column)
                {
                    down = 1;
                    break;                          //如果别马脚，就结束
                }

            }
            if (0 == down)
            {
                if (p[i].column - 1 == b_column&&p[i].row + 2 == b_row)
                    return 0;
                else if (p[i].column + 1 == b_column&&p[i].row + 2 == b_row)
                    return 0;
            }
            break;


        }
    }
    return 1;
}

int yes_or_no(int b_row, int b_column, int size, qizhi*  p)               //判断有没有被将死，将死返回false，没死返回true
{
    int up = 0, down = 0, left = 0, right = 0;
    if (b_row - 1 > 0)                         //判断向上走会不会死
    {
        for (int i = 0; i < size; ++i)
        {
            if (p[i].column == b_column&&p[i].row == b_row - 1)      //判断黑将去的地方有没有红棋的子如果有吃掉
            {
                p[i].kind = ' ';
                break;
            }
        }
        up = panduan(b_row - 1, b_column, size, p);
    }
    if (b_row + 1 < 4)                                   //判断向下走会不会死
    {
        for (int i = 0; i < size; ++i)
        {
            if (p[i].column == b_column&&p[i].row == b_row + 1)      //判断黑将去的地方有没有红棋的子如果有吃掉
            {
                p[i].kind = ' ';
                break;
            }
        }
        down = panduan(b_row + 1, b_column, size, p);
    }
    if (b_column - 1 > 3)                               //判断向左走会不会死
    {
        for (int i = 0; i < size; ++i)
        {
            if (p[i].column == b_column - 1 && p[i].row == b_row)      //判断黑将去的地方有没有红棋的子如果有吃掉
            {
                p[i].kind = ' ';
                break;
            }
        }
        left = panduan(b_row, b_column - 1, size, p);
    }
    if (b_column + 1 < 7)                       //判断向右走会不会死
    {
        for (int i = 0; i < size; ++i)
        {
            if (p[i].column == b_column + 1 && p[i].row == b_row)      //判断黑将去的地方有没有红棋的子如果有吃掉
            {
                p[i].kind = ' ';
                break;
            }
        }
        right = panduan(b_row, b_column + 1, size, p);
    }
    return up + down + left + right;
}

int main()
{
    ///*文件重定向，输出测试*/
    //ifstream fin;
    //fin.open("data.in");
    //cin.rdbuf(fin.rdbuf());
    //ofstream out;
    //out.open("data.out");
    //cout.rdbuf(out.rdbuf());
    int r_number = 0, b_row = 0, b_column = 0;        //红方棋字个数，黑方将的位置
    while (cin >> r_number >> b_row >> b_column&&r_number != 0 && b_column != 0 && b_row != 0)
    {
        auto p = new qizhi[r_number];
        for (int i = 0; i < r_number; ++i)
        {
            cin >> p[i].kind >> p[i].row >> p[i].column;
        }
        if (yes_or_no(b_row, b_column, r_number, p))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        delete[] p;

    }


}