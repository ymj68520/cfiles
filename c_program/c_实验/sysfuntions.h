#define bool _Bool
#define true 1
#define false 0

extern void exit(int _status);
extern char get_first();
extern int puts(const char * __s);

// 装饰品
void star()
{
int a[15][37]={0};
int i,j;
a[0][18]=1;
for(j=17;j<20;j++)
    a[1][j]=1;
for(j=16;j<21;j++)
    a[2][j]=1;
for(j=15;j<22;j++)
    a[3][j]=1;
for(j=14;j<23;j++)
    a[4][j]=1;
for(j=1;j<36;j++)
    a[5][j]=1;
for(j=4;j<33;j++)
    a[6][j]=1;
for(j=7;j<30;j++)
    a[7][j]=1;
for(j=10;j<27;j++)
    a[8][j]=1;
for(j=12;j<25;j++)
    a[9][j]=1;
for(j=11;j<26;j++)
    a[10][j]=1;
for(j=10;j<18;j++)
    a[11][j]=1;
for(j=19;j<27;j++)
    a[11][j]=1;
for(j=9;j<15;j++)
    a[12][j]=1;
for(j=22;j<28;j++)
    a[12][j]=1;
for(j=8;j<12;j++)
    a[13][j]=1;
for(j=25;j<29;j++)
    a[13][j]=1;
for(j=7;j<9;j++)
    a[14][j]=1;
for(j=28;j<30;j++)
    a[14][j]=1;
a[15][6]=1,a[15][31]=1;
for(i=0;i<15;i++)
{
    for(j=0;j<37;j++)
        if(a[i][j]==1) printf("*");
        else printf(" ");
    printf("\n");
}
}

//主菜单
void showhelp(){
    puts("This information management system is powerful, so you can use it to perform the operation you want");
    puts("It includes viewing, deleting, and inserting information, as well as executing exit procedures.");
    //puts("");
    return;    
}
//查看
void show_check(){
    puts("\t1:Check includes student information check and grade check.");
    puts("\tCheck information includes personal information view and all information view.");
    puts("\tPersonal information viewing lists only the details of a specific person.");
    puts("\tThe full information view will list all the people in the existing information base.");
    puts("\tYou can also arbitrarily swap the order of two students by their serial numbers.");
    return;
}
//删除
void show_del(){
    puts("\t2:The delete function supports you to delete the information of a student.");
    puts("\tYou will be asked which objects you want to remove.");
    puts("\tIt could be one person's information or all informations.");
    puts("\tYou can delete it by typing the student's serial number, name, or student number.");
    puts("\tThe system will remind you to change a method when you input a certain item with duplicate information.");
    puts("\tIt is recommended that you delete the information by the student's serial number.");
    return;
}
//插入
void show_ins(){
    puts("\t3:The insert operation allows you to insert information into an existing database.");
    puts("\tYou need to enter the corresponding information according to the system prompt.");
    puts("\tPlease do not enter at will, otherwise the system will prompt you to input error and ask you to enter again.");
    puts("\tOf course you can enter more than one information at a time, but please follow the prompts.");
    return;
}
//退出
void show_ex(){
    puts("\t4:The exit function will exit the program. Please think twice before you do so.");
    puts("\tOf course, the system will prompt you if you need to quit.");
    return;
}
//检查输入字母是否为功能mark
bool checkal(char ch){
    if(ch == 'c')
        return true;
    if(ch == 's')
        return true;
    if(ch == 'h')
        return true;
    if(ch == 'e')
        return true;
    return false;
}
//检查再次输入是否正确
bool checkalag(char ch){
    if(ch == 'm')
        return true;
    if(ch == 'q')
        return true;
    return false;
}
//帮助功能
void fhelp(){
    puts("------------------------------------------------");
    puts("To use help, there are some functions you could use.");
    bool is = true;
    while(is){
        puts("------------------------------------------------");
        showhelp();
        puts("To enter the function mark to view relative help.");
        puts("Such as \"c\" to view the function of check.");
        puts("Please enter: ");
        char ch = get_first();
        while(!checkal(ch)){
            puts("Please enter the valid alphabet !!");
            ch = get_first();
        }//while
        switch (ch)
        {
        case 'c':
            show_check();
            break;
    
        case 'd':
            show_del();
            break;
    
        case 'i':
            break; //////
            show_ins();
            break;
    
        default:
            show_ex();
            break;
        }//switch
    
        puts("If you want to read more ,please enter the \"m\".");
        puts("If you want to qiut, Please enter \"q\".");
        char cf = get_first();
        while(!checkalag(cf)){
            puts("Please enter the valid alphabet !!");
            cf = get_first();
        }//while
        
        if(cf == 'm')   is = true;
        else    return; 

    }//while
}

