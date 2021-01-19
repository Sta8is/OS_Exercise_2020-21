#include <stdio.h>
#ifndef PROCESS_H
#define PROCESS_H
#include "Process.h"
#endif
typedef struct virtualCPU{
    Process processes[20];
}virtualCPU;
virtualCPU initVirtualCPU(virtualCPU toInit){
    int i;
    for(i=0;i<20;i++){
        strcpy(toInit.processes[i].name,"N");
    }
    return toInit;
}