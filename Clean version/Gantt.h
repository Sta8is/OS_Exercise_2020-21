#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef PROCESS_H
#define PROCESS_H
#include "Process.h"
#endif
typedef struct Gantt{
    //Empty array of processes(Number 20 because of the total sum of time)
    Process states[20];
}Gantt;
void print_Gantt(Gantt toPrint){
    int y;
    for(y=0;y<20;y++){
        printf(" %s |",toPrint.states[y].name);
    }
}