//退出功能
void fexit(){
    puts("Do you really want to quit?");
    puts("If you do,Please enter the \"e\" again!");
    char ch;
    ch = tolower(get_first());
    if(ch != 'e'){
        puts("You can continue to use this system!!");
        return;
    }
    puts("Bye!");
}

// check 单独成文

// search 

//search UI
void search_info_ui(){
    puts("------------------------------------------------");
    puts("-------------------welcome----------------------");
    puts("------------------------------------------------");
    puts("------------------------------------------------");
    puts("--         a. Search one by one               --");
    puts("--         b. Search some infomation          --");
    puts("------------------------------------------------");
}
//search input check

//search one by one
SStudent search_obo(SStudent stu,int num,int *ns){
    char whether_continue = 'y';        // 一次性，没有用
    Student temp;
    union what_to_search{
        int order;
        long long stu_num;
    }what_to_search;
    char name[21];
    puts("Would you like to search what?");
    puts("[o]order [n]name [s]stu number?");
    char ch = tolower(get_first());
    SStudent result = NULL;
    switch(ch){
        case 'o':
            puts("Please enter order: ");
            scanf("%d",&what_to_search.order);
            for(int i=0; i<num;i++)     // order obly have one
                 if(stu[i].order==what_to_search.order){
                    result = (SStudent)malloc(sizeof(Student));
                    *result = stu[i];
                }
            if(result==NULL){
                puts("Not find this oprder! Please chech!");
                return NULL;
            }
            *ns = 1;
            break;
        case 'n':
            puts("Please enter name: ");
            int n = 0;
            scanf("%s",name);
            for(int i=0; i<num; i++)      // name likely to repeat
                if(!strcmp(name,(stu[i].name))){
                    n++;
                    result = (SStudent)realloc(result,n*sizeof(Student));
                    result[n-1] = stu[i];
                }
            if(result == NULL){
                puts("Not find! Please check!");
                return NULL;
            }
            *ns = n;
            break;
        case 's':
            puts("Please enter stu num:");
            scanf("%lld",&what_to_search.stu_num);
            for(int i=0; i<num;i++)     // stu_num only have one
                if(stu[i].gra_number==what_to_search.stu_num){
                    result = (SStudent)malloc(sizeof(Student));
                    *result = stu[i];
                }
            if(result == NULL){
                puts("Not find! Please check!");
                return NULL;
            }
            *ns = 1;
            break;
        default:
            puts("You had enter a wrong alphabat,Please try again!");
            return NULL;
            break;
        }
    return result;
}
// search main function
SStudent search_multi(SStudent stu, int num){
    SStudent temp;
    SStudent result;
    int n=1,i=0;        // 计数器
    int len=0;          // 长度
    char whether_continue = 'y';
    while(whether_continue=='y'){
        int num_m=0;
        temp = search_obo(stu, num, &num_m);
        if(temp == NULL){       // 错误，没找到
            puts("Would you want to continue?[y/n]");
            char ch = tolower(get_first());
            if(ch == 'y')
                continue;
            else if(ch =='n')
                break;
            puts("You had enter a wrong alphabet!");
            continue;
        }
        
        len+=num_m;
        result = (SStudent)realloc(result,len);
        int j=0;
        for(;i<len;i++,j++){
            result[i]=temp[j];
        }
        puts("Would you want to continue?[y/n]");
        whether_continue = tolower(get_first());
        if(whether_continue == 'y')
            continue;
        else if(whether_continue == 'n')
            break;
        else{
            puts("You enter a wrong alphabet!!");
            puts("It will continue automaticly!!");
            continue;
        }
    }
    return result;      // 将寻找到点了所有结果返回
}
SStudent search_info(const SStudent stu,const int num,int *nss){
    //search_info_ui();
    char whether_continue = 'y';
    SStudent result = (SStudent)malloc(sizeof(Student));
    int re_n=0;
    int pre_n=0;
    while(whether_continue == 'y'){
        //puts("\'q\' to quit.");
        //printf("Which mode would you like to use?[a/b]");
        //char ch = tolower(get_first());
        SStudent temp = NULL;
        //while(ch!='a' && ch!='b'&& ch!='q'){
        //    puts("Invalid alphabet, Please try again!!!");
        //    ch = tolower(get_first());
        //} // while
        int n=0;
        switch('a'){
            case 'a':
                temp=search_obo(stu,num,&n);
                break;
            case 'b':
                temp=search_multi(stu,num);
                break;
            default:
                puts("None to search!");
                return NULL;
        }
        // 多次查找的集合
        pre_n = re_n;       // 前置 N
        re_n += n;          // 现在的 N
        result = (SStudent)realloc(result,re_n*sizeof(Student));
        *nss = re_n;
        int j=0;
        //print(temp,n);
        for(int i=pre_n;i<re_n,j<n;i++,j++){
            result[i] = temp[j];    // 赋值
        }
        //printf("Do you want to continue?[y/n] ");
        //whether_continue = tolower(get_first());
        whether_continue = 'n';
    }// while

    return result;
}

