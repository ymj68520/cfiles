#pragma once
#include <cstdlib>
#include <cstdio>
#include <deque>

typedef struct _thread {
	unsigned int id;
	unsigned int clock_times;
	unsigned int max_clock_times;
}thread, *pthread;

extern thread idle_thread;

typedef std::deque<thread*> thread_queue;

extern thread_queue first_ready_queue;

extern thread_queue second_ready_queue;

extern thread_queue blocked_queue;

extern thread* current_thread;

void add_ready_thread(thread* ready_thread);
void current_thread_finished();
void current_thread_blocked();					// ��ǰ�̱߳�����ʱ����
void notify();									// �߳����������󱻵���
void notify_all();
void on_clock();								// ģ���ʱ���źź���
void set_first_time_ticks(unsigned int ticks);		// ���õ�һ��Ready��������ҵ���ʱ��Ƭ
void set_second_time_ticks(unsigned int ticks);		// ���õڶ���Ready��������ҵ���ʱ��Ƭ
void set_time_interval(unsigned int interval);	// ����ʱ���жϴ���һ�ζ�Ӧ��ʱ������