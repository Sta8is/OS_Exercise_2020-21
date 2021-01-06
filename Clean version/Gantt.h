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
    Process different_processes[5];
    int waiting_times[5];
    int ta_times[5];
}Gantt;
void print_Gantt(Gantt toPrint){
    int y;
    for(y=0;y<20;y++){
        printf(" %s |",toPrint.states[y].name);
    }
    printf("\n| Time |");
    int k;
    for(k=0;k<5;k++){
        printf(" %s |",toPrint.different_processes[k].name);
    }
    printf("\n|  WT  |");
    int z;
    for(z=0;z<5;z++){
        printf(" %d  |",toPrint.waiting_times[z]);
    }
    printf("\n|  TA  |");
    int e;
    for(e=0;e<5;e++){
        printf(" %d  |",toPrint.ta_times[e]);
    }
}