//学生管理系统
#include <stdio.h>
#include <string.h>

struct student{
    char name[20];
    int sex;
    int birth;
    double stature;
    int c;
    int math;
};

int findx(struct student const *st,int n, int t); //n=0->c  n=1->math
int findi(struct student const *st,int n, int t); //x->max  i->min
void findg(struct student const *st,int n,int grade,int what);//查找相应分数并输出
void pt(struct student const *st,int who);            //输出相应结构数组成员

int main(){
    int n;
    scanf("%d",&n);
    getchar(); //处理空格
    struct student st[n];
    // 输入处理
    for(int i=0;i<n;i++){
        int j=0;
        while((st[i].name[j] = getchar()) != ' '){
            j++;
        }
        scanf("%d",&st[i].sex);
        getchar();
        scanf("%d",&st[i].birth);
        getchar();
        scanf("%lf",&st[i].stature);
        getchar();
        scanf("%d",&st[i].c);
        getchar();
        scanf("%d",&st[i].math);
        getchar();
    }

    //计算
    //c
    int s_c=0,a_c,max_c,min_c;
    for(int i=0;i<n;i++)   //qiuhe
        s_c += st[i].c;
    a_c = s_c / n;         //c average
    max_c = findx(st,n,0);
    min_c = findi(st,n,0);

    // math
    int s_m=0,a_m,max_m,min_m;
    for(int i=0;i<n;i++)
        s_m += st[i].math;
    a_m = s_m / n;
    max_m = findx(st,n,1);
    min_m = findi(st,n,1);

    //shu chu
    printf("C_average:%d\nC_max:%d\n",a_c,max_c);
    findg(st,n,max_c,0);
    printf("C_min:%d\n",min_c);

    printf("Calculus_average:%d\nCalculus_max:%d\n",a_m,max_m);
    findg(st,n,max_m,1);
    printf("Calculus_min:%d\n",min_m);
    
    return 0;
}

int findx(struct student const *st,int n,int t){
    int temp=0;
    if(t == 0){
        for(int i=0;i<n;i++){
            if(temp < st[i].c)
                temp = st[i].c;
        }
        return temp;
    }
    else{
        for(int i=0;i<n;i++){
            if(temp < st[i].math)
                temp = st[i].math;
        }
        return temp;
    }
}

int findi(struct student const *st,int n,int t){
    int temp = 100;
    if(t == 0){
        for(int i=0;i<n;i++){
            if(temp > st[i].c)
                temp = st[i].c;
        }
        return temp;
    }
    else{
        for(int i=0;i<n;i++){
            if(temp > st[i].math)
                temp = st[i].math;
        }
        return temp;
    }
}

void findg(struct student const *st,int n,int grade,int what){
    if(what == 0){
        for(int i=0;i<n;i++){
            if(st[i].c == grade)
                pt(st,i);
        }
    }
    else
    {
        for(int i=0;i<n;i++){
            if(st[i].math == grade)
                pt(st,i);
        }
    }
    return ;
}
void pt(struct student const *st, int who){
    int len = strlen(st[who].name);
    for(int i=0;i<len-1;i++)
        putchar(st[who].name[i]);
    printf(" %d %d %.2lf %d %d",st[who].sex,st[who].birth,
        st[who].stature,st[who].c,st[who].math);
    putchar('\n');
}
