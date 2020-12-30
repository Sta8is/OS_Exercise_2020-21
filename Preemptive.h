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
