#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};//定义一个结构类型

int main(/*int data[],int n //提交码图时的形式*/)
{
	int data[1000],n;//本机测试时定义，提交码图时删掉

	struct node *header,*p;
	int i=0;

	//本机测试时对data和n的初始化，提交码图时删掉
	n=3;
	for(i=0;i<n;i++)
	{
		data[i]=i+1;
	}

	header=(struct node *)malloc(sizeof(struct node));

	if(header==NULL)return 0;
	header->data=-1;// there is no data
	header->next=NULL;


	//单链表的创建：
    p = header;
    struct node *q;
	for(i=0;i<n;++i){
        q = (struct node *)malloc(sizeof(struct node));
        p->next = q;
        q->data = data[i];
        if(i<=n-1)
            p = p->next;
    }
    p->next = NULL;
	//  test
    p = header->next;
    while(p!=NULL){
        printf("%p, %d, ",p,p->data);
        p = p->next;
    }
    printf("%p",p);
	free(header);//本机测试，提交码图时删掉
	return 1;//本机测试，提交码图时删掉
	//return (int)header;
}

