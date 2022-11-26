#include <stdio.h>

struct Person{ 
    int no;
    int age;
    int height;
};

int main(){
    #define LEN 2
    struct Person array[LEN] = { };
    sort(array,LEN);
    printf("%d\n",array[0].height);
}
//冒泡排序 time out 

//(4) chao shi
void sort(struct Person * array, int n){
    struct Person temp[1];  //介质结构体
    if(n <= 0){
        printf("error");
        return;
    }
    if(array == NULL){
        printf("error");
        return;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            //no age height 均相等error
            if(array[i].no == array[j].no)
                if(array[j].age == array[i].age)
                    if(array[i].height == array[j].height)
                    {    
                        printf("error");
                        return;
                    }
            if(array[j].no < array[i].no){  //比较no
                temp[0] = array[j];
                array[j] = array[i];
                array[i] = temp[0];
            }
            else if(array[j].no == array[i].no){ 
                if(array[j].age < array[i].age){    //比较age
                temp[0] = array[j];
                array[j] = array[i];
                array[i] = temp[0];
                }
                else if(array[i].age == array[j].age){
                    if(array[j].height < array[i].height){  //比较height 无需考虑height是否相等
                        temp[0] = array[j];
                        array[j] = array[i];
                        array[i] = temp[0];
                    }

                }
            }
        }
    }

    return;
}


//冒泡排序 (4)chao shi 
void bubble_sort (struct Person * array, int n){
    struct Person temp[1];  //介质结构体
    int change = 1;
    if(n == 0){
        printf("error");
        return;
    }
    if(array == NULL){
        printf("error");
        return;
    }
    for(int i=n-1,change=1;i>=1;i--){
        change = 0;
        for(int j=0;j<i;j++)
            if(array[j].no>array[j+1].no){
                //交换位置
                temp[0] = array[j];
                array[j] = array[j+1];
                array[j+1] = temp[0];
                change = 1;
            }
            else if(array[j].no==array[j+1].no){
                if(array[j].age>array[j+1].age){
                    temp[0] = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp[0];
                    change = 1;
                }
                else if(array[j].age==array[j+1].age){
                    if(array[j].height == array[j+1].height){
                        temp[0] = array[j];
                        array[j] = array[j+1];
                        array[j+1] = temp[0];
                        change = 1;
                    }
                }
            }
    }
    return;
}

//选择排序 time out
void s_sort(struct Person *array, int n){
    struct Person min;
    int min_index;
    if(n == 0){
        printf("error");
        return;
    }
    if(array == NULL){
        printf("error");
        return;
    }
    for(int i=0; i<n; i++){
        min_index = i;
        min = array[i];
        for(int j = i+1; j<n; j++){
            if(array[j].no == array[i].no && 
                array[j].age == array[i].age &&
                array[j].height == array[i].height){
                printf("error");
                return;
            }
            if(min.no > array[j].no){
                min = array[j];
                min_index = j;
            }
            else if(min.no == array[j].no){
                if(min.age > array[j].age){
                    min = array[j];
                    min_index = j;
                }
                else if(min.age == array[j].age){
                    if(min.height > array[j].height){
                        min = array[j];
                        min_index = j;
                    }
                }
            }
        } 
        if(min_index != i){
            array[min_index] = array[i];
            array[i] = min;
        }
    }
}

//快速排序 
void qsort(struct Person *array, int n){
    for(int i=0;i<n-1;i++){
        if(array[i].no == array[i+1].no &&
        array[i].age == array[i+1].age &&
        array[i].height == array[i+1].height)
            printf("error");
        
        return ;
    }
    if(array == NULL || n == 0){
        printf("error");
        
        return;
    }
    int begin = 0;
    int end = n-1;
    Qsort(array, begin, end);

    return;
}

void swap(struct Person *ar1, struct Person *ar2){
    struct Person temp;
    temp = *ar1;
    *ar1 = *ar2;
    *ar2 = temp;

    return;
}

void Qsort(struct Person *array, int begin, int end){
    int i,j;
    if(begin < end){
        j = end;
        i = begin + 1;
        while(i < j){
            if(array[i].no > array[begin].no){
                swap(&array[i],&array[j]);
                j--;
            }
            else if(array[i].no == array[j].no){
                if(array[i].age > array[j].age){
                    swap(&array[i],&array[j]);
                    j--;
                }
                else if(array[i].age == array[j].age){
                    if(array[i].height >array[j].height){
                        swap(&array[i],&array[j]);
                        j--;
                    }
                }
            }
            else{
                i++;
            }
        }
        if(array[i].no > array[begin].no){
            i--;
        }
        else if(array[i].no == array[begin].no){
            if(array[i].age > array[begin].age){
                i--;
            }
            else if(array[i].age == array[begin].age){
                if(array[i].height > array[begin].height){
                    i--;
                }
            }
        }
        swap(&array[begin],&array[i]);

        Qsort(array,begin,i);
        Qsort(array,j,end);
    }
}
