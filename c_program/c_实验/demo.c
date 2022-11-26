#include "StuInform.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
int main(){
    int x;
    Student stu;
    stu.order = 1;
    char c;
    char ch[21] = "zhangsan";
    stu.name[21] = ch[21];
    stu.sex = 1;
    stu.gra_number = 2020000000001;
    stu.chinese = 90;
    stu.eng = 50;
    stu.math = 70;
    stu.cgrade = 100;
    FILE *fp = fopen("the_data","r+");
    int n=10;
    fscanf(fp,"%d",&n);
    printf("%d",n);
    fscanf(fp,"%c",&c);
    int i=0;
    while(c!='#'){
        printf("%c",c);
        fscanf(fp,"%c",&c);
        i++;
    }
    printf("\n%d\n",i);
    
    Student stu1;
    fseek(fp,2,SEEK_SET);
    fscanf(fp,"%d",&stu1.order);
    fscanf(fp,"%s",stu1.name);
    fscanf(fp,"%lld",&stu1.gra_number);
    fscanf(fp,"%d",&stu1.sex);
    fscanf(fp,"%lf %lf %lf %lf",&(stu1.cgrade),
        &(stu1.math),&(stu1.eng),&(stu1.chinese));    
    fseek(fp,-2,SEEK_END);
    fprintf(fp,"\r%d ",stu1.order);
    for(int j=0;*(stu1.name+j)!='\0';j++)
        fprintf(fp,"%c",stu1.name[j]);
    fprintf(fp," ");
    fprintf(fp,"%lld %d %.1lf %.1lf %.1lf %lf #",stu1.gra_number,stu1.sex,
        stu1.cgrade,stu1.math,stu1.eng,stu1.chinese);
    fscanf(fp,"%d",&x);
    fclose(fp);
    printf("%d\n",x);
    return 0;
}