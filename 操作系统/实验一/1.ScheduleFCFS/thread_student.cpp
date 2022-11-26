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
	if(current_thread != nullptr)
		ready_queue.push_back(current_thread);
	current_thread = ready_queue.front();
	ready_queue.pop_front();
	// current_thread =  ready_queue.front();
	// ready_queue.pop_front();
	return;
}
