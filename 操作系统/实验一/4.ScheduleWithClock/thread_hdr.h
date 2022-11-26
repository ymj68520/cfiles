// #pragma once
#include <cstdlib>
#include <cstdio>
#include <deque>

typedef struct _thread {
	unsigned int id;
	unsigned int clock_times;
} thread, * pthread;

extern thread idle_thread;

typedef std::deque<pthread> thread_queue;

extern thread_queue ready_queue;

extern thread_queue blocked_queue;

extern thread* current_thread;

void add_ready_thread(thread* ready_thread);
void schedule();
void current_thread_finished();
void current_thread_blocked();					// ��ǰ�̱߳�����ʱ����
void notify();									// �߳����������󱻵���
void notify_all();
void on_clock();								// ģ���ʱ���źź���
void set_time_ticks(unsigned int ticks);		// ����ʱ��Ƭ
void set_time_interval(unsigned int interval);	// ����ʱ���жϴ���һ�ζ�Ӧ��ʱ������