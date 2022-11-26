#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
	int id;
	char name[50];
	float chinese;
	float math;
	float english;
	float sum;
} student;

int PrintStudents(student stu[], int n);
int ReadStuInfoFromFile(char* name, student** stu);
int NoPass(student stu[], int n, student** noPassStudent, int* m);
int Pass(student stu[], int n, student** PassStudent, int* m);
int SortStudents(student stu[], int n);
int SearchStudent(student stu[], int n, int id, int* rank, student* rstu);



int ReadStuInfoFromFile(char* name, student** stu)
{
	char c;
	char remain[3];
	int count;
	FILE* fp;
	if ((fp = fopen(name, "r")) == NULL)
	{
		printf("file error\n");
		return 0;
	}
	else
	{
		fread(&c, sizeof(char), 1, fp);
		fread(&remain, sizeof(char), 3, fp);
		count = c;
		student* temp;
		temp = (student*)malloc(sizeof(student) * (count + 1));
		for (int i = 0; i < count; i++)
		{
			//temp = (student* )realloc(buff,(count+1)*sizeof(student));
			fread(&temp[i], sizeof(student), 1, fp);
			temp[i].sum = temp[i].chinese + temp[i].math + temp[i].english;
			 
		}
		*stu = temp;
		fclose(fp);
	}
	return count;
}

int NoPass(student stu[], int n, student** noPassStudent, int* m)
{
	if (stu == NULL || n <= 0)
		return -1;
	student* buff;
	int count = 0;
	buff = (student*)malloc(sizeof(student));
	for (int i = 0; i < n; i++)
	{
		if (stu[i].chinese + stu[i].math + stu[i].english < 180)
		{
			buff = (student*)realloc(buff, (count + 1) * sizeof(student));
			buff[count] = stu[i];
			//memmove(&buff[count], &stu[i], sizeof(student));
			count++;
		}
	}
	*noPassStudent = buff;
	*m = count;
	return 0;
}

int Pass(student stu[], int n, student** PassStudent, int* m)
{
	if (stu == NULL || n <= 0)
		return -1;
	student* buff;
	int count = 0;
	buff = (student*)malloc(sizeof(student));
	for (int i = 0; i < n; i++)
	{
		if (stu[i].chinese + stu[i].math + stu[i].english >= 180)
		{
			buff = (student*)realloc(buff, (count + 1) * sizeof(student));
			buff[count] = stu[i];
			//memmove(&buff[count], &stu[i], sizeof(student));
			count++;
		}
	}
	*PassStudent = buff;
	*m = count;
	return 0;
}

int SortStudents(student stu[], int n)
{
	if (stu == NULL || n <= 0)
		return -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (stu[j].sum > stu[j - 1].sum)
			{
				student temp;
				temp = stu[j];
				stu[j] = stu[i];
				stu[i] = temp;
			}
		}

	}
	return 0;
}
int SearchStudent(student stu[], int n, int id,int *rank, student *rstu)
{
		if(stu==NULL||n==0)
	{
		return -1;
	}
	SortStudents(stu, n);
	for(int i=0;i<n;i++)
	{
			if(stu[i].id==id)
		{
			*rank=i+1;
			
				*rstu=stu[i];
				
				return 0;
		}
	}
	return -1;
}