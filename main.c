#include <stdio.h>
#include "fifo.h"
int main(){
    Process *P1_p,*P2_p,*P3_p,*P4_p,*P5_p;
    Process P1,P2,P3,P4,P5;
    P1_p = &P1;
    P2_p = &P2;
    P3_p = &P3;
    P4_p = &P4;
    P5_p = &P5;
    strcpy(P1_p->name,"P1");
    P1_p->arrive_time = 0;
    P1_p->finish_time = 5;
    P1_p->priority = 3;
    strcpy(P2_p->name,"P2");
    P2_p->arrive_time = 1;
    P2_p->finish_time = 6;
    P2_p->priority = 5;
    strcpy(P3_p->name,"P3");
    P3_p->arrive_time = 3;
    P3_p->finish_time = 2;
    P3_p->priority = 2;
    strcpy(P4_p->name,"P4");
    P4_p->arrive_time = 9;
    P4_p->finish_time = 4;
    P4_p->priority = 1;
    strcpy(P5_p->name,"P5");
    P5_p->arrive_time = 12;
    P5_p->finish_time = 3;
    P5_p->priority = 4;
    Process *processes[5] = {P1_p,P2_p,P3_p,P4_p,P5_p};
    Gantt fifo;
    fifo = create_fifo(processes);
    free(P1_p);
    free(P2_p);
    free(P3_p);
    free(P4_p);
    free(P5_p);
    print_Gantt(fifo);
    printf("\n");
}
