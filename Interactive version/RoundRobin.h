#include <stdio.h>
#ifndef GANTT_H
#define GANTT_H
#include "Gantt.h"
#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "functions.h"
#endif
Gantt createRoundRobin(Process processes[],int numberOfProcesses,int timeQuantum){
    Gantt temp;
    //Initializing empty gantt chart
    temp = initGantt(temp,numberOfProcesses,processes);
    //Copying algorithm's name
    strcpy(temp.algorithm_name,"RoRo");
    //Sortinf from smallest to highest arrival time
    bubble_sort(processes,numberOfProcesses);
    int time;
    int k,count = 0;;
    int arrive_times[numberOfProcesses],burst_times[numberOfProcesses],priorities[numberOfProcesses];
    for(k=0;k<numberOfProcesses;k++){
        arrive_times[k] = processes[k].arrive_time;
        burst_times[k] = processes[k].burst_time;
        priorities[k] = processes[k].priority;
    }
    int y;
    int current;
    int total,i,x,counter =0;
    x = numberOfProcesses;
    for(total = 0, i = 0; x != 0;){
            if(burst_times[i] <= timeQuantum && burst_times[i] > 0){
                  int k;
                  for(k=0;k<burst_times[i];k++){
                    strcpy(temp.states[total].name,processes[i].name);
                    total = total+1;
                  }
                  burst_times[i] = 0;
                  counter = 1;
            }
            else if(burst_times[i] > 0){
                  burst_times[i] = burst_times[i] - timeQuantum;
                  int u;
                  for(u=0;u<timeQuantum;u++){
                    strcpy(temp.states[total].name,processes[i].name);
                    total = total + 1;
                  }
            }
            if(burst_times[i] == 0 && counter == 1){
                  x--;
                  //wait_time = wait_time + total - arrival_time[i] - burst_time[i];
                  //turnaround_time = turnaround_time + total - arrival_time[i];
                  counter = 0;
            }
            if(i == numberOfProcesses - 1){
                  i = 0;
            }
            else if(arrive_times[i + 1] <= total){
                  i++;
            }
            else{
                  i = 0;
            }
    }
    return temp;
}
