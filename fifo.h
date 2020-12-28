//#include "Process.h"
#include <stdio.h>
#include "Gantt.h"
typedef struct Process Process;
typedef struct Gantt Gantt;
Gantt* create_fifo(Process processes[5]){
    Gantt* fifo;
    Gantt* fifo2 = initGantt(fifo);
    int j;
    int count =0;
    for(j = 0;j<5;j++){
        Process process = processes[find_min_arrive_time(processes)];
        //printf("%s",process.name);
        int k; 
        for(k = 0;k<process.finish_time-process.arrive_time;k++){
            fifo = append(fifo2,process);
            free(fifo2);
        }
    }
    return fifo;
}
int find_min_arrive_time(Process lista[5]){
    int exclude[5] = {10,10,10,10,10};
    int min_index = 0;
    int count = 0;
    int i;
    for (i = 0; i < 5; i++)
    {
       if(i == exclude[0] || i == exclude[1] || i == exclude[2] || i == exclude[3] || i == exclude[4]) continue; 
       if(lista[i].arrive_time < min_index){
           min_index = i;
           exclude[count] = i;
           count++;
       }
    }
    return min_index;

}
