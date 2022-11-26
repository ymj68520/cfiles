#include "thread_hdr.h"
int tick=0;
int interV=0;
void add_ready_thread(thread* ready_thread)
{
	// ��Ӧ�Ĵ���ʵ��
	ready_thread->clock_times = 0;
	ready_queue.push_back(ready_thread);
	return;
}

void schedule()
{
	// ��Ӧ�Ĵ���ʵ��
	// if(ready_queue.size() == 0) current_thread = &idle_thread;
	if(current_thread != &idle_thread)
		ready_queue.push_back(current_thread);
	current_thread = (ready_queue.size()==0) ? &idle_thread : ready_queue.front();
	ready_queue.pop_front();
	// current_thread =  ready_queue.front();
	// ready_queue.pop_front();
	return;
}

void current_thread_finished()
{
	// ʵ�ֵĴ���
	current_thread = &idle_thread;
	schedule();
	return;
}

void current_thread_blocked()
{
	// ��Ӧ�Ĵ���ʵ��
	if(current_thread != &idle_thread){
		blocked_queue.push_back(current_thread);
		current_thread = &idle_thread;
	}
	schedule();
	return;
}

void notify()
{
	// ��Ӧ�Ĵ���ʵ��
	if(!blocked_queue.empty()){
		ready_queue.push_back(blocked_queue.front());
		blocked_queue.pop_front();
	}
	return;
}

void notify_all()
{
	// ��Ӧ�Ĵ���ʵ��
	while(!blocked_queue.empty()){
		notify();
	}
	return;
}

void on_clock()
{
	// ��Ӧ�Ĵ���ʵ��
	if(current_thread == &idle_thread)
		schedule();
	else{
		current_thread->clock_times += interV;
		if(current_thread->clock_times >= tick){
			current_thread->clock_times=0;
			schedule();
		}
	}
}

void set_time_ticks(unsigned int ticks)
{
	// ��Ӧ�Ĵ���ʵ��
	tick = ticks;
	return;
}

void set_time_interval(unsigned int interval)
{
	// ��Ӧ�Ĵ���ʵ��
	interV = interval;
	return;
}