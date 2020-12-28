#include <stdio.h>
#include "fifo.h"
int main(){
    Process P1 = {"P1",0,5,3};
    Process P2 = {"P2",1,6,5};
    Process P3 = {"P3",3,2,2};
    Process P4 = {"P4",9,4,1};
    Process P5 = {"P5",12,3,4};
    Process processes[5] = {P1,P2,P3,P4,P5};
    Gantt* fifo;
    fifo = create_fifo(processes);
    print_Gantt(fifo);
    printf("\n");
}
