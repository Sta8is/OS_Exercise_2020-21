#include <stdio.h>
#include <string.h>
typedef struct Process
{
    char name[2];
	int arrive_time;
    int finish_time;
    int priority;
}Process;
