#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


//起泡排序
void bubble_sort (int a[], int n){
    bool change;
    int temp;
    for(int i=n-1,change=true;i>=1;i--){
        change = false;
        for(int j=0;j<i;j++)
            if(a[j]>a[j+1]){
                //交换位置
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                change = true;
            }
    }
}

//选择排序
void select_sort (int a[], int n){
    int minindex;  //最小值索引
	int min;	   //最小值
    for(int i = 0; i < n-1; i++){
        minindex = i; //初始化索引
        min = a[minindex]; //初始化最小值
        for(int j = i + 1; j < n-1; j++){
            if(min > a[j]){ //查找后n-1项
                min = a[j];
                minindex = j;
            }
        }
        if(minindex != i){  //换位
            a[minindex] = a[i];
            a[i] = min;
        }
    }
}

//归并排序 merge sort 
void merge_sort (int a[], int n){

}

//快速排序 quick sort
#include <math.h>
//打印函数
void display(int array[],int maxlen)
{
	int i;

	for(i=0 ; i<maxlen ; i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");

	return;
}
//交换函数
void swap(int *a,int *b)
{
	int temp;
	temp= *a;
	*a= *b;
	*b= temp;

	return;
}
//快速排序算法
void QSort(int array[], int begin, int end)
{
	int i,j;
	display(array,end+1);
	if(begin < end)
	{
		i= begin+1;	//将array[begin]作为基准数
		j= end;	//array[end]是数组最后一位
		while(i < j)
		{
			if(array[i] > array[begin])
			{
				swap(&array[i],&array[j]);	//如果该元素大于基准数，则交换位置
				j--;
			}
			else
			{
				i++;	//继续比较
			}
		}
		//跳出后i=j

		if(array[i] >= array[begin])	//特殊情况
		{
			i--;
		}

		swap(&array[begin],&array[i]);	//将基准数换至分界点

		QSort(array,begin,i);	//继续排序，以此类推，直到begin == i，j == end
		QSort(array,j,end);	//或者说直到第二第三两个参数相等
	}
}


