#include <stdio.h>
#ifndef PROCESS_H
#define PROCESS_H
#include "Process.h"
#endif
typedef struct virtualCPU{
    Process *processes;
}virtualCPU;
virtualCPU initVirtualCPU(virtualCPU toInit,int totalTime)
{
    int i;
    toInit.processes = malloc(totalTime*sizeof(Process));
    for(i=0;i<totalTime;i++){
        toInit.processes[i].name = malloc(1*sizeof(char*));
        strcpy(toInit.processes[i].name,"N");
    }
    return toInit;
}
