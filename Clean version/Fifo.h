#include <stdio.h>
#ifndef GANTT_H
#define GANTT_H
#include "Gantt.h"
#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "functions.h"
#endif
Gantt create_fifo(Process processes[5]){
    //Initialize empty struct(Gantt) fifo
    Gantt fifo;
    //intialize variables for loops
    int k,y,count = 0;
    //Bubble Sort for smaller arrive_time according to FIFO
    bubble_sort(processes);
    for(k=0;k<5;k++){
        //Set currProcess to each process of the sorted array
        Process currProcess = processes[k];
        for(y=0;y<currProcess.finish_time;y++){
            //Add specified Process to each time unit
            fifo.states[count] = currProcess;
            //Increase time unit(Max:20 see Gantt)
            count = count +1;
        }
    }
    //Return struct(Gantt) fifo
    return fifo;
}

