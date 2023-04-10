//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//        ͷ�ļ���
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>
#include "schedule.h"


/*�������ǳ��õ�һ�ֱ�̿�ܣ�Ҳ�ǲ���ϵͳ�Ĳ�ֶ�����ĺ��ģ�
���絥Ƭ������������ܣ�����Э��ջ�Ŀ����can���ء�485���صȵȣ�ʹ�ó��ϱȽ϶࣬�����ȶ���Ʒ�Ƚϳ��õı�̼���

��ԭ��������ѭ��+ʱ��Ƭ����
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
//        �ӿڶ�����
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define MAX_TASKS 10
static volatile unsigned char cur_task_num = 0;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//        ����������
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static running_queue_def running_queue[MAX_TASKS] = { 0 };

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//        ����������
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