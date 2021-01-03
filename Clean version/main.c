#include <stdio.h>
#ifndef FIFO_H
#define FIFO_H
#include "fifo.h"
#endif
#ifndef PREEMPTIVE_H
#define PREEMPTIVE_H
#include "Preemptive.h"
#endif
int main(){
    //Initialize empty processes
    Process P1,P2,P3,P4,P5;
    //Intialize values for processes
    P1.arrive_time =0;
    P1.finish_time = 5;
    P1.priority = 3;
    strcpy(P1.name,"P1");
    P2.arrive_time =1;
    P2.finish_time = 6;
    P2.priority = 5;
    strcpy(P2.name,"P2");
    P3.arrive_time =3;
    P3.finish_time = 2;
    P3.priority = 2;
    strcpy(P3.name,"P3");
    P4.arrive_time =9;
    P4.finish_time = 4;
    P4.priority = 1;
    strcpy(P4.name,"P4");
    P5.arrive_time =12;
    P5.finish_time = 3;
    P5.priority = 4;
    strcpy(P5.name,"P5");
    
    Process processes[5] = {P1,P2,P3,P4,P5};
    printf("Time:0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20\n");
    printf("     |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |\n");
    Gantt fifo,preE;
    fifo = create_fifo(processes);
    printf("FCFS:|");
    print_Gantt(fifo);
    printf("\n");
    printf("PreE:|");
    preE = preEmptive(processes);
    print_Gantt(preE);
}
