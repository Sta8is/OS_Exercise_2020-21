#include <stdio.h>
#ifndef GANTT_H
#define GANTT_H
#include "Gantt.h"
#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "functions.h"
#endif
Gantt create_fifo(Process processes[],int numberOfProcesses)
{
    //Initialize empty struct(Gantt) fifo
    Gantt fifo;
    fifo = initGantt(fifo,numberOfProcesses,processes);
    strcpy(fifo.algorithm_name,"FCFS");
    //Initialize variables for loops
    int k,y,count = 0;
    //Bubble Sort for smaller arrive_time according to FIFO
    bubble_sort(processes,numberOfProcesses);
    //Setting waiting time of first process to zero
    fifo.waiting_times[0] =0;
    //Setting completion time of first process to its burst_time
    int completion_time = processes[0].burst_time;
    //Setting turn-around time of first process to the previous set completion_time
    fifo.ta_times[0] = completion_time;
    //int time =0;
    for(k=0;k<numberOfProcesses;k++)
    {
        //Set currProcess to each process of the sorted array
        Process currProcess = processes[k];
        //Calculating number of changes for each process (in fifo all of them is 0)
        fifo.number_of_changes[k] = 0;
        //Calculation of specific times needed
        if(k != 0)
        {
            //Calculating waiting time based on previous process' completion time and subtracting arrive time of current process
            fifo.waiting_times[k] =  completion_time -processes[k].arrive_time;
            //Re-calculating completion time of current process
            completion_time = completion_time + processes[k].burst_time;
            //Calculating turn-around time based of current process' completion time
            fifo.ta_times[k] = completion_time - processes[k].arrive_time;
        }
        //For loop to complete gantt chart
        for(y=0;y<currProcess.burst_time;y++)
        {
            //Add specified Process to each time unit
            fifo.states[count] = currProcess;
            //Update value of virtualCPU to U for using
            strcpy(fifo.cpus[k].processes[count].name,"U");
            //Increment time unit
            int t;
            int index = 0;
            //Procedure for remaining processes
            for(t=k+1;t<numberOfProcesses;t++)
            {
                if(count >= processes[t].arrive_time)
                {
                    //Add process to queue
                    strcpy(fifo.queues[count].processes_waiting[index].name,processes[t].name);
                    //Increment index
                    index++;
                }

            }
            int z;
            //Procedure for rest processes
            for(z=k+1;z<numberOfProcesses;z++)
            {
                //Search queue for other processes
                if(searchQueue(fifo.queues[count],processes[z],numberOfProcesses) == 1)
                {
                    //Update value of virtualCPU to W for waiting
                    strcpy(fifo.cpus[z].processes[count].name,"W");
                }
            }
            count++;

        }

    }
    //Return struct(Gantt) fifo
    return fifo;
}

