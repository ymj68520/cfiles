#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>

int main()
{
	while(1)
	{
		printf("user@shell $>");
        fflush(stdout);//刷新缓冲区
		// 等待标准输入
		char buf[1024]={0};//用来存放获取的命令
		fgets(buf,1023,stdin);//获取输入的命令
		buf[strlen(buf)-1]='\0';
		// 对需要重定向的文件进行解析
		char *ptr1=buf;
		int ret1=0;//用于标志是清空重定项还是追击重定项的标志位
		char *retptr=NULL;//定义一个存储需要重定项的文件名指针
		while(*ptr1!='\0')
		{
			if(*ptr1=='>')
			{
				ret1=1;//如果是清空重定项将标志位置为 1
				*ptr1='\0';//这里说明命令解析完毕
				ptr1++;
			if(*ptr1=='>')	// 此时若成立 则为 >>
			{
				ret1=2;//如果是追加重定项 将标志位置为 2
				ptr1++;
			}
			while(*ptr1==' '&&*ptr1!='\0') ptr1++;
			retptr=ptr1;//这个指针指向需要文件名的起始位置
			while(*ptr1!=' '&&*ptr1!='\0') ptr1++;//将文件名走完
			*ptr1='\0';//将最后一个置为\0
			}
			ptr1++;
		}
		// 对输入的进行解析
		char *argv[32]={NULL};//定义的一个二维数组
		int argc=0;
		char *ptr=buf;
		while(*ptr!='\0')
		{
			if(*ptr!=' ')//获取输入的命令 存入数组中
			{
			argv[argc]=ptr;
			argc++;
				int i=0;
				while(*ptr!=' '&& *ptr!='\0')
				{
					ptr++;
				}
				*ptr='\0';
			}
			ptr++;
		}
		argv[argc]=NULL;//最后一个位置参数的下一个位置置空NULL  这是因为函数要求传递的字符数组的最后一个必须为NULL
		int i=0;
		// for(i=0;i<argc;i++)
		// {
		// 	printf("argv[%d]=argv[%s}\n",i,argv[i]);//可以对输入的命令进行查看
		// }
		// 创建子进程 并完子进程的程序替换
		pid_t pid=fork();
		if(pid==0)
		{	
			if(ret1==1)//这是一个清空重定向
			{		
				int fd=open(retptr,O_WRONLY|O_CREAT|O_TRUNC,0664);
				dup2(fd,1);//将标准输入重定向到retptr 也就是我们刚解析的文件名，那么原本要进行输出打印的内容就会被写入到该文件中		
			}
			else if(ret1==2)//表示这是一个追加重定向
			{
				
				int fd=open(retptr,O_WRONLY|O_CREAT|O_APPEND,0664);//追加重定项，改变上面个的写入方式即可
				dup2(fd,1);//将标准输入重定向到retptr 		
			}
			execvp(argv[0],argv);//程序替换成功就去运行程序了 失败了返回负一   成功的时候没有返回值
			perror("execvp error");//如果程序走到这里就表明程序替换失败了打印上一次系统调用接口使用的错误原因
			exit(0);
		}
		// 进程等待
		wait(NULL);
	}
	return 0;
}