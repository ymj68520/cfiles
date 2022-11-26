#include "thread_hdr.h"

pthread temp = NULL;//就绪队列中间变量 队头
pthread tempBlock;//阻塞队列中间变量 队头
int flag = 0;//判断线程能否重新进入就绪队列
int flagOnClock = 0;//为时间调度on_click先执行一次schedule()
unsigned int ticks_s;//时间片
unsigned int interval_s;//时间间隔
//int flag2 = 0;
//hread temp2;
void add_ready_thread(thread* ready_thread)
{
	// 相应的代码实现
	//入队
	ready_thread->clock_times = 0;
	ready_queue.push_back(ready_thread);
}

void schedule()
{
	//实验二注意当就绪队列有一个线程的情况，也会出现ready_queue.size()==0
	if (flag == 1 && temp != NULL) {
		//实验一中线程不会结束
		add_ready_thread(temp);
	}
	if (ready_queue.size() == 0) {
		temp = NULL;
		current_thread = &idle_thread;
		flagOnClock = 0;
		flag = 0;
	}else{
		//句子1
		current_thread->clock_times = 0;
		// 相应的代码实现
		temp = ready_queue.front();
		current_thread = temp;
		//出队，控制ready_queue.size()大小
		ready_queue.pop_front();
		flag = 1;
	}
}
void current_thread_finished()
{
	// 实现的代码
	flag = 0;
	schedule();
}

void current_thread_blocked()
{
	// 相应的代码实现
	//加入阻塞队列
	blocked_queue.push_back(current_thread);
	//出队就绪队列，更换当前运行线程
	flag = 0;
	schedule();
}

void notify()
{
	// 相应的代码实现
	tempBlock = blocked_queue.front();
	blocked_queue.pop_front();
	add_ready_thread(tempBlock);
}

void notify_all()
{
	// 相应的代码实现
	//遍历
	int length = (int)blocked_queue.size();
	for (int i = 0; i < length; i++) {
		tempBlock = blocked_queue.front();
		blocked_queue.pop_front();
		add_ready_thread(tempBlock);
	}
}
void on_clock()
{
	// 相应的代码实现
	//注意thread_tester没有先执行schedule()
	if (flagOnClock == 0) {
		schedule();
		flagOnClock = 1;
	}
	current_thread->clock_times += interval_s;
	if (current_thread->clock_times > ticks_s) {
		//这句位置调到句子1 75
		//current_thread->clock_times = 0;
		schedule();
		
		//这一句加上去掉都是50
		current_thread->clock_times += interval_s;
	}
	//这一句也是同样效果
	//current_thread->clock_times += interval_s;
}

//oid on_clock()
//{
//	if (flag2 == 1) {
//		add_ready_thread(temp2);
//	}
//	flag2 = 0;
//	// 相应的代码实现
//	//注意thread_tester没有先执行schedule()
//	if (flagOnClock == 0) {
//		schedule();
//		flagOnClock = 1;
//	}
//	current_thread->clock_times += interval_s;
//	if (current_thread->clock_times > ticks_s) {
//		//这句位置调到句子1 75分
//		//current_thread->clock_times = 0;
//		//实验二注意当就绪队列有一个线程的情况，也会出现ready_queue.size()==0
//		flag2 = 1;
//		temp2 = current_thread;
//		if (ready_queue.size() == 0) {
//			current_thread = &idle_thread;
//			flagOnClock = 0;
//			flag = 0;
//		}
//		else
//		{
//			//句子1
//			current_thread->clock_times = 0;
//			// 相应的代码实现
//			temp = ready_queue.front();
//			current_thread = temp;
//			//出队，控制ready_queue.size()大小
//			ready_queue.pop_front();
//			flag = 1;
//		}
//
//		//这一句加上去掉都是50分
//		//current_thread->clock_times += interval_s;
//	}
//	//这一句也是同样效果
//	//current_thread->clock_times += interval_s;
//}


void set_time_ticks(unsigned int ticks)
{
	// 相应的代码实现
	ticks_s = ticks;
}

void set_time_interval(unsigned int interval)
{
	// 相应的代码实现
	interval_s = interval;
}
