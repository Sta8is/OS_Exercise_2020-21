#include <stdio.h>
#ifndef FIFO_H
#define FIFO_H
#include "fifo.h"
#endif
#ifndef PREEMPTIVE_H
#define PREEMPTIVE_H
#include "Preemptive.h"
#endif
#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H
#include "RoundRobin.h"
#endif
#ifndef SRTF_H
#define SRTF_H
#include "srtf.h"
#endif // SRTF_H
int main()
{
    //Initialize empty processes
    int numberOfProcesses;
    printf("Enter number of processes:");
    scanf("%d",&numberOfProcesses);
    int count;
    Process *arxiko;
    arxiko = malloc(numberOfProcesses*sizeof(Process));
    memset(arxiko,0,numberOfProcesses);
    for(count = 0; count<numberOfProcesses;count++)
    {
        printf("Enter name of process:");
        int length;
        char name[3];
        scanf("%s",&name);
        length = sizeof(name)/sizeof(name[0]);
        arxiko[count].name = malloc(length*sizeof(char));
        strcpy(arxiko[count].name,name);
        printf("Enter arrive,burst time and priority of %s: ",arxiko[count].name);
        scanf("%d %d %d",&arxiko[count].arrive_time,&arxiko[count].burst_time,&arxiko[count].priority);
    }
    int timeQuantum;
    printf("Enter time quantum:");
    scanf("%d",&timeQuantum);
    Gantt fifo;
    fifo = create_fifo(arxiko,numberOfProcesses);
    print_Gantt(fifo);
    Gantt preE;
    preE = preEmptive(arxiko,numberOfProcesses);
    print_Gantt(preE);
    Gantt roro;
    roro = createRoundRobin(arxiko,numberOfProcesses,timeQuantum);
    print_Gantt(roro);
    Gantt SRTF;
    SRTF = create_srtf(arxiko,numberOfProcesses);
    print_Gantt(SRTF);
}