// 实现搜索的 最高分 最低分 

// 单科最高/低
SStudent search_g(SStudent stu,int num,int *nss){
    puts("------------------------------------------------");
    puts("------------------------------------------------");
    puts("-- c. c language                 m. math      --");
    puts("-- e. English                    y. Chinese   --");
    puts("------------------------------------------------");
    puts("------------------------------------------------");
    printf("Which subject do want to search?[c/m/e/y]");
    char subject = tolower(get_first());
    while(subject!='c'&&subject!='m'&&subject!='e'&&subject!='y'){
        puts("You enter a wrong alphabet!!");
        printf("Which subject do want to search?[c/m/e/y]");
        subject = tolower(get_first());
    }
    printf("Do you want to find highest grade or lowest?[h/l]");
    char grade = tolower(get_first());
    while(grade!='h'&&grade!='l'){
        puts("You enter a wrong alphabet!!");
        printf("Do you want to find highest grade or lowest?[h/l]");
        grade = tolower(get_first());
    }
    SStudent temp = (SStudent)malloc(sizeof(Student));
    *temp = stu[0];
    int index_s = 0;
    switch(subject){
        case 'c':
            if(grade == 'h'){
                for(int i=1;i<num;i++){
                    if(stu[i].chinese>temp->cgrade){
                        *temp = stu[i];
                        index_s = i;
                    }
                }//for
                int n=1;
                for(int i=0;i<num;i++){
                    if(index_s = i)
                        continue;
                    if(temp == stu+i){
                        n++;
                        temp = realloc(temp,n*sizeof(Student));
                        temp[n-1] = stu[i];
                    }
                }
                *nss = n;
                return temp;
            }
            if(grade == 'l'){
                for(int i=1;i<num;i++){
                    if(stu[i].cgrade<temp->cgrade)
                        *temp = stu[i];
                }//for
                int n=1;
                for(int i=0;i<num;i++){
                    if(index_s = i)
                        continue;
                    if(temp == stu+i){
                        n++;
                        temp = realloc(temp,n*sizeof(Student));
                        temp[n-1] = stu[i];
                    }
                }
                *nss = n;
                return temp;
            }
            break;
        case 'm':
            if(grade == 'h'){
                for(int i=1;i<num;i++){
                    if(stu[i].math>temp->math)
                        *temp = stu[i];
                }//for
                int n=1;
                for(int i=0;i<num;i++){
                    if(index_s = i)
                        continue;
                    if(temp == stu+i){
                        n++;
                        temp = realloc(temp,n*sizeof(Student));
                        temp[n-1] = stu[i];
                    }
                }
                *nss = n;
                return temp;
            }
            if(grade == 'l'){
                for(int i=1;i<num;i++){
                    if(stu[i].math<temp->math)
                        *temp = stu[i];
                }//for
                int n=1;
                for(int i=0;i<num;i++){
                    if(index_s = i)
                        continue;
                    if(temp == stu+i){
                        n++;
                        temp = realloc(temp,n*sizeof(Student));
                        temp[n-1] = stu[i];
                    }
                }
                *nss = n;
                return temp;
            }
            break;
        case 'e':
            if(grade == 'h'){
                for(int i=1;i<num;i++){
                    if(stu[i].eng>temp->eng)
                        *temp = stu[i];
                }//for
                int n=1;
                for(int i=0;i<num;i++){
                    if(index_s = i)
                        continue;
                    if(temp == stu+i){
                        n++;
                        temp = realloc(temp,n*sizeof(Student));
                        temp[n-1] = stu[i];
                    }
                }
                *nss = n;
                return temp;
            }
            if(grade == 'l'){
                for(int i=1;i<num;i++){
                    if(stu[i].eng<temp->eng)
                        *temp = stu[i];
                }//for
                int n=1;
                for(int i=0;i<num;i++){
                    if(index_s = i)
                        continue;
                    if(temp == stu+i){
                        n++;
                        temp = realloc(temp,n*sizeof(Student));
                        temp[n-1] = stu[i];
                    }
                }
                *nss = n;
                return temp;
            }
            break;
        case 'y':
            if(grade == 'h'){
                for(int i=1;i<num;i++){
                    if(stu[i].chinese>temp->chinese)
                        *temp = stu[i];
                }//for
                int n=1;
                for(int i=0;i<num;i++){
                    if(index_s = i)
                        continue;
                    if(temp == stu+i){
                        n++;
                        temp = realloc(temp,n*sizeof(Student));
                        temp[n-1] = stu[i];
                    }
                }
                *nss = n;
                return temp;
            }
            if(grade == 'l'){
                for(int i=1;i<num;i++){
                    if(stu[i].chinese<temp->chinese)
                        *temp = stu[i];
                }//for
                int n=1;
                for(int i=0;i<num;i++){
                    if(index_s = i)
                        continue;
                    if(temp == stu+i){
                        n++;
                        temp = realloc(temp,n*sizeof(Student));
                        temp[n-1] = stu[i];
                    }
                }
                *nss = n;
                return temp;
            }
            break;
        default:
            *nss = 0;
            return NULL;
    }
    return NULL;
}
// 总分最高/低
SStudent search_s(SStudent stu,int num,int *nss){
    puts("------------------------------------------------");
    puts("Do you want to Find highest/Lowest ");
    printf("sum grade?[h/l] ");
    char ch = tolower(get_first());
    puts("------------------------------------------------");
    while(ch != 'h' && ch != 'l'){
        puts("You enter a wrong alphabet! Please try again!");
        printf("Do you want?[h/l] ");
        ch = tolower(get_first());
    }
    SStudent temp = (SStudent)malloc(sizeof(Student));
    *temp = stu[0];
    int index_s;
    if(ch == 'h'){
        for(int i=1;i<num;i++){
            if(stu[i].sum>temp->sum){
                *temp = stu[i];
                index_s = i;
            }
        }//for
    }else if(ch == 'l'){
        for(int i=1;i<num;i++){
            if(stu[i].sum<temp->sum){
                *temp = stu[i];
                index_s = i;
            }
        }//for
    }
    int ns=1;
    for(int j=0;j<num;j++){
        if(j==index_s)
            continue;
        if(temp[0].sum==stu[j].sum){
            ns++;
            temp = realloc(temp,ns*sizeof(Student));
            temp[ns-1] = stu[j];
        }
    }
    *nss = ns;
    return temp;
}
// 主搜索界面
void search_ui(){
    puts("------------------------------------------------");
    star();
    puts("------------------------------------------------");
    puts("--This function allow you to find someinfo you--");
    puts("--want base in data you had write in it before--");
    puts("------------------------------------------------");
    puts("--  f. Find one/muti student in database      --");
    puts("--  g. Find one subject`s highest(L) grade    --");
    puts("--  s. Find highest(L) sum grade              --");
    puts("--  q. quit                                   --");
    puts("------------------------------------------------");
    printf("Which function do you want to use?[f/g/s/q]");
}

