#include <stdio.h>
#ifndef PROCESS_H
#define PROCESS_H
#include "Process.h"
#endif
//Struct of ReadyQueue
typedef struct ReadyQueue{
    int length;
    Process *processes_waiting;
    int lastIndex;
}ReadyQueue;
//Function to find index(position) of specific process in ready queue
int findIndex(Process toFind,Process processes[],int numberOfProcesses){
    int k;
    int index;
    for(k=0;k<numberOfProcesses;k++){
        if(strcmp(toFind.name, processes[k].name) == 0){
            index = k;
            break;
        }
    }
    return index;
}
//Function to initialize Queue
ReadyQueue initializeQueue(ReadyQueue toInit,int numberOfProcesses){
    int y;
    toInit.lastIndex = 0;
    toInit.processes_waiting = malloc(numberOfProcesses*sizeof(Process));
    for(y=0;y<numberOfProcesses;y++){
        //Set times and priority of each process inside queue to 0
        toInit.processes_waiting[y].arrive_time = 0;
        toInit.processes_waiting[y].burst_time = 0;
        toInit.processes_waiting[y].priority = 0;
        toInit.processes_waiting[y].name = malloc(2*sizeof(char));
        strcpy(toInit.processes_waiting[y].name,"::");
    }
    return toInit;
}
//Function to search queue for a specific process(1 true, 0 false)
int searchQueue(ReadyQueue toSearch,Process toFind,int numberOfProcesses){
    int t;
    //1 if true,0 if false
    int result;
    for(t= 0;t<numberOfProcesses;t++){
        //compare each member of queue to process given
        if(strcmp(toFind.name,toSearch.processes_waiting[t].name) == 0){
            result = 1;
            break;
        }
        else result = 0;
    }
    return result;
}

