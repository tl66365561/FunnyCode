#pragma once

typedef struct {

	void (*fun)();   //����ָ��
	unsigned short period; //����
	unsigned short cnt;

} running_queue_def;



int create_task( void (*fun)(), unsigned short period);

int scheduler_run();



