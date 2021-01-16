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
typedef struct Gantt{
    //Empty array of processes(Number 20 because of the total sum of time)
    Process states[20];
    //Each individual process used
    Process different_processes[5];
    //Waiting time of each process
    int waiting_times[5];
    //Turn-around time of each process
    int ta_times[5];
    //Number of changes each process has through each algorithm
    int number_of_changes[5];
    //Response time of each process
    int response_times[5];
    //Name of algorithm used for print function later
    char algorithm_name[5];
    ReadyQueue queues[20];
}Gantt;
void print_Gantt(Gantt toPrint){
    printf("Time:0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20\n");
    //printf("     |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |\n");
    //Print algorithm's name
    printf("%s:|",toPrint.algorithm_name);
    //Print Gantt chart (times and processes)
    int y,k,z,e,t,u;
    for(y=0;y<20;y++){
        printf(" %s |",toPrint.states[y].name);
    }
    printf("\n");
    //Print ReadyQueues
    printf("\nReady Queue:\n");
    int o,l;
    for(o=0;o<5;o++){
        printf("|");
        for(l=0;l<20;l++){
            //if(strcmp(toPrint.queues[l].processes_waiting[o].name,"-")!=0){
            printf(" %s  | ",toPrint.queues[l].processes_waiting[o].name);
            //}
            //else{
            //    printf("  -  |");
           // }
        }
        printf("\n");
    }
    //Print first row with process's names
    printf("\n\n| Time |");
    for(k=0;k<5;k++){
        printf("  %s  |",toPrint.different_processes[k].name);
    }
    //Print second row containing waiting times
    printf("\n|  WT  |");
    for(z=0;z<5;z++){
        if(toPrint.waiting_times[z] > 9){
            printf("  %d  |",toPrint.waiting_times[z]);
        }
        else printf("  %d   |",toPrint.waiting_times[z]);
    }
    //Print third row containing turn-around times
    printf("\n|  TA  |");
    for(e=0;e<5;e++){
        //Check if time>9 to adjust boundaries for print
        if(toPrint.ta_times[e] > 9){
            printf("  %d  |",toPrint.ta_times[e]);
        }
        else printf("  %d   |",toPrint.ta_times[e]);    
    }
    //Print fourth row containing response times
    printf("\n|  RT  |");
    for(u=0;u<5;u++){
        printf("  %d   |",toPrint.response_times[u]);
    }
    //Print fifth row containg number of changes
    printf("\n|  NC  |");
    for(t=0;t<5;t++){
        printf("  %d   |",toPrint.number_of_changes[t]);
    }
    printf("\n\n");
   
}
Gantt initGantt(Gantt toInit){
    int r;
    for(r=0;r<20;r++){
        toInit.queues[r] = initializeQueue(toInit.queues[r]);
    }
    return toInit;
}