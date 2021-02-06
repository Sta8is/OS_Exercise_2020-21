#include <stdio.h>
#ifndef GANTT_H
#define GANTT_h
#include "Gantt.h"
#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "functions.h"
#endif
Gantt preEmptive(Process processes[],int numberOfProcesses){
    Gantt tmp;
    //Initialize gantt chart
    tmp = initGantt(tmp,numberOfProcesses,processes);
    strcpy(tmp.algorithm_name,"preE");
    //Initialize all necessary variables for loops
    int count = 0,time,smallest,i,k,end,total_count=0;
    //Initialize arrays of arrive,burst times and priorities
    int arrive_times[numberOfProcesses],burst_times[numberOfProcesses],priorities[numberOfProcesses+1],first_times[numberOfProcesses],number_changes[numberOfProcesses];
    //Create array of arrive,burst times and priorities for each process
    for(k=0;k<numberOfProcesses;k++){
        arrive_times[k] = processes[k].arrive_time;
        burst_times[k] = processes[k].burst_time;
        priorities[k] = processes[k].priority;
        first_times[k] = -1;
    }
    //Setting lowest Priority
    priorities[numberOfProcesses] = 0;
    int previous = 5;
    for(time=0; count<numberOfProcesses; time++)
    {
        //Index of smallest priority in processes
        smallest=numberOfProcesses;
        for(i=0; i<numberOfProcesses; i++)
        {
            //Check for smallest arrive time and if it has higher priority. also check burst_time > 0 so the process isnt over yet
            if(arrive_times[i]<=time && priorities[i]>priorities[smallest] && burst_times[i]>0 ){
                smallest=i;
            }
        }
        if(first_times[smallest] <0) 
        {
            //Initialize first time process entered cpu and set number of changes to zero
            first_times[smallest] = time;
            number_changes[smallest] = 0;
        }
        //Copy to virtualCPU letter U for Using
        strcpy(tmp.cpus[smallest].processes[time].name,"U");
        int index = 0;
        for(k = 0;k<numberOfProcesses;k++){
            if(k !=smallest && arrive_times[k]<=time && burst_times[k] != 0 && first_times[k] < 0){
                strcpy(tmp.queues[time].processes_waiting[index].name,processes[k].name);
                tmp.queues[time].processes_waiting[index].priority = processes[k].priority;
                //Increment index
                index++;
                //Copy to virtualCPU letter W for Waiting
                strcpy(tmp.cpus[k].processes[time].name,"W");
            }
        }
        //If current process != previous increment number of changes for current process
        if(previous != smallest)
        {
            number_changes[smallest]++;
        }
        //If a process has arrived, isn't finished and has entered CPU before update to sleeping
        int u;
        for(u=0;u<numberOfProcesses;u++)
        {
            if (u != smallest && arrive_times[u] <= time && first_times[u] >= 0 && burst_times[u] != 0){
                strcpy(tmp.queues[time].processes_waiting[index].name,processes[u].name);
                tmp.queues[time].processes_waiting[index].priority = processes[u].priority;
                //Increment index
                index++;
                //Copy to virtualCPU letter S for Sleeping
                strcpy(tmp.cpus[u].processes[time].name,"S");
            }

        }
        //Decrease burst time of current process to be able to calculate if its done or not
        burst_times[smallest]--;
        //Set current process to that of smallest arrive time and highest priority
        strcpy(tmp.states[time].name,processes[smallest].name);
        //Sort queue to highest priority
        int c,d;
        for (c = 0 ; c < numberOfProcesses - 1; c++)
        {
            for (d = 0 ; d < numberOfProcesses - c - 1; d++)
            {
                //Empty temp character to store name
                char tempChar[3] = "";
                int tempPriority;
                //printf("Time:%d => %s -> %d | %s -> %d \n",time,tmp.queues[time].processes_waiting[d].name,tmp.queues[time].processes_waiting[d].priority,tmp.queues[time].processes_waiting[d+1].name,tmp.queues[time].processes_waiting[d+1].priority);
                if (tmp.queues[time].processes_waiting[d].priority <  tmp.queues[time].processes_waiting[d+1].priority){
                    //Swapping processes
                    tempPriority = tmp.queues[time].processes_waiting[d].priority;
                    tmp.queues[time].processes_waiting[d].priority = tmp.queues[time].processes_waiting[d+1].priority;
                    tmp.queues[time].processes_waiting[d+1].priority = tempPriority;
                    strcpy(tempChar,tmp.queues[time].processes_waiting[d].name);
                    strcpy(tmp.queues[time].processes_waiting[d].name,tmp.queues[time].processes_waiting[d+1].name);
                    strcpy(tmp.queues[time].processes_waiting[d+1].name,tempChar);
                }
            }
        }
        //Enter if, if a process is finished
        if(burst_times[smallest]==0)
        {
            //Increase count so that one process is done and move to find next one
            count++;
            end=time+1;
            //Calculate times of each process
            tmp.ta_times[smallest] = end - arrive_times[smallest];
            tmp.waiting_times[smallest] = tmp.ta_times[smallest] - processes[smallest].burst_time;
            tmp.number_of_changes[smallest] = number_changes[smallest] -1;
        }
        //Update previous process to keep number of process changes
        previous = smallest;
    }
    //Return struct(Gantt) tmp containing the full chart.
    return tmp;
}
