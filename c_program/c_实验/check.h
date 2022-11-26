
extern char get_first();

// check功能，包含 列出 排序列出（5排序） 增加 插入 删除 
// check 界面
void ui_check(){
	puts("-----------------------------------------------");
	star();
	puts("-----------------------------------------------");
	puts("Welcom to check function, if you are first use ");
	puts("this function, Please read help of this function.");
	puts("Enter \'h\' to get help.");
    puts("-----------------------------------------------");
    puts("--  s. show                o. show as order  --");
    puts("-----------------------------------------------");
    puts("--  a. add info            d. delete info    --");
    puts("-----------------------------------------------");
    puts("--  h. get help of this function.            --");
    puts("--------------\'q\' to quit----------------------");
    puts("-----------------------------------------------");
}
// check 检查(由于记不清是否其他地方使用了isright，这里使用static声明)
static bool isright(char ch){
    switch(ch){
        case 'a':
            return true;
        case 's':
            return true;
        case 'd':
            return true;
        case 'o':
            return true;
        case 'h':
            return true;
        case 'q':
            return true;
        default:
            return false;
    }
}
// check 检查输入,返回正确字符
char checkin(){
    puts("Now, Please enter \'s\' \'o\' \'a\' \'d\' \'h\' \'q\' ");
    puts("to use related function! Please enter:");
    char ch = tolower(get_first());  // 清理输入流
    int i = 0;
    while(!isright(ch)&& i<10){
        puts("You have enterd a invalid word, please reenter:");
        ch = tolower(get_first());
        i++;
    }
    if (i==10)
        puts("You had missed 10 times, so exit automatically!");
    return ch;    
}
// check show info

void check_show_info(SStudent stu,const int num){
    printf("There are %d students in this system.\n",num);
    for(int i=0;i<num;i++){
        printf ("--");
        printf("%d ",stu[i].order);
        printf("%s ",stu[i].name);
        printf("%lld %d %.1lf %.1lf %.1lf %.1lf",stu[i].gra_number,
            stu[i].sex,stu[i].cgrade,stu[i].math,stu[i].eng,stu[i].chinese);
        printf("--\n");
    }
    getchar();
}
// mode check
// 错误返回0 order返回1 12，name 2，cg 3 32，m 4 42，e 5 52，ch 6 62

