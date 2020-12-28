//#include "Process.h"
#include <stdio.h>
#include "Gantt.h"
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
//Bubble Sort
void bubble_sort(Process *lista[5]){
    Process *temp;
    int c,d;
    for (c = 0 ; c < 5 - 1; c++){
        for (d = 0 ; d < 5 - c - 1; d++){
            if (lista[d]->arrive_time > lista[d+1]->arrive_time){
                temp       = lista[d];
                lista[d]   = lista[d+1];
                lista[d+1] = temp;
            }
        }
    }
}
