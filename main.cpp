#include "schedule.h"
#include"windows.h"
#include <stdio.h>
#include<iostream>
#include<chrono>
#include<vector>
#include<iomanip>//格式控制
using namespace std;

//调度器

void task1()
{
    printf("task1 run\n");
}

void task2()
{
    printf("task2 run\n");
}

//ostream& operator<<(ostream& os, const chrono::time_point<chrono::system_clock>& t) 
//{
//
//   // const auto ltime(chrono::system_clock::to_time_t(t));
//   // const auto localTime(localTime(&ltime));
//   //return os << put_time(localTime, "%c");
//}




int main()   
{
 
    create_task(task1, 1);
    create_task(task2, 2);
    while (1)
    {
        scheduler_run();
        Sleep(1000);
    }

    return 0;
}