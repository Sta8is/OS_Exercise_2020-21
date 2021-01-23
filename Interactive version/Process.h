#include <stdio.h>
#include <string.h>
typedef struct Process
{
    char* name;
	int arrive_time;
    int burst_time;
    int priority;
}Process;
