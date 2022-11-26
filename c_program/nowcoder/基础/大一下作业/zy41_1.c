#include <stdio.h>
#include <string.h>

struct Person{
int no;
int age;
int height;
};

void sort(struct Person * array,int n)
{
struct Person temp;
int i = 0;
int j = 0;
if(n > 0 && array != NULL)
{
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 -i; j++)
        {
            if (array[j].no > array[j+1].no)
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }//if
            else if (array[j].no == array[j+1].no && array[j].age > array[j+1].age)
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }//else if
            else if ((array[j].no == array[j+1].no) && (array[j].age == array[j+1].age)
                        && (array[j].height > array[j+1].height))
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }//else if
        }//in-for
    }//out-for
}//if
else {
    printf("error");
}//else
}//sort