// search()
void search(SStudent stu,int num){
    char whether_continue = 'y';
    while(whether_continue == 'y'){
        search_ui();
        char func = tolower(get_first());
        // 此处省略输入判断 默认输出不符自动退出
        SStudent temp;
        int n;
        switch(func){
            case 'f':
                temp = search_info(stu,num,&n);
                if(temp == NULL)
                    puts("Error!!");
                puts("Get these info:");
                print(temp,n); // 多组结果的情况
                break;
            case 'g':
                temp = search_g(stu,num,&n);
                if(temp == NULL)
                    puts("Error!!");
                puts("Get these info:");
                print(temp,n); // 多组结果的情况
                break;
            case 's':
                temp = search_s(stu,num,&n);
                if(temp == NULL){
                    puts("Error!!");
                    break;
                }
                puts("Get these info:");
                print(temp,n); // 多组结果的情况
                break;
            default:    // 包含了q to quit 和不合法输入的情况
                return;
        }
        printf("Would you like to continue?[y/n]");
        whether_continue = tolower(get_first()); // 默认不是y就退出
    }
    return;
}

// insert 

// Insert UI
void insert_UI(){
    puts("------------------------------------------------");
    puts("-------------------welcome----------------------");
    puts("-- This function allowed you to insert info   --");
    puts("------------------------------------------------");
    puts("--  b. Insert before someone                  --");
    puts("--  l. Insert after someone                   --");
    puts("--  h. help                q. quit            --");
    puts("------------------------------------------------");
    printf("What mode do you want to use?[b/l] ");
}
bool check_grade(Student stu){
    
    if(stu.cgrade<0 || stu.cgrade>100){
        puts("entered C language grade wrong!");
        return false;
    }
    if(stu.math<0 || stu.math>100){
        puts("Entered math grade wrong !");
        return false;
    }
    if(stu.eng<0 || stu.eng>100){
        puts("Enterde English grade wrong!");
        return false;
    }
    if(stu.chinese<0 || stu.chinese>100){
        puts("Entered Chinese grade wrong!");
        return false;
    }

    return true;
    
}

