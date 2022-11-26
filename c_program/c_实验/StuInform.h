
typedef struct student{
    //序号
    int order; 
    //张（zhang）最多四字20字符
    char name[21]; 
    //学号
    unsigned long long gra_number; 
    //true = 男  false = 女
    int sex;  
    //c
    double cgrade; 
    //数学
    double math;   
    //英语
    double eng;     
    //语文
    double chinese;      
    //此处均分移出结构体
    
    //总成绩
    double sum;

}Student,*SStudent;
// 信息读入
SStudent Stuscanf(const char *name,int *Num,SStudent stu){
	FILE *fp;
	if((fp = fopen(name,"r"))==NULL){
		puts("Source File error, Please cheak!");
		exit(EXIT_FAILURE);
	}
	int pre_num_peo=0;
	fscanf(fp,"%d",&pre_num_peo);		// 首行为总人数
	*Num = pre_num_peo;
	stu = (SStudent)malloc(pre_num_peo*sizeof(Student));
	for (int i=0;i<pre_num_peo;i++){
		fscanf(fp,"%d",&stu[i].order);	// 读取序号
		fscanf(fp,"%s",stu[i].name);	// 读取名字
		// 读取学号 性别 成绩
		fscanf(fp,"%lld %d %lf %lf %lf %lf",&stu[i].gra_number,
			&stu[i].sex,&stu[i].cgrade,&stu[i].math,&stu[i].eng,&stu[i].chinese);
		
		//stu[i].sum = stu[i].cgrade+stu[i].chinese+stu[i].eng+stu[i].math;
		
		fscanf(fp,"%lf",&stu[i].sum);
		/*
		// 读取行位回车或者结束符'#'
		char ch = getc(fp);
		if(ch=='#')
			break;
		*/
	}
	return stu;
}
// 打印结构数组
void print (SStudent stu,int num){
	for(int i=0;i<num;i++){
		printf("%d ",stu[i].order);
		for(int j=0;*(stu[i].name+j)!='\0';j++)
        	printf("%c",stu[i].name[j]);
		printf(" %lld",stu[i].gra_number);
		if(stu[i].sex==1)
			printf(" boy ");
		else
			printf(" girl ");
		printf("%.2lf %.2lf %.2lf %.2lf %.2lf\n",
		 stu[i].cgrade, stu[i].math, stu[i].eng, stu[i].chinese, stu[i].sum);
	}
	sleep(2);
}

// 信息打印, 返回字符数
int check_pt(SStudent stu,const char *name,int num_peo){
	int words;
	int i=0;
	// 空格位（含回车）
	int space = num_peo*8;
	// 打开文件，输出流
	FILE *fp = fopen(name,"r");
	char ch = getc(fp);
	while(ch!='#'){
		printf("%c",ch);
		ch = getc(fp);
		i++;
	}
	// 计算总人数数字位数
	int num=1;
	int temp = num_peo;
	while((temp/10)>1){
		temp = temp / 10;
		num++;
	}
	// 计算字符数
	words = i - space - num -1;
	
	return words;
}

// 按某一个方面排序,名（1），成绩（2-5）
Student *check_od(SStudent stu,int num_peo,const char ch){
	switch (ch){
		case '1' :

			break;
		case '2' :

			break;
		case '3' :

			break;
		case '4' :

			break;
		case '5' :

			break;
		default:
			puts("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			puts("      Please enter the right num!");
			puts("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	}
}

//普通读入 gets_s()的改进
char * ss_gets(char * st, int n ){
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if(ret_val){
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return ret_val;
}