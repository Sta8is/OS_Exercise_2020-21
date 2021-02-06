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
    //Sorting from smallest to highest arrival time
    bubble_sort(processes,numberOfProcesses);
    int k;
    //Array of arrive_times,burst_times,copy of burst_times and first_times of each process
    //First_times is array of value each process first entered CPU(updated to normal value later on programm)
    int arrive_times[numberOfProcesses],burst_times[numberOfProcesses],copyBurst[numberOfProcesses],first_times[numberOfProcesses];
    //Update values for arrays declared previously
    for(k=0;k<numberOfProcesses;k++){
        arrive_times[k] = processes[k].arrive_time;
        burst_times[k] = processes[k].burst_time;
        copyBurst[k] = burst_times[k];
        first_times[k] = -1;
    }
    int time,i,x,counter =0;
    //Set value of x to initial remaining number of processes
    x = numberOfProcesses;
    int previous = -1;
    for(time = 0, i = 0; x != 0;){
        //Initialize value of next for the next "i"
        int next= -1;
        //Case 1: process has remaining burst_time smaller or equal to time quantum
        if(burst_times[i] <= timeQuantum && burst_times[i] > 0){
            //Check first_times to see if process has entered CPU before
            if(first_times[i] < 0){
                //If not, set it to current time
                first_times[i] = time;
            }
            int k;
            //Variable to remove process only once(changed to 1 if current process is removed from queue)
            int change = 0;
            //Loop to repeat for remaining burst_time of process
            for(k=0;k<burst_times[i];k++){
                //Check time isn't zero
                if(time !=0){
                    int theta;
                    //Copying readyQueue from previous state
                    for(theta =0;theta<numberOfProcesses;theta++){
                        strcpy(temp.queues[time].processes_waiting[theta].name,temp.queues[time - 1].processes_waiting[theta].name);
                    }
                    //Remove current process(used)
                    temp.queues[time].lastIndex = temp.queues[time-1].lastIndex;
                    if(strcmp(temp.queues[time].processes_waiting[0].name,"::") != 0 && change == 0){
                        int dex;
                        for(dex=0;dex<numberOfProcesses-1;dex++){
                            strcpy(temp.queues[time].processes_waiting[dex].name,temp.queues[time].processes_waiting[dex+1].name);
                        }
                        strcpy(temp.queues[time].processes_waiting[numberOfProcesses-1].name,"::");
                        //Current process removed from queue => change updated
                        change = 1;
                        //Decrement lastIndex(index of last process in queue)
                        temp.queues[time].lastIndex--;
                    }
                }
                //Update virtualCPU and States of Gantt chart to current process
                strcpy(temp.cpus[i].processes[time].name,"U");
                strcpy(temp.states[time].name,processes[i].name);
                //Procedure for check of the rest processes
                int q;
                //Loop for all processes
                for(q=0;q<numberOfProcesses;q++){
                    //If a new process has arrived and it's the first time to appear then => the process is waiting and entered in the queue
                    if(arrive_times[q]<= time && q != i && burst_times[q] !=0 && first_times[q]<0){
                        strcpy(temp.cpus[q].processes[time].name,"W");
                        if(q != previous &&searchQueue(temp.queues[time],processes[q],numberOfProcesses) == 0 && time !=0){
                            strcpy(temp.queues[time].processes_waiting[temp.queues[time].lastIndex].name,processes[q].name);
                            //Increment lastIndex
                            temp.queues[time].lastIndex++;
                        }
                    }
                    //If a process has also arrived earlier but was used before is put as sleeping and entered also in queue
                    else if(arrive_times[q] <= time && q!=i && burst_times[q] !=0 && first_times[q] >= 0){
                        strcpy(temp.cpus[q].processes[time].name,"S");
                        if(q != previous &&searchQueue(temp.queues[time],processes[q],numberOfProcesses) == 0 && time !=0){
                            strcpy(temp.queues[time].processes_waiting[temp.queues[time].lastIndex].name,processes[q].name);
                            //Increment lastIndex
                            temp.queues[time].lastIndex++;
                        }
                    }
                    //The whole procedure is linear so the previous used process must be put last,
                    //if it's not complete yet. If a new process arrives later then that process is put last
                    if(previous >= 0 && previous != i && searchQueue(temp.queues[time],processes[previous],numberOfProcesses) == 0 && burst_times[previous] != 0){
                        strcpy(temp.queues[time].processes_waiting[temp.queues[time].lastIndex].name,processes[previous].name);
                        //Increment lastIndex
                        temp.queues[time].lastIndex++;
                    }

                }
                //Update the "previous" variable to our current i
                previous = i;
                //Increment our time
                time++;
            }
            //Current process is done => burst_time =  0 , flag = 1
            burst_times[i] = 0;
            counter = 1;
        }
        //Case 2: process has remaining burst_time > time Quantum and also zero(isn't finished)
        else if(burst_times[i] > 0){
            //Update value of remaing burst_time of current process
            burst_times[i] = burst_times[i] - timeQuantum;
            int u;
            //Update value of first_time if its the first time
            //the current process entered the CPU
            if(first_times[i] < 0){
                first_times[i] = time;
            }
            //As previously, variable "change" is used to determine if previous
            //process is removed (originally set to 0)
            int change = 0;
            for(u=0;u<timeQuantum;u++){
                //Update states and virtualCPU to using
                strcpy(temp.states[time].name,processes[i].name);
                strcpy(temp.cpus[i].processes[time].name,"U");
                int w;
                if(time !=0){
                    int theta;
                    //Copying readyQueue of previous state
                    for(theta =0;theta<numberOfProcesses;theta++){
                        strcpy(temp.queues[time].processes_waiting[theta].name,temp.queues[time - 1].processes_waiting[theta].name);
                    }
                    //Remove current process
                    temp.queues[time].lastIndex = temp.queues[time-1].lastIndex;
                    if(strcmp(temp.queues[time].processes_waiting[0].name,"::") != 0 && change ==0){
                        int dex;
                        for(dex=0;dex<numberOfProcesses-1;dex++){
                            strcpy(temp.queues[time].processes_waiting[dex].name,temp.queues[time].processes_waiting[dex+1].name);
                        }
                        //Update value of variable "change" as the previous process is
                        //now removed
                        change = 1;
                        strcpy(temp.queues[time].processes_waiting[numberOfProcesses-1].name,"::");
                        //Decrement last index
                        temp.queues[time].lastIndex--;
                    }
                }
                //Procedure to check for the rest of the processes
                for(w=0;w<numberOfProcesses;w++){
                    //If a process has arrived, isn't finished and hasn't entered the CPU previously
                    if(arrive_times[w]<= time && w!=i && burst_times[w] !=0 && first_times[w]<0){
                        //Update value of virtualCPU to W for waiting
                        strcpy(temp.cpus[w].processes[time].name,"W");
                        if(w != previous &&searchQueue(temp.queues[time],processes[w],numberOfProcesses) == 0 && time !=0){
                            //Add process to queue
                            strcpy(temp.queues[time].processes_waiting[temp.queues[time].lastIndex].name,processes[w].name);
                            //Increment lastIndex of queue
                            temp.queues[time].lastIndex++;
                        }
                    }
                    //If a process has arrived, isnt't finished and has entered the CPU previously
                    else if(arrive_times[w] <= time && w!=i && burst_times[w] !=0 &&first_times[w] >= 0){
                        //Update value of virtualCPU to W for waiting
                        strcpy(temp.cpus[w].processes[time].name,"S");
                        if(w != previous && searchQueue(temp.queues[time],processes[w],numberOfProcesses) == 0 && time !=0) {
                            //Add process to queue
                            strcpy(temp.queues[time].processes_waiting[temp.queues[time].lastIndex].name,processes[w].name);
                            //Increment lastIndex of queue
                            temp.queues[time].lastIndex++;
                        }
                    }
                    if(previous >= 0 && previous != i && searchQueue(temp.queues[time],processes[previous],numberOfProcesses) == 0 && burst_times[previous] != 0){
                        //Add process to queue
                        strcpy(temp.queues[time].processes_waiting[temp.queues[time].lastIndex].name,processes[previous].name);
                        //Increment value of lastIndex
                        temp.queues[time].lastIndex++;
                    }
                }
                //Update value of  variable "previous" to our current i
                previous = i;
                //Increment time by one
                time++;
            }
            //After process is done(not finished), increment number of changes of current process
            temp.number_of_changes[i]++;
        }
        //If a process is done
        if(burst_times[i] == 0 && counter == 1){
            //Decrement number of processes remaining for the algorithm to finish
            x--;
            //Calculate times of each process
            temp.waiting_times[i] = time - arrive_times[i] - copyBurst[i];
            temp.ta_times[i] = time - arrive_times[i];
            counter = 0;
        }
        //Find index of next process to be used
        int r;
        for(r=0;r<numberOfProcesses;r++){
            if(strcmp(processes[r].name,temp.queues[time-1].processes_waiting[0].name) == 0){
                next = r;
            }
        }
        //If next is >= 0 set i to next
        if(next>=0){
            i = next;
        }
        //Else continue algorithm with the previous process
        else i = previous;
    }
    //Return gantt chart
    return temp;
}
