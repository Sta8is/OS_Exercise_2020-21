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
    strcpy(fifo.algorithm_name,"FCFS");
    //intialize variables for loops
    int k,y,count = 0;
    //Bubble Sort for smaller arrive_time according to FIFO
    bubble_sort(processes);
    //Setting waiting time of first process to zero
    fifo.waiting_times[0] =0;
    //Setting completion time of first process to its burst_time
    int completion_time = processes[0].burst_time;
    //Setting turn-around time of first process to the previous set completion_time
    fifo.ta_times[0] = completion_time;
    for(k=0;k<5;k++){
        //Set currProcess to each process of the sorted array
        Process currProcess = processes[k];
        //FIll out array with all the different processes used
        fifo.different_processes[k] = currProcess;
        //Calculating number of changes for each process (in fifo all of theme is 0)
        fifo.number_of_changes[k] = 0;
        //Calculation of specific times needed
        if(k != 0){
            //Calculating waiting time based on previous process' completion time and subtracting arrive time of current process 
            fifo.waiting_times[k] =  completion_time -processes[k].arrive_time;
            //Re-calculating completion time of current process
            completion_time = completion_time + processes[k].burst_time;
            //Calculating turn-around time based of current process' completion time
            fifo.ta_times[k] = completion_time - processes[k].arrive_time;
        }
        //Calculating response time (same with waiting time in fifo)
        fifo.response_times[k] = fifo.waiting_times[k];
        //For loop to complete gantt chart
        for(y=0;y<currProcess.burst_time;y++){
            //Add specified Process to each time unit
            fifo.states[count] = currProcess;
            //Increase time unit(Max:20 see Gantt)
            count = count +1;
        }
    }
    //Return struct(Gantt) fifo
    return fifo;
}

