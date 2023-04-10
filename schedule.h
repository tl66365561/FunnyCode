#pragma once

typedef struct {

	void (*fun)();   //函数指针
	unsigned short period; //周期
	unsigned short cnt;

} running_queue_def;



int create_task( void (*fun)(), unsigned short period);

int scheduler_run();



