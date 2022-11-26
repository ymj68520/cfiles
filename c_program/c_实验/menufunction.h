#include <termios.h>	// Linux 下无回显输入 用于password
#include <unistd.h>


#define MENULEN 60
#define FSPACELEN 4
#define NSPACE 5

#define STAR '*'
#define SPACE ' '
//宏函数
#define PR(...) printf(__VA_ARGS__);

//输出两个*
void put_t_s(){
	putchar(STAR);putchar(STAR);
}

//输出两个空格
void puttsp(void){
	PR("%c%c",SPACE,SPACE)
}

//空行
void voidrow(){
	put_t_s();
	PR("                                                        ")
	put_t_s();
	putchar('\n');
}

//装饰，极其难看
void sr_decorate(){ 
		for(int i=0;i<MENULEN/2;i++)
			PR("%c",SPACE);
		PR("%c\n",STAR)
		for(int i=0; i<MENULEN/3;i++)
			putchar(SPACE);
		for(int i=0; i<MENULEN/3; i++)
			putchar(STAR);
		putchar('\n');
		for(int i=0; i<MENULEN/4; i++)
			putchar(SPACE);
		for(int i=0; i<30; i++)
			putchar(STAR);
		putchar('\n');
}

//标题
void headline(){
	for(int i=0; i<2; i++){            //����*��
		for(int i=0; i<MENULEN; i++) 
			PR("%c",STAR)
		putchar('\n');
	}//for
	voidrow();
	put_t_s();
	for(int i=0; i<FSPACELEN; i++) //���׿ո�
		PR("%c",SPACE);
	PR("Wlecome to UESTE`s student management system:")
	//ð�ź��7�ַ���
	for(int i=0; i<7; i++) 
		putchar(SPACE);
	put_t_s();
	putchar('\n');

	voidrow(); //��������	
	
	for(int i=0; i<MENULEN; i++) //һ���Ǻ�
			PR("%c",STAR)
		putchar('\n');
}

//密码 ------------- iloveyou
void password(){
	char word[9];
	char tword[9] = "iloveyou";
	bool is = false;
	puts("For you first use, Please enter the password!!");
	// 改为无回显输入
	//ss_gets(word,8);		//自带输入流清理
	char ch;
	int j=0;
	struct termios oldt,newt;  // 无回显输入
	while(1)
	{
		tcgetattr(STDIN_FILENO,&oldt);
		newt = oldt;
		
		newt.c_lflag &= ~(ECHO | ICANON);
		
		tcsetattr(STDIN_FILENO,TCSANOW,&newt);
		
		ch = getchar();
		
		if(ch == '\n')
		{
			word[8] = '\0';
			tcsetattr(STDIN_FILENO,TCSANOW,&oldt);
			break;
		}
		
		word[j] = ch;
		j++;
		
		tcsetattr(STDIN_FILENO,TCSANOW,&oldt);//每次输入一个字符后恢复回显状态
		printf("*");
	}
	static bool isright = true;
	if(j!=8)
		isright = false;
	else
		for(int i=0;i<9;i++)
			if(word[i]!=tword[i]){
				isright = false;
				break;
			}
	if(!isright){
		puts("Wrong key!");
		puts("This system will close in 3 seconds!");
		sleep(3);
		exit(EXIT_FAILURE);
	}
	puts("\nCongratulations!! welcome enter this system!");
	puts("-----------------------------------------------");
	puts("If you are first use this system, Please read the help by enter \"h\".");

	return;
}

//主菜单
void main_menu(){
	for(int i=0; i<2; i++){            //����*��
		for(int i=0; i<MENULEN; i++) 
			PR("%c",STAR)
		putchar('\n');
	}//for

	// ���� 
	voidrow();

	
	//�б���һ����
	put_t_s(); 
	puttsp();

	PR("c. check				      s. search")
	//�б���һ�в���ո�
	for(int i=0; i<NSPACE-2; i++)
		PR("%c",SPACE)
	put_t_s();putchar('\n');
	voidrow(); //�б���һ�к����
	
	//�б��ڶ�����
	put_t_s();
	puttsp();
	
	PR("a. alter				     e. exit")
	//�б��ڶ���β
	for(int i=0; i<FSPACELEN+1; i++)
		putchar(SPACE);
	put_t_s();
	putchar('\n');
	
	//����
	voidrow();

	//�б���������
	put_t_s();
	puttsp();
	
	//printf(" This is information management system.          ");
	PR("Get help please enter the alphabet \"h\".          ");
	//�б�������β
	for(int i=0; i<FSPACELEN+1; i++)
		putchar(SPACE);
	put_t_s();
	putchar('\n');
	
	//����
	voidrow();

	//��β
	for(int i=0; i<2; i++){            //����*��
		for(int i=0; i<MENULEN; i++) 
			PR("%c",STAR)
		putchar('\n');
	}//for

	 putchar('\n');
    //���������
    //��ʾ����
    puts("Please enter the alphabet which denote a operator.");
    puts("Such as c, s, i, h or e, others will not be allowed!!"); //����
	puts("Please enter:");
}

//获取首字母
char get_first(){
	int ch;
	
	ch = getchar();
	while(getchar()!='\n'){
		continue;
	}
	return ch;
}


//检查输入 
bool checkinput(char ch){
	if(!isalpha(tolower(ch)))
		return false;
	switch (ch)
	{
	case 'c':
		return true;
		break;
	case 'i':
		return false; // true;
		break;
	case 'a':
		return true;
		break;
	case 's':
		return true;
		break;
	case 'e':
		return true;
		break;
	case 'h':
		return true;
	default:
		return false;
	}
}
