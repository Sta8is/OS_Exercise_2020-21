#include <stdio.h>
#ifndef FIFO_H
#define FIFO_H
#include "fifo.h"
#endif
#ifndef PREEMPTIVE_H
#define PREEMPTIVE_H
#include "Preemptive.h"
#endif
int main(){
    //Initialize empty processes
    int numberOfProcesses;
    printf("Enter number of processes:");
    scanf("%d",&numberOfProcesses);
    int count;
    Process *arxiko;
    arxiko = malloc(numberOfProcesses*sizeof(Process));
    memset(arxiko,0,numberOfProcesses);
    for(count = 0; count<numberOfProcesses;count++){
        printf("\nEnter name of process:");
        int length;
        char name[3];
        scanf("%s",&name);
        length = sizeof(name)/sizeof(name[0]);
        arxiko[count].name = malloc(length*sizeof(char));
        strcpy(arxiko[count].name,name);
        printf("\nEnter arrive time of process:");
        scanf("%d",&arxiko[count].arrive_time);
        printf("\nEnter burst time of process:");
        scanf("%d",&arxiko[count].burst_time);
        printf("Enter priority of process:");
        scanf("%d",&arxiko[count].priority);
    }
    Gantt fifo;
    fifo = create_fifo(arxiko,numberOfProcesses);
    print_Gantt(fifo);
    Gantt preE;
    preE = preEmptive(arxiko,numberOfProcesses);
    print_Gantt(preE);
}
