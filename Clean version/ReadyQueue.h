#include <stdio.h>
#ifndef PROCESS_H
#define PROCESS_H
#include "Process.h"
#endif
typedef struct ReadyQueue{
    int length;
    Process processes_waiting[5];
    int lastIndex;
}ReadyQueue;
void printReadyQueue(ReadyQueue toPrint){
    int i;
    for(i = 0 ; i <5;i++){
        printf("%s | ",toPrint.processes_waiting[i].arrive_time);
    }
}
int findIndex(Process toFind,ReadyQueue queueToSearch){
    int k;
    int index;
    for(k=0;k<5;k++){
        if(toFind.name == queueToSearch.processes_waiting[k].name){
            index = k;
        }
    }
}
void swapProcesses(Process a,Process b,ReadyQueue queue){
    int indexOfB;
    indexOfB = findIndex(b,queue);
    queue.processes_waiting[indexOfB] = a;
}
ReadyQueue addProcessToQueueFifo(Process toAdd,ReadyQueue queueToBeAdded){
    strcpy(queueToBeAdded.processes_waiting[queueToBeAdded.lastIndex].name, toAdd.name);
    queueToBeAdded.lastIndex++;
    return queueToBeAdded;
}
ReadyQueue initializeQueue(ReadyQueue toInit){
    int y;
    toInit.lastIndex = 0;
    for(y=0;y<5;y++){
        toInit.processes_waiting[y].arrive_time = 0;
        toInit.processes_waiting[y].burst_time = 0;
        toInit.processes_waiting[y].priority = 0;
        strcpy(toInit.processes_waiting[y].name,"::");
    }
    return toInit;
}
int searchQueue(ReadyQueue toSearch,Process toFind){
    int t;
    //1 if true,0 if false
    int result;
    for(t= 0;t<5;t++){
        if(toFind.name == toSearch.processes_waiting[t].name){
            result = 1;
            break;
        }
        else result = 0;
    }
    return result;
}
ReadyQueue removeProcessFromReadyQueue(ReadyQueue toRemoveFrom){
    int k;
    for(k=0;k<4;k++){
        strcpy(toRemoveFrom.processes_waiting[k].name,toRemoveFrom.processes_waiting[k+1].name);
    }
    strcpy(toRemoveFrom.processes_waiting[4].name,"::");
    toRemoveFrom.lastIndex--;
    return toRemoveFrom;
}