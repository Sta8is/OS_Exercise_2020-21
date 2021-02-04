#include <stdio.h>
#ifndef GANTT_H
#define GANTT_h
#include "Gantt.h"
#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "functions.h"
#endif
Gantt preEmptive(Process listap[],int numberOfProcesses){
    Gantt tmp;
    //Initialize gantt chart
    tmp = initGantt(tmp,numberOfProcesses,listap);
    strcpy(tmp.algorithm_name,"preE");
    //Initalize all necessary variables for loops
    int count = 0,time,smallest,i,k,end,total_count=0;
    //Initalize arrays of arrive,burst times and priorities
    int arrive_times[numberOfProcesses],burst_times[numberOfProcesses],priorities[numberOfProcesses+1],first_times[numberOfProcesses],number_changes[numberOfProcesses];
    //Create array of arrive,burst times and priorities for each process
    for(k=0;k<numberOfProcesses;k++){
        arrive_times[k] = listap[k].arrive_time;
        burst_times[k] = listap[k].burst_time;
        priorities[k] = listap[k].priority;
        first_times[k] = -1;
    }
    //Setting lowest Priority
    priorities[numberOfProcesses] = 0;
    int previous = 5;
    for(time=0; count<numberOfProcesses; time++){
        //Index of smallest priority in processes
        smallest=numberOfProcesses;
        for(i=0; i<numberOfProcesses; i++){
            //Check for smallest arrive time and if it has higher priority. also check burst_time > 0 so the process isnt over yet
            if(arrive_times[i]<=time && priorities[i]>priorities[smallest] && burst_times[i]>0 ){
                smallest=i;
                if(first_times[i] <0) {
                    //Initialize first time process entered cpu and set number of changes to zero
                    first_times[i] = time;
                    number_changes[i] = 0;
                }
            }
        }
        //Copy to virtualCPU letter U for Using
        strcpy(tmp.cpus[smallest].processes[time].name,"U");
        int index = 0;
        for(k = 0;k<numberOfProcesses;k++){
            if(k !=smallest && arrive_times[k]<=time && burst_times[k] != 0){
                strcpy(tmp.queues[time].processes_waiting[index].name,listap[k].name);
                index++;
                //Copy to virtualCPU letter W for Waiting
                strcpy(tmp.cpus[k].processes[time].name,"W");
            }
        }
        //tmp.queues[time] = sortPriorityFirst(tmp.queues[time]);
        if(previous != smallest){
            number_changes[smallest]++;
        }
        int u;
        for(u=0;u<numberOfProcesses;u++){
            if (u != smallest && arrive_times[u] <= time && first_times[u] >= 0 && burst_times[u] != 0){
                strcpy(tmp.cpus[u].processes[time].name,"S");
            }

        }
        //Decrease burst time of current process to be able to calculate if its done or not
        burst_times[smallest]--;
        //Set current process to that of smallest arrive time and highest priority
        strcpy(tmp.states[time].name,listap[smallest].name);
        //Increase total_count to enter a new time value(Max:20 see Gantt struct)
        total_count++;
        if(burst_times[smallest]==0){
            //Increase count so that one process is done and move to find nexxt one
            count++;
            end=time+1;
            tmp.ta_times[smallest] = end - arrive_times[smallest];
            tmp.waiting_times[smallest] = tmp.ta_times[smallest] - listap[smallest].burst_time;
            tmp.number_of_changes[smallest] = number_changes[smallest] -1;
        }
        //Update previous process to keep number of process changes
        previous = smallest;
    }
    //Return struct(Gantt) tmp containing the full chart.
    return tmp;
}
