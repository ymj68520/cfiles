#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h> // 监听信号

#include "help.h"
#include "StuInform.h"
#include "menufunction.h"
#include "sysfuntions.h"
#include "check.h"


#define SLEN 13  //文件名长度上限   自定义读取文件时使用

int main(){
    // 初始读取文件内容至缓冲区 the_data
    int num_peo;
    SStudent stu;
    stu = Stuscanf("the_data", &num_peo, stu);
    //其他变量
    char cf;            //主界面首字母
    bool mainis = true; //主界面循环条件
    bool isright;       //首字母成立条件
    
    sr_decorate(); //装饰
    headline();
	password();   //iloveyou
    
    //功能展现
    while(mainis){
        main_menu();    //主菜单
        cf = get_first(); //获取首字母
        isright = checkinput(cf); //检查首字母
        while(!isright){
            puts("Please enter the valid alphabet!!!");
            puts("Pleasse try again!");
            cf = get_first(); //再次获取首字母
            isright = checkinput(cf); //再次检查首字母
        }//in-while
        //swich 相应操作
        switch (tolower(cf))  
        {
        case 'c':
            check(&stu,&num_peo); //check
            break;
        
        case 's':
            search(stu,num_peo);     // search
            break;
        case 'a':
            alter(&stu,&num_peo);
            break;
        case 'i':
            if(!insert(&stu,&num_peo))
                puts("ERROR!");
            break;
        case 'e':
            fexit();
            mainis = false;
            break;
        default: //help
            fhelp();    
            break;
        }//switch
    }//out-while
    
    FILE *fp = fopen("the_data","w");
    fprintf(fp,"%d\n",num_peo);
    for(int i=0;i<num_peo;i++){
        fprintf(fp,"%d %s %lld %d %.2lf %.2lf %.2lf %.2lf %.2lf\n",stu[i].order,stu[i].name,
            stu[i].gra_number,stu[i].sex,stu[i].cgrade,stu[i].math,stu[i].eng,
            stu[i].chinese,stu[i].sum);
    }
    fprintf(fp,"#");
    fclose(fp);
    return 0;
}//main


