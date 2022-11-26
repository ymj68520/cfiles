//------------------------------------------problm区------------------------------
//①思考typedef 定义的变量如何利用fwrite进行存储
//②典型可利用sleep()语句类实现控制移动速度
//③BOOL PlaySoundW(LPCWSTR, HMODULE, DWORD)”: 无法将参数 1 从“const char[8]”转换为“LPCWSTR   -->导致原因-->即原因vc2010开发环境中可能找不到字符串的音乐导致
//④思考怎么消去不是这四个键的情况
#include<stdio.h>
#include<stdbool.h> 
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include <MMSystem.h>//导入声音头文件-->即联合形成
#pragma warning(disable:4996)//可以利用该代码消去警告类
#pragma comment(lib, "Winmm.lib")//链接库


//------------------------------------------变量区---------------------------------
//---------------------------------------宏定义变量定义----------------------------
#define H   24//定义高为24
#define W   78//定义宽为78
#define false 0
#define true  1

//-------------------------------------非宏定义变量定义----------------------------
int n=0;//全局变量定用于写界面的状况
int zpalyer=0;//记录总玩家的个数
int fs;//用于记录玩家的分数
int key=72;//用于控制玩家的移动方向的变量,且赋予初始化值为上
int changeFlag = 0;//判断是否吃到了果实,用于确定是否需要擦除蛇尾
int i;//用于函数中控制循环的变量
char name[20];
char name1[20];

 struct palyerinfo//定义玩家的名称与分数的结构体
{
	char name[20];
	int palyefs;
}player[100];
struct //定义贪吃蛇的食物产生的坐标类
{
	int x;
	int y;
}food;
struct //利用链表实现贪吃蛇的长度
{
	int x[100];
	int y[100];
	int len;
	int zfs;
	int speed;
}snake1;




//------------------------------------------声明区---------------------------------

void xj();
void dq();
void save();
void ck();
void xuanz();
void jm();
void phb();
void fs1(); 
int  begin();
void creatfood();
void keyDown();
bool sfjs();
void getoxy(int x,int y);
void ex();
int yy();
//------------------------------------------函数区---------------------------------


//-----------------------------------------界面函数区------------------------------
void menu1()//进入游戏后选择读取用户还是新建用户
{

	int n;
	system("color 3e");//即加一个语句即可控制颜色,即与cmd中类似进行控制颜色-->控制的是控制台的颜色
	printf("====================================================\n");
	printf("#                                                  #\n");
	printf("#                                                  #\n");
	printf("#                  1. 建立新玩家                   #\n");
	printf("#                  2. 读取存档                     #\n");
	printf("#                                                  #\n");
	printf("#                                                  #\n");
	printf("====================================================\n");
	printf("                  选项：");
	scanf("%d", &n);
	if (n == 1)
	{
		xj();
	}
	else
		if (n == 2)
		{
			dq();
		}
		else
		{
			printf("输入错误,请重新选择:\n");
			menu1();
		}

}