int modecheck(const char mode[],int n){
    /*puts("Please enter what mode you want use.");
    mode[0]=getchar();  // 读取首字母
    mode[1]=getchar();  // 读取第二个字符 可能是换行
    mode[2]='\0';
    if(!isalpha(mode[0]))
        return 0;
    if(mode[1]!='\n'){  // 处理回车影响
        while(getchar()!='\n'){     // 处理输入流
            continue;
        }
        if(mode[1]!='d')    // 错误输入
            return 0;
    }
    else
        mode[1] = '\0';     // 将mode化简，不要出现空白字符
    */
    switch(strlen(mode)){
        case 1:
            switch(mode[0]){
                case 'o':
                    return 1;
                case 'n':
                    return 2;
                case 'c':
                    return 3;
                case 'm':
                    return 4;
                case 'e':
                    return 5;
                case 'y':
                    return 6;
                case 'q':
                    return -1;
                default:
                    return 0;
            }
            break;  // 外层break；
        case 2:
            switch(mode[0]){
                case 'o':
                    return 12;
                case 'n':
                    return 2;
                case 'c':
                    return 32;
                case 'm':
                    return 42;
                case 'e':
                    return 52;
                case 'y':
                    return 62;
                default:
                    return 0;
            }
    }
    return 0;           
}
// check 信息按序输出
// mode : 'o' order, 'n' name, 'c1-c4' grade 正序，由小到大
// mode : 'od' 'c1d-c4d' 倒序，由大到小
SStudent order_ord(SStudent stu,const int num,const char answer[]){
    // 所有模式
    char order[] = {"o"},inorder[] = {"od"};
    char name[] = {"n"};
    char c_grade[] = {"c"},inc_grade[] = {"cd"};
    char math[] = {"m"},inmath[] = {"md"};
    char eng[] = {"e"}, ineng[] = {"ed"};
    // 用户输入的模式
    int m;
    while(!(m=modecheck(answer,3))){
        puts("You had enter a invalid string!");
    }
    switch(m){
        case -1:
        // 
        case 1:
            for(int i=0;i<num;i++){
                for(int j=i;j<num;j++){
                    if(stu[i].order>stu[j].order){
                        Student stutemp = stu[i];
                        stu[i] = stu[j];
                        stu[j] = stutemp; 
                    }
                }
            }
            return stu;
        case 12:
            for(int i=0;i<num;i++){
                for(int j=i;j<num;j++){
                    if(stu[i].order<stu[j].order){
                        Student stutemp = stu[i];
                        stu[i] = stu[j];
                        stu[j] = stutemp; 
                    }
                }
            }
            return stu;
        case 2:
            for(int i=0;i<num;i++){
                for(int j=i;j<num;j++){
                    if(strcmp(stu[i].name,stu[j].name)>0){
                        Student stutemp = stu[i];
                        stu[i] = stu[j];
                        stu[j] = stutemp; 
                    }
                }
            }
            return stu;
        case 3:
            for(int i=0;i<num;i++){
                for(int j=i;j<num;j++){
                    if(stu[i].cgrade>stu[j].cgrade){
                        Student stutemp = stu[i];
                        stu[i] = stu[j];
                        stu[j] = stutemp; 
                    }
                }
            }
            return stu;
        case 32:
            for(int i=0;i<num;i++){
                for(int j=i;j<num;j++){
                    if(stu[i].cgrade<stu[j].cgrade){
                        Student stutemp = stu[i];
                        stu[i] = stu[j];
                        stu[j] = stutemp; 
                    }
                }
            }
            return stu;
        case 42:
            for(int i=0;i<num;i++){
                for(int j=i;j<num;j++){
                    if(stu[i].math<stu[j].math){
                        Student stutemp = stu[i];
                        stu[i] = stu[j];
                        stu[j] = stutemp; 
                    }
                }
            }
            return stu;
        case 4:
            for(int i=0;i<num;i++){
                for(int j=i;j<num;j++){
                    if(stu[i].math>stu[j].math){
                        Student stutemp = stu[i];
                        stu[i] = stu[j];
                        stu[j] = stutemp; 
                    }
                }
            }
            return stu;
        case 5:
            for(int i=0;i<num;i++){
                for(int j=i;j<num;j++){
                    if(stu[i].eng>stu[j].eng){
                        Student stutemp = stu[i];
                        stu[i] = stu[j];
                        stu[j] = stutemp; 
                    }
                }
            }
            return stu;
        case 52:
            for(int i=0;i<num;i++){
                for(int j=i;j<num;j++){
                    if(stu[i].eng<stu[j].eng){
                        Student stutemp = stu[i];
                        stu[i] = stu[j];
                        stu[j] = stutemp; 
                    }
                }
            }
            return stu;
        case 6:
            for(int i=0;i<num;i++){
                for(int j=i;j<num;j++){
                    if(stu[i].chinese>stu[j].chinese){
                        Student stutemp = stu[i];
                        stu[i] = stu[j];
                        stu[j] = stutemp; 
                    }
                }
            }
            return stu;
        case 62:
            for(int i=0;i<num;i++){
                for(int j=i;j<num;j++){
                    if(stu[i].chinese<stu[j].chinese){
                        Student stutemp = stu[i];
                        stu[i] = stu[j];
                        stu[j] = stutemp; 
                    }
                }
            }
            return stu;
        default:
            return NULL;
    }
    return NULL;
}
// check order 界面
void check_order_ui(){
    puts("------------------------------------------------");
    puts("---------wlecom to subfunction!-----------------");
    puts("For use this subfunction,you need to konw how to");
    puts("use it,enter \'h\' to get help.");
    puts("------------------------------------------------");
    puts("--   \"o\" As order    \"od\" As inverse order    --");
    puts("--   \"n\" As name first words to show          --");
    puts("--   \"c\" As C grade  \"cd\" As inverse order    --");
    puts("--   \"m\" As math     \"md\" As inverse order    --");
    puts("--   \"e\" As english  \"ed\" As inverse order    --");
    puts("--   \"y\" As Chinese  \"yd\" As inverse order    --");
    puts("--   \"q\" to quit.                             --");
    puts("------------------------------------------------");
    puts("Please enter(Do not include quotation marks):");
}
// check order 主函数
void check_order(SStudent stu,int num){
    puts("------------------------------------------------");
    puts("-------------------welcome----------------------");
    while(1){
        check_order_ui();
        puts("Please enter what mode you want use.");
        char mode[3];
        mode[0]=getchar();  // 读取首字母
        mode[1]=getchar();  // 读取第二个字符 可能是换行
        mode[2]='\0';
        if(!isalpha(mode[0]))
            continue;
        if(mode[0]=='q')
            return;
        if(mode[1]!='\n'){  // 处理回车影响
            while(getchar()!='\n'){     // 处理输入流
                continue;
            }//while
            if(mode[1]!='d')    // 错误输入
                continue;
        }//if
        else
            mode[1] = '\0';     // 将mode化简，不要出现空白字符
        
        SStudent temp = order_ord(stu,num,mode);
        print(temp,num);
    }//while

    return;
}// fun
// add
SStudent check_add(SStudent stu,int *num){
    puts("------------------------------------------------");
    puts("-------------------welcome----------------------");
    puts("Do you want to display existing information?[y/n]");
    char whether_display = tolower(get_first());
    if(whether_display=='y')
        print(stu,*num);
    
    // add now
    
    char whether_continue = 'y';
    int add_num = 0;
    char pre_num = *num;
    SStudent result = (SStudent)malloc(sizeof(Student));
    while(whether_continue=='y'){
        add_num++;
        pre_num ++;  // 计算当前大小
        Student temp;
        temp.order = pre_num;
        printf("Please enter the name.");
        scanf("%s",(temp.name));
        /*
        char name_temp[21];
        scanf("%s",name_temp);
        int i=0;
        while(name_temp[i]!='\0'){
            (*((*stu)+pre_num-1)).name[i] = name_temp[i];
            i++;
        }
        int i;
        for(i=0;name_temp!='\n';i++){
            ((*stu)+pre_num-1)->name[i];
            name_temp = getchar();
        }
        ((*stu)+pre_num-1)->name[i]='\0';
        */
        getchar();
        puts("The student number is like 2020000000000,Please enter:");
        long long int tt; scanf("%lld",&tt);
        while(tt<=2000000000000){
            scanf("%lld",&tt);
            puts("You have enterd a invalid number, Please try again!");
        }
        temp.gra_number = tt;
        puts(" ");
        printf("Is %s boy?[y/n]  ",temp.name);
        getchar();
        char sex=tolower(get_first());   //自动清理输入流
        if(sex=='y')
            temp.sex = 1;
        else
            temp.sex = 0;
        puts("Please enter his/her grades(four lessons):");
        while(scanf("%lf %lf %lf %lf",&(temp.cgrade),&(temp.math),
          &(temp.eng),&(temp.chinese) )!= 4){  //错误读入
            puts("You don`t enter four valid number!!");
            puts("Please try again!");
        }
        temp.sum=temp.chinese+temp.cgrade+temp.eng+temp.math;
        result = (SStudent)realloc(result,add_num*sizeof(Student));
        result[add_num-1] = temp;
        
        getchar();  // 回车
        puts("Do you want to add more?[y/n]");
        whether_continue = tolower(get_first());
        
    }// while
    *num = pre_num;
    
    return result;
}
// delete ui
void del_UI(){
    puts("--------------****************------------------");
    puts("Welcom to check function, if you are first use ");
	puts("this function, Please read help of this function");
	puts("Enter \'h\' to get help.");
    puts("------------------------------------------------");
    puts("-- a. del all info      b.del info one by one --");
//    puts("-- s. delete multiple student`s info           --");
    puts("-- q. quit              h.help                --");
    puts("------------------------------------------------");
}
// del all
void del_all(SStudent *stu, int *num){
    char ch;
    puts("Do you really want to del all info?[y/n]?");
    while((ch = tolower(get_first()))!='y'&& ch !='n')
        puts("Input wrong!");
    if(ch=='n')
        return;
    puts("Please confirm it again!");
    puts("This operation cannot be undone!!");
    puts("whether to del?[y/n]");
    while((ch = tolower(get_first()))!='y'&& ch !='n')
        puts("Input wrong!");
    if(ch=='n')
        return;
    free(*stu);
    *stu = NULL;
    *num = 0;
    puts("You had del all info!");
    return;
}
// del one
SStudent del_one(SStudent stu,int *num){
    puts("Do you want to display existing information?[y/n]");
    char whether_display = tolower(get_first());
    if(whether_display=='y')
        print(stu,*num);
    union del_what
    {
        int order;
        char name[21];
        long long int stu_num;
    }del_what;
    int whether_del = 1;
    int n; // 名字多个的情况
    SStudent del_stu;
    char del = 'y';
    while(del == 'y'){
        puts("To del info, you need to find first!");
        del_stu = search_obo(stu,*num,&n);
        if(del_stu == NULL){
            puts("Wrong!");
            continue;
        }
        puts("Do you want to del this student?");
        print(del_stu,n);
        puts("Do you sure to del?[y/n]?");
        del = tolower(get_first());
    }// while
    SStudent result = (SStudent)malloc((*num)*sizeof(Student));
    for(int i=0;i<(*num);i++)
        result[i] = stu[i];
    /*
    if(n==1 && del_stu->order == *num){     //最后一个直接重新分配
        result = (SStudent)realloc(result,(*num)-1);
        return result;
    }
    */
    if(n==1){   // one case
        for(int i=(del_stu->order)-1;i<(*num)-1;i++)
            result[i] = result[i+1];
        result = (SStudent)realloc(result,(*num)-1);
        *num = (*num)-1;
        for(int i=0;i<(*num);i++){
            result[i].order = i+1;
        }
    }
    else{       // multi case
        /*
        for(int i=0;i<n;i++){   // 排序
            for(int j=i;j<n;j++){
                if(del_stu[i].order>del_stu[j].order){
                    Student tempstu;
                    tempstu = del_stu[i];
                    del_stu[i] = del_stu[j];
                    del_stu[j] = tempstu;
                }
            }
        }
        */ // 本来就是有序的
        /*
        for(int i=0;i<n-1;i++){
            for(int j=(del_stu[i].order)-1-i;j<del_stu[i+1].order;j++){ // 处理挪了之后，后面的位置
                result[j] = result[j+1];
            }
        }
        
        for(int i=(del_stu[n].order)-n;i<(*num)-1;i++)
            result[i]=result[i+1];
        */
        for(int i=0;i<n;i++){
            if(del_stu[i].order == (*num)){
                *num = (*num)-1;
                result = (SStudent)realloc(result,(*num)*sizeof(Student));
                continue;
            }
            for(int j=(del_stu[i].order)-1;j<(*num)-1;j++){
                result[j] = result[j+1]; 
                result[j].order = j+1;
            }
            *num = (*num)-1;
            result = (SStudent)realloc(result,(*num)*sizeof(Student));
        }
        
    }
    puts("------------------------------------------------");
    puts("Now there are :");
    print(result,(*num));
    puts("------------------------------------------------");
    return result;
}
// del some
bool del_mul(SStudent *stu, int *num){
    puts("This function only support to use order to del.");
    char whether_contine = 'y';
    while(whether_contine == 'y'){
        puts("Please enter all order at once. Use Spaces to separate");
        int *order = (int *)malloc(sizeof(int));
        int n = 1;
        if(!scanf("%d",order))
            puts("Error!!!!");
        if((*order)<1 || (*order)>(*num)){
            printf("This order %d is invalid!!",*order);
            n--;
        }
        char ch = getchar();
        while(ch != '\n'){
            n++;
            order = (int *) realloc(order,n*sizeof(order));
            scanf("%d",order+n-1);
            if((*(order+n-1))<1 || (*order+n-1)>(*num)){
                printf("This order %d is invalid!!",*(order+n-1));
                n--;
            }

            ch = getchar();
        }
        if(order == NULL){
            puts("Error!!!");
            return false;
        }
        printf("Do you sure to del these student?\n");
        for(int i=0;i<n;i++)
            printf("%d ",order[i]);
        printf("Do you sure?[y/n] ");
        char ch_su = tolower(get_first());
        if(ch_su != 'y')
            continue;
        for(int i=0;i<n;i++){       // 就不排列order然后间隔移动了= =   
            for(int j=order[i]-1;j<(*num)-1;j++){
                *stu[j] = *stu[j+1];
            }
            *num = *num - 1;
            *stu = (SStudent)realloc(*stu,(*num)*sizeof(Student));
            n--;
        }
        puts("Done!");
        free(order);
        printf("Would you want to contine?[y/n] ");
        whether_contine = tolower(get_first());
    }
    return true;
}
// delete 主函数
void check_del(SStudent *stu,int *num){
    puts("------------------------------------------------");
    puts("-------------------welcome----------------------");
    SStudent result = (SStudent)malloc((*num)*sizeof(Student));
    for(int i=0;i<(*num);i++)
            result[i] = (*stu)[i];
    int flag = 1;
    while(flag){
    del_UI();
    printf("Which mode do you want to use? ");
    char mode = tolower(get_first());
    while(mode!='a' && mode != 'b' /*&& mode != 's'*/&& mode != 'h'&&mode!='q'){
        puts("Invalid!");
        mode = tolower(get_first());
    }
    switch(mode){
        case 'a':
            del_all(&result,num);
            *stu = result;
            break;
        case 'b':
            *stu = del_one(result,num);
            
            break;
        /*
        case 's':
            del_mul(&result,num);
            *stu = result;
            break;
        */
        case 'q': 
            return;
        default:
            hcheck_del();
            break;
    }//switch
    } // while
    return;
}
// 主功能
void check(SStudent *stu,int *num){
    ui_check();
    char whether_continue = 'y';
    SStudent result = (SStudent)malloc((*num)*sizeof(Student));
    for(int i=0;i<(*num);i++)
            result[i] = (*stu)[i];
    while(whether_continue == 'y'){
        char ch = checkin();
        int pre_num;
        SStudent add;
        int add_num;
        switch (ch)
        {
        case 's':
            print(result, *num);
            break;
        case 'o':
            check_order(result,*num);
            break;
        case 'a':
            pre_num = *num;
            add = check_add(result,num);
            add_num = (*num) - pre_num;
            result = realloc(result,(*num)*sizeof(Student));
            for(int i=0;i<add_num;i++){
                result[pre_num+i] = add[i];
            }
            free(add);
            *stu = result;
            break;
        case 'd':
            check_del(&result,num);
            *stu = result;
            break;
        case 'q':
            return ;
        default:
        //check_help();
            break;
        }
        printf("Do you want to continue use check?[y/n] ");
        whether_continue = tolower(get_first());
    }
    return;
}

