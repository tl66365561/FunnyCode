//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//        头文件区
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>
#include "schedule.h"


/*调度器是常用的一种编程框架，也是操作系统的拆分多任务的核心，
比如单片机的裸机程序框架，网络协议栈的框架如can网关、485网关等等，使用场合比较多，是做稳定产品比较常用的编程技术

【原理】：超级循环+时间片分配
void main()
{
    while (1)
    {
        task1();
        task2();
        ...
    }
}*/




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//        接口定义区
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define MAX_TASKS 10
static volatile unsigned char cur_task_num = 0;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//        变量定义区
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static running_queue_def running_queue[MAX_TASKS] = { 0 };

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//        函数定义区
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int create_task( void (*fun)(), unsigned short period)
{
    //unsigned char i ;

    if (cur_task_num >= MAX_TASKS)
    {
        printf("over limit max_tasks\n");
        return -1;
    }
    running_queue[cur_task_num].fun = fun;
    running_queue[cur_task_num].period = period;
    running_queue[cur_task_num].cnt = 0;

    cur_task_num++;
    return 0;
}

int scheduler_run()
{
    unsigned char i;
    for (i = 0; i < cur_task_num; i++)
    {
        if (running_queue[i].cnt > 0)
        {
            running_queue[i].cnt--;
        }
        else
        {
            running_queue[i].cnt = running_queue[i].period;
            running_queue[i].fun();
        }
    }

    return 0;
}