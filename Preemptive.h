#include <stdio.h>
#ifndef GANTT_H
#define GANTT_h
#include "Gantt.h"
#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "functions.h"
#endif
Gantt preEmptive(Process *listap[5]){
    Gantt tmp;
    //Initiliaze Gantt struct
    tmp = initGantt(tmp);
    int count = 0,time,smallest,i,end;
    int k;
    int arrive_times[5],burst_times[5],priorities[6];
    //Create array of arrive,burst times and priorities for each process
    for(k=0;k<5;k++){
        arrive_times[k] = listap[k]->arrive_time;
        burst_times[k] = listap[k]->finish_time;
        priorities[k] = listap[k]->priority;
    }
    //Setting lowest Priority
    priorities[5] = 0; 
    for(time=0; count<5; time++){
        smallest=5;
        for(i=0; i<5; i++){
            //Check for smallest arrive time and if it has higher priority. also check burst_time(finish_time) > 0 so the process isnt over yet
            if(arrive_times[i]<=time && priorities[i]>priorities[smallest] && burst_times[i]>0 )
                smallest=i;
        }
        burst_times[smallest]--;
       //Concatenate strings to gantt struct diagram
        strncat(tmp.diagram,listap[smallest]->name,2);
        //Add space between processes
        strcat(tmp.diagram," | ");
        if(burst_times[smallest]==0){
            count++;
            end=time+1;

            //ΥΠΟΛΟΓΙΣΜΟΙ ΧΡΟΝΩΝ(ΜΠΟΡΕΙ ΝΑ ΒΟΗΘΗΣΕΙ)
            /*completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
            */
        }   
    }
    tmp.diagram[99] = '\0';
    return tmp;
}