#include "thread_hdr.h"

pthread temp;//就绪队列中间变量 队头
pthread tempBlock;//阻塞队列中间变量 队头
int flag = 0;//判断线程能否重新进入就绪队列
int flag2 = 0;
int flagOnClock = 0;//为时间调度on_click先执行一次schedule()
int flagFirst = 1;//0执行second_ready_queue 1执行first_ready_queue
unsigned int ticks_f;
unsigned int ticks_s;
unsigned int interval_s;//时间间隔
void add_ready_thread(thread* ready_thread)
{
	// 相应的代码实现
	//入队
	ready_thread->clock_times = 0;
	ready_thread->max_clock_times = ticks_f;
	first_ready_queue.push_back(ready_thread);
}
void scheduleSecond() {
	if (flag2 == 1) {
		temp->max_clock_times = ticks_s;
		second_ready_queue.push_back(temp);
	}
	if (second_ready_queue.size() == 0) {
		if (first_ready_queue.size() == 0) {
			current_thread = &idle_thread;
		}
	}
	temp = second_ready_queue.front();
	current_thread = temp;
	second_ready_queue.pop_front();
	flag2 = 1;
}
void schedule()
{
	//实验二注意当就绪队列有一个线程的情况，也会出现ready_queue.size()==0
	if (flag == 1) {
		//实验一中线程不会结束
		add_ready_thread(temp);
	}
	if (first_ready_queue.size() == 0) {
		//current_thread = &idle_thread;
		flagOnClock = 0;
		flag = 0;
		flagFirst = 0;
		scheduleSecond();
	}
	else
	{
		//句子1
		//current_thread->clock_times = 0;
		// 相应的代码实现
		temp = first_ready_queue.front();
		current_thread = temp;
		//出队，控制ready_queue.size()大小
		first_ready_queue.pop_front();
		flag = 1;
		flagFirst = 1;
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
	int length = blocked_queue.size();
	for (int i = 0; i < length; i++) {
		tempBlock = blocked_queue.front();
		blocked_queue.pop_front();
		add_ready_thread(tempBlock);
	}
	if (flagFirst == 0) {
		flagOnClock = 0;
		second_ready_queue.push_back(current_thread);
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
	/*int time;
	if (flagFirst == 1) {
		time = ticks_f;
	}
	else {
		time = ticks_s;
	}*/
	if (current_thread->clock_times > current_thread->max_clock_times) {
		if (current_thread->max_clock_times == ticks_f) {
			flag = 0;
			second_ready_queue.push_back(temp);
			schedule();
		}
		else {
			schedule();
		}
	}
}

void set_time_interval(unsigned int interval)
{
	// 相应的代码实现
	interval_s = interval;
}

void set_first_time_ticks(unsigned int ticks)
{
    // 相应的代码实现
	ticks_f = ticks;
}

void set_second_time_ticks(unsigned int ticks)
{
    // 相应的代码实现
	ticks_s = ticks;
}
