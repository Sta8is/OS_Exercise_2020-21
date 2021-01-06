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
    //Setting waiting time of first process to zero
    fifo.waiting_times[0] =0;
    //Setting completion time of first process to its burst_time
    int completion_time = processes[0].finish_time;
    //Setting turn-around time of first process to the previous set completion_time
    fifo.ta_times[0] = completion_time;
    for(k=0;k<5;k++){
        //Set currProcess to each process of the sorted array
        Process currProcess = processes[k];
        fifo.different_processes[k] = currProcess;
        if(k != 0){
            //Calculating waiting time based on previous process' completion time and subtracting arrive time of current process 
            fifo.waiting_times[k] =  completion_time -processes[k].arrive_time;
            //Re-calculating completion time of current process
            completion_time = completion_time + processes[k].finish_time;
            //Calculating turn-around time based of current process' completion time
            fifo.ta_times[k] = completion_time - processes[k].arrive_time;
        }
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

