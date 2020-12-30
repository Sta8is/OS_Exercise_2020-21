#include <stdio.h>
#ifndef GANTT_H
#define GANTT_h
#include "Gantt.h"
#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "functions.h"
#endif
Gantt create_preemptive(Process *processes[5]){
    Gantt preemptive;
    preemptive = initGantt(preemptive);
    print_Gantt(preemptive);
    bubble_sort(processes);
    int i,k,time=0;
    for(i = 0;i<5;i++){
        Process *currProcess = processes[i];
        Process *holdProcess;
        for(k = 0;k<currProcess->finish_time;k++){
            if(processes[i+1]->arrive_time == time && processes[i+1]->priority < processes[i]->priority ){
                currProcess = processes[i];
            }
            else{
                strncat(preemptive.diagram,currProcess->name,2);
            }
            
        }
    }
    return preemptive;
}
int exists(int times[],int search){
    int y;
    int size;
    size = sizeof(times[])/sizeof(times[0]);
    for(int y=0;y<size;y++){
        if(search == y){
            //Returns 1 if element exists in array
            return 1;
        }
        //Returns 0 if it doesn't
        else return 0;
    }
}
int produceTimeArray(Process o){
    int sizeOfArray = o.finish_time;
    int time[sizeOfArray];
    int k,start = o.arrive_time;
    for(k=0;k<o.finish_time;k++){
        time[k] = start;
        start++; 
    }
    return time;
}