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
    return index;
}
void swapProcesses(Process a,Process b){
    char temp[3]="";
    strcpy(temp,a.name);
    strcpy(a.name,b.name);
    strcpy(b.name,temp);
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
        if(strcmp(toFind.name,toSearch.processes_waiting[t].name) == 0){
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
ReadyQueue sortPriorityFirst(ReadyQueue toSort){
    int c,d;
    for (c = 0 ; c < 5 - 1; c++){
        for (d = 0 ; d < 5 - c - 1; d++){
            if (toSort.processes_waiting[d].priority > toSort.processes_waiting[d+1].priority){
                swapProcesses(toSort.processes_waiting[d],toSort.processes_waiting[d+1]);
                /*strcpy(temp,)
                lista[d]   = lista[d+1];
                lista[d+1] = temp;*/
            }
        }
    }
    return toSort;
    
}