bool insert(SStudent *stu,int *num){
    char whether_continue = 'y'; 
    Student temp;
    puts("------------------------------------------------");
        star();
    puts("------------------------------------------------");
    puts("--------------------welcome---------------------");
    //printf("Do you want to see existing data?[y/n] ");
    //char show_data = getchar();
    //if(show_data == 'y')
    //    print(*stu,*num);
    while(whether_continue == 'y'){
        insert_UI();
        char mode = tolower(get_first());
        while(mode != 'b' && mode != 'l' && mode != 'h'&& mode != 'q'){
            puts("Wrong ！！");
            printf("What mode do you want to use?[b/l/h] ");
            mode = tolower(get_first());
        }
        if(mode == 'q')
            return true;
        if(mode == 'h'){
            Insert_hel();
            continue;
        }
        puts("------------------------------------------------");
        puts("Now, Please enter the info you want to insert!");
        puts("[name] [stu number] [gender] [grade1] [g2] [g3] [g4]");
        scanf("%s %lld",temp.name,&(temp.gra_number));
        if(temp.gra_number<2020000000000 && temp.gra_number>2999999999999){
            puts("Entered stu number wrong!");
            continue;
        }
        char whe_boy[5]; scanf("%s",whe_boy);
        if(whe_boy != "boy" && whe_boy != "girl"){
            puts("Entered gender wrong!");
            continue;
        }
        scanf("%lf %lf %lf %lf",&(temp.cgrade),&(temp.math),&(temp.eng),&(temp.chinese));
        if(!check_grade(temp)){
            continue;
        }
        temp.sum = temp.cgrade+temp.chinese+temp.eng+temp.math;
        puts("Do you want to insert this info? ");
        print(&temp,1);
        printf("Do you sure?[y/n]");
        char whether_insert = tolower(get_first());
        if(whether_insert != 'y'){
            continue;
        }

        printf("where do you want to insert?[order] ");
        int order; scanf("%d",&order);
        while(order<0 || order >*num){
            puts("Order is Invalid ! ");
            scanf("%d",&order);
        }
        switch(mode){
            case 'b':
                if(order == 0){
                    puts("Order invalid!");
                    continue;
                }
                *num = (*num) + 1;
                *stu = (SStudent)realloc(*stu,(*num)*sizeof(Student));
                for(int i=(*num);i>order;i--){
                    *stu[i] = *stu[i-1];
                }
                *stu[order] = temp;                    
                break;
            case 'l':
                if(order == *num){
                    puts("Order Invalid!");
                    continue;
                }
                *num = (*num) + 1;
                *stu = (SStudent)realloc(*stu,(*num)*sizeof(Student));
                for(int i=(*num);i>order+1;i--){
                    *stu[i] = *stu[i-1];
                }
                *stu[order+1] = temp;                    
                break;
            default:
                puts("ERROR!");
                return false;
                break;
        }// swich
        printf("Do you want to show data now?[y/n] ");
        whether_insert = tolower(get_first());
        if(whether_insert=='y') // 借用whether_insert
            print(*stu,*num);
        puts("Done!!");
        // order order
        for(int i=0;i<*num;i++){
            (*stu[i]).order = i+1;
        }
        printf("Do you want to continue?[y/n] ");
        whether_continue = tolower(get_first());
    }

    return true;
}

