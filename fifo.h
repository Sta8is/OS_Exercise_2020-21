#include <stdio.h>
#ifndef GANTT_H
#define GANTT_H
#include "Gantt.h"
#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "functions.h"
#endif
//typedef struct Process Process;
//typedef struct Gantt Gantt;
Gantt create_fifo(Process *processes[5]){
    Gantt fifo;
    fifo = initGantt(fifo);
    //print_Gantt(fifo);
    int k,y,count = 0;
    //Bubble Sort for smaller arrive_time according to FIFO
    bubble_sort(processes);
    for(k=0;k<5;k++){
        Process *currProcess = processes[k];
        for(y=0;y<currProcess->finish_time;y++){
            //Add specified Process to each time unit
            strncat(fifo.diagram,currProcess->name,2);
            strcat(fifo.diagram," | ");
            count = count +5;
            //printf("%s \n",fifo.diagram);
        }
        //Free Memory
        free(currProcess);
    }
    fifo.diagram[count-1] = '\0';
    return fifo;
}

