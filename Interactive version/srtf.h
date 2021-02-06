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
    int arrive_times[numberOfProcesses],burst_times[numberOfProcesses+1],priorities[numberOfProcesses+1],first_times[numberOfProcesses],number_changes[numberOfProcesses];
    for(k=0;k<numberOfProcesses;k++)
    {
        arrive_times[k] = processes[k].arrive_time;
        burst_times[k] = processes[k].burst_time;
        priorities[k] = processes[k].priority;
        first_times[k] = -1;
    }
    //Τemp process for the first condition
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
            if(arrive_times[i]<=time && burst_times[i]>0)
            {
                //check if ne
                if(burst_times[i]<burst_times[shortest])
                {
                    shortest = i;
                }
                // if burst times are the same
                if(burst_times[i] == burst_times[shortest])
                {
                    if(priorities[i]>priorities[shortest])
                    shortest = i ;
                }
            }
        }
        if(first_times[shortest] <0)
        {
        //Initialize first time process entered cpu and set number of changes to zero
        first_times[shortest] = time;
        number_changes[shortest] = 0;
        }
        //Copy to virtualCPU letter U for Using
        strcpy(temp.cpus[shortest].processes[time].name,"U");
        int index = 0;
        for(k = 0;k<numberOfProcesses;k++)
        {
            if(k !=shortest && arrive_times[k]<=time && burst_times[k] != 0){
                //Add to queue "waiting" process and its remaining burst_time(Later used in sorting)
                if(searchQueue(temp.queues[time],processes[k],numberOfProcesses) == 0){
                    strcpy(temp.queues[time].processes_waiting[index].name, processes[k].name);
                    temp.queues[time].processes_waiting[index].burst_time = burst_times[k];
                    //Increment index of current time unit
                    index++;
                }
                //Copying letter "W" for waiting in virtualCPU
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
            if (u != shortest && arrive_times[u] <= time && first_times[u] >= 0 && burst_times[u] != 0)
            {
                //Add to queue "sleeping" process and its remaining burst_time(Later used in sorting)
                if(searchQueue(temp.queues[time],processes[u],numberOfProcesses) == 0){
                    strcpy(temp.queues[time].processes_waiting[index].name, processes[u].name);
                    temp.queues[time].processes_waiting[index].burst_time = burst_times[u];
                    //Increment index of current time unit
                    index++;
                }
                //Copying letter "S" for sleeping in virtualCPU
                strcpy(temp.cpus[u].processes[time].name,"S");
            }

        }
        //Bubble sort based on smallest burst time
        int c,d;
        for (c = 0 ; c < numberOfProcesses - 1; c++)
        {
            for (d = 0 ; d < numberOfProcesses - c - 1; d++)
            {
                if(temp.queues[time].processes_waiting[d].burst_time != 0 && temp.queues[time].processes_waiting[d+1].burst_time != 0){
                    //Empty temp character to store name
                    char tempChar[3] = "";
                    int tempBurst;
                    if (temp.queues[time].processes_waiting[d].burst_time > temp.queues[time].processes_waiting[d+1].burst_time)
                    {
                        //Swapping processes
                        tempBurst = temp.queues[time].processes_waiting[d].burst_time;
                        temp.queues[time].processes_waiting[d].burst_time = temp.queues[time].processes_waiting[d+1].burst_time;
                        temp.queues[time].processes_waiting[d+1].burst_time = tempBurst;
                        strcpy(tempChar,temp.queues[time].processes_waiting[d].name);
                        strcpy(temp.queues[time].processes_waiting[d].name,temp.queues[time].processes_waiting[d+1].name);
                        strcpy(temp.queues[time].processes_waiting[d+1].name,tempChar);
                    }
                }
            }
        }
        //Decrease burst time of current process to be able to calculate if its done or not
        burst_times[shortest]--;
        //Set current process to that of shortest arrive time and shortest burst time
        strcpy(temp.states[time].name, processes[shortest].name);
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
     //Initializing sums
    float sum = 0,sum2=0;
    int r;
    //Calculate sum of waiting_times and ta_times
    for(r=0;r<numberOfProcesses;r++){
        sum = sum + temp.waiting_times[r];
        sum2 = sum2 + temp.ta_times[r];
    }
    //Divide with number of processes
    temp.avg_ta_time = sum2/numberOfProcesses;
    temp.avg_waiting_time = sum/numberOfProcesses;
    //Return struct(Gantt) tmp containing the full chart.
    return temp;
}
