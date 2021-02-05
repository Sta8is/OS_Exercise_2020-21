#include <stdio.h>
#ifndef GANTT_H
#define GANTT_H
#include "Gantt.h"
#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "functions.h"
#endif
Gantt create_srtf(Process processes[],int numberOfProcesses)
{   
    Gantt temp;
    //Initializing empty gantt chart for srtf algorithm
    temp = initGantt(temp,numberOfProcesses,processes);
    int k,i,end;
    int count = 0,total_count = 0;
    strcpy(temp.algorithm_name,"SRTF");
    //Sorting from smallest to highest arrival time
    bubble_sort(processes,numberOfProcesses);
    int time;
    int arrive_times[numberOfProcesses],burst_times[numberOfProcesses],priorities[numberOfProcesses],first_times[numberOfProcesses],number_changes[numberOfProcesses];
    for(k=0;k<numberOfProcesses;k++)
    {
        arrive_times[k] = processes[k].arrive_time;
        burst_times[k] = processes[k].burst_time;
        priorities[k] = processes[k].priority;
        first_times[k] = -1;
    }
    //temp process for the first condition
    burst_times[numberOfProcesses] = 9999;
    priorities[numberOfProcesses] = 0;
    int previous = 5;
    for(time=0; count<numberOfProcesses; time++)
    {   
        //index of priority with shortest remaining time
        int shortest = numberOfProcesses;
        for(i=0; i<numberOfProcesses; i++)
        {
            
            //Check for smallest arrive time and if it has shortest burst time. also check burst_time > 0 so the process isnt over yet
            if(arrive_times[i]<=time && burst_times[i]>0 )
            {   
                if(burst_times[i]<burst_times[shortest])
                {
                    shortest = i;
                    if(first_times[shortest] <0) 
                    {
                    //Initialize first time process entered cpu and set number of changes to zero
                    first_times[shortest] = time;
                    number_changes[shortest] = 0;
                    }
                }
                // if burst times are the same
                if(burst_times[i] == burst_times[shortest])
                {
                    if(priorities[i]>priorities[shortest])
                    shortest = i ;
                    if(first_times[shortest] <0) 
                    {
                    //Initialize first time process entered cpu and set number of changes to zero
                    first_times[shortest] = time;
                    number_changes[shortest] = 0;
                    }
                }

            }
        }
        //Copy to virtualCPU letter U for Using
        strcpy(temp.cpus[shortest].processes[time].name,"U");
        int index = 0;
        for(k = 0;k<numberOfProcesses;k++)
        {
            if(k !=shortest && arrive_times[k]<=time && burst_times[k] != 0){
                strcpy(temp.queues[time].processes_waiting[index].name, processes[k].name);
                index++;
                //Copy to virtualCPU letter W for Waiting
                strcpy(temp.cpus[k].processes[time].name,"W");
            }
        }
        //tmp.queues[time] = sortPriorityFirst(tmp.queues[time]);
        if(previous != shortest)
        {
            number_changes[shortest]++;
        }
        int u;
        for(u=0;u<numberOfProcesses;u++)
        {
            if (u != shortest && arrive_times[u] <= time && first_times[u] >= 0 && burst_times[u] != 0){
                strcpy(temp.cpus[u].processes[time].name,"S");
            }

        }

        //Decrease burst time of current process to be able to calculate if its done or not
        burst_times[shortest]--;
        //Set current process to that of shortest arrive time and shortest burst time
        strcpy(temp.states[time].name,processes[shortest].name);
        //Increase total_count to enter a new time value(Max:20 see Gantt struct)
        total_count++;
        if(burst_times[shortest]==0)
        {
        //Increase count so that one process is done and move to find nexxt one
        count++;
        end=time+1;
        temp.ta_times[shortest] = end - arrive_times[shortest];
        temp.waiting_times[shortest] = temp.ta_times[shortest] - processes[shortest].burst_time;
        temp.number_of_changes[shortest] = number_changes[shortest] -1;
        }
        //Update previous process to keep number of process changes
        previous = shortest;
    }
    //Return struct(Gantt) tmp containing the full chart.
    return temp;
}