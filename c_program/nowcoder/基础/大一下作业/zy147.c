#include <stdlib.h>
#include <stdio.h>
typedef struct student
{
	int id;
	char name[50];
	float chinese;
	float math;
	float english;
	float sum;
}student;
/*输入参数：字符串name是要打开的文件名称。输出参数：stu是读出的学生的详细信息。函数的返回值：学生人数.任何错误返回0*/
int ReadStuInfoFromFile(char *name, student **stu);

/*输入参数：stu是全班学生信息，n是人数。输出参数：3科平均成绩不及格人名单noPassStudent,不及格人数m.操作成功返回0，失败返回-1*/
int NoPass(student stu[], int n, student **noPassStudent, int *m);

/*输入参数：stu是全班学生信息，n是人数。输出参数：3科平均成绩及格人名单PassStudent,及格人数m.操作成功返回0，失败返回-1*/
int Pass(student stu[], int n, student **PassStudent, int *m);

/*输入参数：stu是全班学生信息，n是人数。输出参数：按照总分/平均分排序后的结果也存储在stu中.操作成功返回0，失败返回-1*/
int SortStudents(student stu[], int n);

/*输入参数：stu是全班学生信息，n是人数。操作成功返回0，失败返回-1。本函数在码图上不会进行检测，只是供同学们调试使用。*/
int PrintStudents(student stu[], int n);

/*输入参数：stu是全班学生信息，n是人数,id是待查找的学号。输出参数：rank是在班上的排名；stu是这个学生的详细信息。返回值：查找成功返回0，失败返回-1*/
int SearchStudent(student stu[], int n, int id,int *rank, student *rstu);

int main (){
    int n, rank, id,i,m;
	char name[]= "stuScores.txt";
	student *stu=NULL,*noPassStu=NULL,*PassStu=NULL,rstu;
	n = ReadStuInfoFromFile(name, &stu);
	if (n == 0) { printf("error"); return -1; }
	PrintStudents(stu, n);

	printf("\n no pass studnt--------\n");
	i = NoPass(stu, n, &noPassStu, &m);
	if(i==-1)printf("no pass error");
	else
	PrintStudents(noPassStu, m);
	
	printf("\n  passed studnt--------\n");
	i = Pass(stu, n, &noPassStu, &m);
	if (i == -1)printf(" pass error");
	else
		PrintStudents(noPassStu, m);

	printf("\n sort studnt--------\n");
	//i = NoPass(stu, n, &noPassStu, &m);
	i=SortStudents(stu, n);
	if (i == -1)printf("sort error");
	else
		PrintStudents(stu, n);

	printf("\n search id--------\n");
	//i = NoPass(stu, n, &noPassStu, &m);
	scanf_s("%d", &id);
	i = SearchStudent(stu, n, id, &rank, &rstu);
	if (i == -1)printf("search error");
	else
		PrintStudents(&rstu, 1);
       if(stu){free(stu);stu=NULL;}
       if(noPassStu){free(noPassStu);noPassStu=NULL;}
       if(PassStu){free(PassStu);PassStu=NULL;}
	return 0;
}
int ReadStuInfoFromFile(char *name, student **stu){
    FILE * fp;
    if((fp=fopen(name,'r'))==NULL)
        return 0;
    
}