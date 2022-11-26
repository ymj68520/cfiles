#include "thread_hdr.h"
int interV=0,tick1=0,tick2=0;

void add_ready_thread(thread* ready_thread)
{
	// 相应的代码实现
    ready_thread->clock_times=0;
    ready_thread->max_clock_times = tick1;
    first_ready_queue.push_back(ready_thread);
}
void schedule(){
    if(first_ready_queue.size()){
        current_thread = first_ready_queue.front();
        first_ready_queue.pop_front();
    }
    else if(second_ready_queue.size()){
        current_thread = second_ready_queue.front();
        second_ready_queue.pop_front();
    }
    else{
        current_thread = &idle_thread;
    }
}

void current_thread_finished()
{
    // 相应的代码实现
    schedule();
}

void current_thread_blocked()
{
    // 相应的代码实现
    blocked_queue.push_back(current_thread);
    schedule();
}

void notify()
{
    // 相应的代码实现
    if(!blocked_queue.empty()){
        pthread t = blocked_queue.front();
        pthread temp = new thread;
        temp->id = t->id, temp->clock_times = 0, temp->max_clock_times = tick1;
        first_ready_queue.push_back(temp);
        blocked_queue.pop_front();
    }
}

void notify_all()
{
    // 相应的代码实现
    while(!blocked_queue.empty()){
        notify();
    }
}

void on_clock()
{
    // 相应的代码实现
    if(current_thread == &idle_thread){
        schedule();
    }
    else{
        current_thread->clock_times += interV;
        if(current_thread->clock_times >= current_thread->max_clock_times){
            current_thread->max_clock_times = tick2;
            current_thread->clock_times = 0;
            second_ready_queue.push_back(current_thread);
            schedule();
        }
        else if(current_thread->max_clock_times == tick2 && first_ready_queue.size()){
            second_ready_queue.push_back(current_thread);
            schedule();
        }
    }
}

void set_first_time_ticks(unsigned int ticks)
{
    // 相应的代码实现
    tick1 = ticks;
    return;
}

void set_second_time_ticks(unsigned int ticks)
{
    // 相应的代码实现
    tick2 = ticks;
    return;
}

void set_time_interval(unsigned int interval)
{
    // 相应的代码实现
    interV = interval;
    return;
}