void menu2()//游戏里面的主菜单
{
	int n;
	printf("====================================================\n");
	printf("#                                                  #\n");
	printf("#               贪吃蛇 Version goddemon            #\n");
	printf("#                                                  #\n");
	printf("#                1. 开始游戏                       #\n");
	printf("#                2. 查看排行榜                     #\n");
	printf("#                3. 查看我的分数                   #\n");
	printf("#                4. 退出游戏                       #\n");
	printf("#                                                  #\n");
	printf("#                                                  #\n");
	printf("====================================================\n");

	printf("                  选项：\n");
	while (1)
	{
		scanf_s("%d", &n);
		switch (n)//选择功能
		{
		case 1:   begin();                                                                                                   break;
		case 2:      phb();                                                                                                  break;
		case 3:        fs1();                                                                                                break;
		case 4:          ex();                                                                                               break;
		default: printf("输出错误,请重新输入:\n");                                                                           break;
		}
	}

}
void xj()//新建用户的名字
{
	
	ck();
	++zpalyer;	//注意如果是在退出的时候赋予的值,会出现只能读出两个值的状况特点-->即在子函数中赋予值,必须在读取值后进行赋予值加减才可,否则可能出现乱码状况
	printf("\t\t输入用户名:\n");//注意利用\t\t进行控制界面-->很nice
	scanf("%s", name);
	strcpy(player[zpalyer].name,name);//注意赋值的先后
	menu2();
}
void dq()//读取存档里面的用户且进行选择
{
	ck();
	printf("请输入读取的姓名:\n");
	scanf("%s", name1);
	for (i = 0; i <= zpalyer; i++)
	{
		if ((strcmp(player[i].name, name1) == 0))
		{
			menu2();
		}
		else
			if(i==zpalyer)
		    {
			printf("未找到该用户,请在次选择读取与创建功能\n");
			menu1();
		    }
	}
}
//-----------------------------功能函数区---------------------------------
int begin()//开始游戏
{
	system("cls");
	jm();	
	while (1)
	{
		keyDown();
		if (!sfjs())
			break;
		creatfood();
		Sleep(snake1.speed);
	}
	player[zpalyer].palyefs = snake1.zfs;
	getoxy(W / 2, H / 2);
	printf("本次得分:%d\n",snake1.zfs);
	Sleep(3000);
	system("cls");
	menu2();
	Sleep(5000);
	return 0;

}
void phb()//排行榜
{
	int i;
	printf("======================  排行榜  ====================\n");
	for (i = 0; i <zpalyer; i++)
	{
		printf("%s\t%d\n", player[i].name, player[i].palyefs);
	}
	printf("====================================================\n");

}
void fs1()//查看自己的分数
{
	printf("你的分数为:\n");	
	printf("%d", player[zpalyer].palyefs);

}
void ex()//退出功能
{
	save();
	exit(0);
}
void save()
{
	FILE *fp;
	fp = fopen("tcs.txt", "w+");
	fwrite(&zpalyer, 4, 1, fp);
	for (i = 0; i <= zpalyer; i++)
	{
		fwrite(&player[i], sizeof(struct palyerinfo), 1, fp);
	}
	fclose(fp);

}
void ck()//读取文档中的数据状况
{
	FILE *fp;
	int i;
	fp = fopen("tcs.txt", "r+");
	fread(&zpalyer, 4, 1, fp);
	for (i = 0; i <=zpalyer; i++)
	{
		fread(&player[i], sizeof(struct palyerinfo), 1, fp);
	}
	fclose(fp);
}
void xuanz()
{

	int j = 0, x = 1;
	menu2();
	   
}
void getoxy(int x,int y)//定位坐标位置的函数
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void jm()//贪吃蛇初始化界面
{
	
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	system("color 3e");
	//打印上下边界的循环
	for (i = 0; i <= W; i+=2)
	{
		getoxy(i, 0);
		printf("++");

		getoxy(i,H);//打印下边界
		printf("++");
	}
	for (i = 0; i < H; i++)
	{
		getoxy(0, i);
		printf("++");
		getoxy(W, i);
		printf("++");//打印下边界
	}
	while (1)//生成初始化的食物
	{
		srand((unsigned int)time(NULL));
		food.x = rand() % (W - 4) + 2;
		food.y = rand() % (H - 2) + 1;
		if (food.x % 2 == 0)
		{
			break;
		}
		
	}
	getoxy(food.x, food.y);
	printf("*");

	snake1.len = 3;
	snake1.speed = 200;
	snake1.x[0] = W / 2 + 1;//即在中间区域打印蛇头
	snake1.y[0] = H / 2;
	getoxy(snake1.x[0], snake1.y[0]);
	printf("★");
	for (i = 1; i < snake1.len; i++)//打印蛇头的状况特点-->利用getoxy(光标移动)+printf语句联合打印出蛇
	{
		snake1.x[i] = snake1.x[i - 1] + 2;//即将坐标赋值加2的状况理解
		snake1.y[i] = snake1.y[i - 1];
		getoxy(snake1.x[i], snake1.y[i]);
		printf("★");

	}
	getoxy(W - 2,0);
	
	return;
}
void creatfood()//创建食物的函数
{
	
	if (snake1.x[0] == food.x&&snake1.y[0] == food.y)//即蛇会吃掉这个食物
	{
		while (1)
		{
			int flag = 1;
			srand((unsigned int)time(NULL));
			food.x = rand() % (W - 4) + 2;
			food.y = rand() % (H - 2) + 1;
			for (i = 0; i < snake1.len; i++)
			{
				if (snake1.x[i] == food.x&&snake1.y[i] == food.y)
				{
					flag = 0;
					break;
				}
			}
			if (flag&&food.x % 2 == 0)//用该语句进行判断是否该结束坐标赋值
			{
				break;
			}
			
		}
		getoxy(food.x, food.y);//即创建食物,每一次都进行创造
		printf("*");	
		snake1.len++;//即蛇的长度加1,因为吃到了食物导致
		snake1.speed -= 5;
		snake1.zfs += 10;//即一个果实的分数等于10分
		changeFlag = 1;//即意味着吃到了食物,不需要擦除蛇尾的含义

	}
	return;//即return可以为空
}void keyDown()//控制移动的函数
{
	int pre_key = key;//记录前一个按键的方向
	if (_kbhit())
	{
		fflush(stdin);

		//getch()读取方向键的时候，会返回两次，第一次调用返回0或者224，第二次调用返回的才是实际值
		key = _getch();//第一次调用返回的不是实际值
		key = _getch();//第二次调用返回实际值
	}
	if (changeFlag == 0)
	{
		getoxy(snake1.x[snake1.len - 1], snake1.y[snake1.len - 1]);
		printf("  ");//在蛇尾处输出空格即擦去蛇尾
	}

	//将蛇的每一节依次向前移动一节（蛇头除外）
	for (i = snake1.len - 1; i > 0; i--)
	{
		snake1.x[i] = snake1.x[i - 1];
		snake1.y[i] = snake1.y[i - 1];
	}
	if (pre_key == 72 && key == 80)
		key = 72;
	if (pre_key == 80 && key == 72)
		key = 80;
	if (pre_key == 75 && key == 77)
		key = 75;
	if (pre_key == 77 && key == 75)
		key = 77;



	switch (key)
	{
	case 75:
		snake1.x[0] -= 2;//往左
		break;
	case 77:
		snake1.x[0] += 2;//往右
		break;
	case 72:
		snake1.y[0]--;//往上
		break;
	case 80:
		snake1.y[0]++;//往下
		break;
	}
	//打印出蛇头
	getoxy(snake1.x[0], snake1.y[0]);
	printf("★");
	getoxy(W - 2, 0);
	//由于目前没有吃到食物，changFlag值为0
	changeFlag = 0;
	return;
}
bool  sfjs()//判断游戏是否结束的函数
{

	if (snake1.y[0] == 0 || snake1.y[0] == H)
	{
		return false;
	}
	if (snake1.x[0] == 0 || snake1.x[0] == W)
	{
		return false;
	}
	for (i = 1; i < snake1.len; i++)
	{
		if (snake1.x[i] == snake1.x[0] && snake1.y[i] == snake1.y[0])//注意判断是否结束的函数需要注意
		{
			return false;
		}
	}
	return true;//即返回这个函数本身为真

}

int yy()
{
	PlaySound(TEXT("F:\\小苹果.wav"), NULL, SND_NODEFAULT | SND_ASYNC | SND_LOOP);//即利用转换参数进行代
	//SND_LOOP-->//重复播放声音，必须与SND_ASYNC标志一块使用
	//SND_ASYNC-->//用异步方式播放声音，PlaySound函数在开始播放后立即返回
	//SND_NODEFAULT -->不播放缺省声音，若无此标志，则PlaySound在没找到声音时会播放缺省声音-->典型找文件音乐是用的格式查看方式进行找的

	return 0;
}

//------------------------------------------主函数区-------------------------------


int main()
{
	yy();
	menu1();
	
	system("pause");
	return 0;
}



