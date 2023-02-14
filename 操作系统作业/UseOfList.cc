#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <list>
#include <atomic>
#include <linux/types.h>

// 双向循环链表使用list容器代替 插入时不考虑循环指针问题，容器动态分配
template <class T>
class MyList{
    // 数据存贮单元
    private: std::list<T> base;
    // 默认构造函数
    public: MyList(){base.clear();}
    // 初始化构造函数
    public: MyList(std::list<T> int_list){base.clear();base = int_list;}
    // 获取数据函数
    public: std::list<T> getData(){return base;}
    // 迭代器获取
    public: typename std::list<T>::const_iterator begin(){return base.begin();}
    public: typename std::list<T>::const_iterator end(){return base.end();}
    public: typename std::list<T>::const_iterator crbegin(){return base.crbegin();}
    public: typename std::list<T>::const_iterator crend(){return base.crend();}
    // 头插
    public: void push_front(T name){base.push_front(name);}
    // 尾插
    public: void push_back(T name){base.push_back(name);}
    // 擦除迭代器指向的元素
    public: T erase(typename std::list<T>::const_iterator it){T temp = *it;base.erase(it);return temp;}
    // 移动迭代器指向的元素到pos位置
    public: void move(typename std::list<T>::const_iterator it, int pos){
                // 重新计算pos
                int count=0;
                auto t = base.begin();
                for(;t!=it;t++) count++;
                pos = count>pos ? pos : pos-1;
                T temp = erase(it);
                t = base.begin();
                for(int i=0;i<pos;i++)  t++;
                base.insert(t,temp);
            }
    // 替换
    public: void replace(T name, int pos){base[pos] = name;}
    // 旋转操作使用crbegin()和crend()实现

    // 从pos位置分割列表
    public: void cutoff(std::list<T> &pre, std::list<T> &last, int pos){
        auto it = base.begin();
        for(int i=0;  i<pos        ;++i)  pre .push_back(*it++);
        for(int i=pos;i<base.size();++i)  last.push_back(*it++);
    }
    // 合并列表
    public: void merge(MyList another){base.merge(another.getData());}
};

class MyProgramInfo{
public:
    // 假设的标识符
    int id;
    // 假设的构造函数
    MyProgramInfo():id(-1){};
    MyProgramInfo(int _id):id(_id){};
    struct task_struct {
        //表示进程当前运行状态
        //volatile避免了读取缓存在寄存器中的脏数据，而是直接从内存中取
        //-1 不可运行  0 可运行的  >0 暂停状态
        volatile long state;	/* -1 unrunnable, 0 runnable, >0 stopped */

        struct thread_info *thread_info;
        std::atomic<bool> usage;
        //进程标记符 flags反映进程的状态信息，用于内核标识当前进程的状态
        unsigned long flags;	/* per process flags, defined below */
        unsigned long ptrace;

        int lock_depth;		/* Lock depth */

        // ...

        //mm进程所拥有的内存空间描述符，对于内核线程的mm为NULL
        //activi_mm进程运行时所使用的进程描述符
        struct mm_struct *mm, *active_mm;

    /* task state */
        struct linux_binfmt *binfmt;
        int exit_code, exit_signal;
        int pdeath_signal;  /*  The signal sent when the parent dies  */
        /* ??? */
        unsigned long personality;
        int did_exec:1;
        //进程的唯一标识
        pid_t pid;
        pid_t __pgrp;		/* Accessed via process_group() */
        pid_t tty_old_pgrp;
        pid_t session;
        //线程组标识符
        pid_t tgid;
        // ...
    };
    // 内存相关
    struct mm_struct{
        // somedefines
        // ...
    };
    // 虚存相关
    struct vm_area_struct{
        // somedefines
        // ...
    };
};

int main(){
    std::list<MyProgramInfo> preInfo{1,2,3};
    // 初始化进程管理链表
    MyList<MyProgramInfo> mL(preInfo);
    preInfo = mL.getData();
    // 输出进程序列的lamda函数
    auto print = [&](){
        std::cout<< "当前进程序列为：";
        for(const auto &x : preInfo)    std::cout << x.id << " ";
        std::cout << std::endl;
    };
    print();

    // 添加
    mL.push_front({4});
    mL.push_back({5});
    preInfo = mL.getData();
    print();

    // 删除
    mL.erase(mL.begin());
    preInfo = mL.getData();
    print();

    // 分割
    std::list<MyProgramInfo> t1,t2;
    mL.cutoff(t1,t2,1);
    preInfo = t1;print();
    preInfo = t2;print();

    return 0;
}