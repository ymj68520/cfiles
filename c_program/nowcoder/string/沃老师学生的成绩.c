#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct INFO{
    char name[20];
    int inte;
    char *grade;
}info,*pinfo;
void swap(pinfo,pinfo);
int main (){
    int N;
    scanf("%d%*c",&N);
    info data[N]; 
    int i;
    for(i=0;i<N;i++){
        char ch = getchar();
        int j=0;
        while(ch!=' '){
            data[i].name[j] = ch;
            j++;
            ch = getchar();
        }
        data[i].name[j] = '\0';
        scanf("%d%*c",&(data[i].inte));
        int count_float = 0;
        data[i].grade = (char *)malloc(sizeof(char));
        do{
            (data[i].grade) = (char *)realloc(data[i].grade,(count_float+1)*sizeof(char));
            ch = getchar();
            data[i].grade[count_float] = ch;
            count_float++;            
        }while(ch!='\n');
        data[i].grade[count_float-1] = '\0';
        // 对于小数位为空的数据 其小数字符字符串数组为空
    }// 输入流处理
    // 整除部分 与 小数部分分开存储 小数部分使用char类型动态数组存储
    for(i=0;i<N;i++){   // 冒泡
        for(int j=i;j<N;j++){  // 数字排序为大的在前
            if(data[i].inte<data[j].inte){  // 整数部分大小明显 执行换位
                swap(data+i,data+j);
            }else if(data[i].inte==data[j].inte){    // 整数部分相同
                if(strcmp(data[i].grade,data[j].grade) < 0) // 通过strcmp函数确定字典序
                {   // 前者字典序在后
                    swap(data+i,data+j);
                }else if(strcmp(data[i].grade,data[j].grade) == 0){
                    if(strcmp(data[i].name,data[j].name) > 0)  // 前者字典序在后（名字排序为小的在前）
                    {   // 所有名字均不相同
                        swap(data+i,data+j);
                    }
                }
            }
        }
    }// 对数据进行枚举搜索排序
    for(i=0;i<N;i++){
        printf("%s %d.%s\n",data[i].name,data[i].inte,data[i].grade);
    }
    return 0;
}
void swap(pinfo data_i,pinfo data_j){
    info temp;
    temp = *data_i;
    *data_i = *data_j;
    *data_j = temp;
}