// alter

// alter UI
void alter_ui(){
    puts("------------------------------------------------");
    puts("-------------------welcome----------------------");
    puts("-- This function allowed you to alter info    --");
    puts("------------------------------------------------");
}

// alter func
void alter(SStudent *stu, int *num){
    alter_ui();
    SStudent temp_stu = (SStudent)malloc((*num)*sizeof(Student));
    for(int i=0; i<(*num);i++){
        temp_stu[i] = (*stu)[i];
    }
    printf("Do you want to alter you data?[y/n]");
    char whether_alter = tolower(get_first());
    if(whether_alter != 'y')
        return;
    puts("To alter you data, you need find it first!");
    puts("If you search you info by name, it may allow");
    puts("you to alter your first search results.");
    char whether_continue = 'y';
    SStudent result;
    while(whether_continue == 'y'){
        int find_num;
        result = search_info(temp_stu,*num,&find_num);
        puts("This is info you want to alter: ");
        print(result,1);
        printf("which lesson grade do you want to alter?('q' to give up)[c/m/e/y] ");
        getchar();
        char lesson = tolower(get_first());
        while(lesson != 'c' && lesson != 'm' && lesson != 'e' && lesson != 'y' && lesson !='q'){
            puts("Lesson Wrong!");
            lesson = tolower(get_first());
        }
        int new_grade;
        int j=0;
        switch(lesson){
            case 'c':
                printf("The pre-grade is %lf",result[0].cgrade);
                printf("You want to change to: ");
                scanf("%d",&new_grade);
                while(temp_stu[j].order!=result[0].order){
                    j++;
                }
                temp_stu[j].cgrade = new_grade;
                break;
            case 'm':
                printf("The pre-grade is %lf",result[0].math);
                printf("You want to change to: ");
                scanf("%d",&new_grade);
                
                while(temp_stu[j].order!=result[0].order){
                    j++;
                }
                temp_stu[j].math = new_grade;
                break;
            case 'e':
                printf("The pre-grade is %lf",result[0].eng);
                printf("You want to change to: ");
                scanf("%d",&new_grade);
                while(temp_stu[j].order!=result[0].order){
                    j++;
                }
                temp_stu[j].eng = new_grade;
                break;
            case 'y':
                printf("The pre-grade is %lf",result[0].chinese);
                printf("You want to change to: ");
                scanf("%d",&new_grade);
                while(temp_stu[j].order!=result[0].order){
                    j++;
                }
                temp_stu[j].chinese = new_grade;
                break;
            case 'q':
                continue;
            default:
                puts("ERRor!");
                return;
        }

        puts("Do you want to konw data after alter?[y/n]");
       getchar();
        char whether_show = tolower(get_first());
        if(whether_show == 'y')
            print(temp_stu+j,1);
        puts("Do you want to continue alter?");
        whether_continue = tolower(get_first());
    }
    *stu = temp_stu;
    return;
}