#include <stdio.h>
#ifndef GANTT_H
#define GANTT_h
#include "Gantt.h"
#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "functions.h"
#endif
Gantt preEmptive(Process listap[5]){
    Gantt tmp;
    //Initalize all necessary variables for loops
    int count = 0,time,smallest,i,k,end,total_count=0;
    //Initalize arrays of arrive,burst times and priorities
    int arrive_times[5],burst_times[5],priorities[6];
    //Create array of arrive,burst times and priorities for each process
    for(k=0;k<5;k++){
        arrive_times[k] = listap[k].arrive_time;
        burst_times[k] = listap[k].finish_time;
        priorities[k] = listap[k].priority;
    }
    //Setting lowest Priority
    priorities[5] = 0; 
    for(time=0; count<5; time++){
        //Index of smallest priority in processes
        smallest=5;
        for(i=0; i<5; i++){
            //Check for smallest arrive time and if it has higher priority. also check burst_time(finish_time) > 0 so the process isnt over yet
            if(arrive_times[i]<=time && priorities[i]>priorities[smallest] && burst_times[i]>0 )
                smallest=i;
        }
        //Decrease burst time of current process to be able to calculate if its done or not
        burst_times[smallest]--;
        //Set current process to that of smallest arrive time and highest priority
        tmp.states[total_count] = listap[smallest];
        //Increase total_count to enter a new time value(Max:20 see Gantt struct)
        total_count++;
        if(burst_times[smallest]==0){
            //Increase count so that one process is done and move to find nexxt one
            count++;
            end=time+1;

            //ΥΠΟΛΟΓΙΣΜΟΙ ΧΡΟΝΩΝ(ΜΠΟΡΕΙ ΝΑ ΒΟΗΘΗΣΕΙ)
            /*completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
            */
        }   
    }
    //Return struct(Gantt) tmp containing the full chart.
    return tmp;
}