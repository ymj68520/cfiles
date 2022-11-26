#include "thread_hdr.h"

void add_ready_thread(thread* ready_thread)
{
	// ��Ӧ�Ĵ���ʵ��
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