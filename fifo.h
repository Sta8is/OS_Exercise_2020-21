//#include "Process.h"
#include <stdio.h>
#include "Gantt.h"
#include "functions.h"
typedef struct Process Process;
typedef struct Gantt Gantt;
Gantt create_fifo(Process *processes[5]){
    Gantt fifo;
    //fifo = initGantt(fifo);
    int k,y;
    //Bubble Sort for smaller arrive_time according to FIFO
    bubble_sort(processes);
    for(k=0;k<5;k++){
        Process *currProcess = processes[k];
        for(y=0;y<currProcess->finish_time;y++){
            //Add specified Process to each time unit
            strcat(fifo.diagram,currProcess->name);
            strcat(fifo.diagram," ");
        }
        //Free Memory
        free(currProcess);
    }
    return fifo;
}

