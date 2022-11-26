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