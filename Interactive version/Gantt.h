#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef PROCESS_H
#define PROCESS_H
#include "Process.h"
#endif
#ifndef READY_QUEUE_H
#define READY_QUEUE _H
#include "ReadyQueue.h"
#endif
#ifndef VIRTUAL_CPU_H
#define VIRTUAL_CPU_H
#include "virtualCPU.h"
#endif
typedef struct Gantt{
    int numberOfProcesses;
    int totalTime;
    //Empty array of processes(Number 20 because of the total sum of time)
    Process *states;
    //Each individual process used
    Process *different_processes;
    //Waiting time of each process
    int *waiting_times;
    //Turn-around time of each process
    int *ta_times;
    //Number of changes each process has through each algorithm
    int *number_of_changes;
    //Name of algorithm used for print function later
    char algorithm_name[5];
    //Ready queues(each one represents ready queue at specific time)
    ReadyQueue *queues;
    //Virtual CPUs (each one for each process)
    virtualCPU *cpus;
}Gantt;
//Function to print Gantt chart
void print_Gantt(Gantt toPrint){
    //Print Time Units
    printf("Time:");
    int time;
    for(time=0;time<toPrint.totalTime+1;time++){
        if(time<=9) printf("%d    ",time);
        else printf("%d   ",time);
    }
    printf("\n");
    //Print algorithm's name
    printf("%s:|",toPrint.algorithm_name);
    //Print Gantt chart (times and processes)
    int y,k,z,e,t;
    for(y=0;y<toPrint.totalTime;y++){
        printf(" %s |",toPrint.states[y].name);
    }
    printf("\n");
    //Print ReadyQueues
    printf("\nReady Queue:\n");
    int o,l;
    for(o=0;o<toPrint.numberOfProcesses-1;o++){
        printf("|");
        for(l=0;l<toPrint.totalTime;l++){
            printf(" %s  | ",toPrint.queues[l].processes_waiting[o].name);
        }
        printf("\n");
    }
    //Print Virtual CPUS
    printf("\nVirtual CPUs:\n");
    int first,w;
    for(first=0;first<toPrint.numberOfProcesses;first++){
        printf("Virtual CPU %s: |",toPrint.different_processes[first].name);
        for(w=0;w<toPrint.totalTime;w++){
            printf("  %s  |",toPrint.cpus[first].processes[w].name);
        }
        printf("\n");
    }
    //Print first row with process's names
    printf("\n\n| Time |");
    for(k=0;k<toPrint.numberOfProcesses;k++){
        printf("  %s  |",toPrint.different_processes[k].name);
    }
    //Print second row containing waiting times
    printf("\n|  WT  |");
    for(z=0;z<toPrint.numberOfProcesses;z++){
        if(toPrint.waiting_times[z] > 9){
            printf("  %d  |",toPrint.waiting_times[z]);
        }
        else printf("  %d   |",toPrint.waiting_times[z]);
    }
    //Print third row containing turn-around times
    printf("\n|  TA  |");
    for(e=0;e<toPrint.numberOfProcesses;e++){
        //Check if time>9 to adjust boundaries for print
        if(toPrint.ta_times[e] > 9){
            printf("  %d  |",toPrint.ta_times[e]);
        }
        else printf("  %d   |",toPrint.ta_times[e]);
    }
    //Print fourth row containg number of changes
    printf("\n|  NC  |");
    for(t=0;t<toPrint.numberOfProcesses;t++){
        printf("  %d   |",toPrint.number_of_changes[t]);
    }
    printf("\n\n");
}
Gantt initGantt(Gantt toInit,int noProcesses,Process processes[]){
    //Setting number of processes to the number given by the user
    toInit.numberOfProcesses = noProcesses;
    //Malloc memory for array of times for all processes
    toInit.waiting_times = malloc(noProcesses*sizeof(int));
    memset(toInit.waiting_times,0,noProcesses);
    toInit.ta_times = malloc(noProcesses*sizeof(int));
    memset(toInit.ta_times,0,noProcesses);
    toInit.number_of_changes = malloc(noProcesses*sizeof(int));
    memset(toInit.number_of_changes,0,noProcesses);
    //Malloc memory for different processes
    toInit.different_processes = malloc(noProcesses*sizeof(Process));
    int r,y,t,x;
    toInit.totalTime = 0;
    for(t=0;t<noProcesses;t++){
        //Entering all different processes used
        toInit.different_processes[t] = processes[t];
        //Calculating total runtime of all processes
        toInit.totalTime = toInit.totalTime + processes[t].burst_time;
        //Initializing times to 0 (will be updated according to each algorithm)
        toInit.waiting_times[t] = 0;
        toInit.ta_times[t] = 0;
        toInit.number_of_changes[t] = 0;
    }
    //Malloc memory for virtual cpus,states of Gantt and ready queues of all time units
    toInit.cpus = malloc(noProcesses*sizeof(virtualCPU));
    toInit.queues = malloc(toInit.totalTime*sizeof(ReadyQueue));
    toInit.states = malloc(toInit.totalTime*sizeof(Process));
    //Initialize every state of Gantt to ::
    for(x=0;x<toInit.totalTime;x++){
        toInit.states[x].name = malloc(3*sizeof(char));
        strcpy(toInit.states[x].name,"::");
    }
    //Initialize virtual CPUs
    for(y=0;y<noProcesses;y++){
        toInit.cpus[y] = initVirtualCPU(toInit.cpus[y],toInit.totalTime);
    }
    //Initialize queues
    for(r=0;r<toInit.totalTime;r++){
        toInit.queues[r] = initializeQueue(toInit.queues[r],toInit.numberOfProcesses);
    }
    return toInit;
}
