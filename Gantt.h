#include <stdio.h>
#include "Process.h"
#include <stdlib.h>
typedef struct Gantt{
    char *diagram;
    //Process diagram[20];
    int pointer;
}Gantt;
Gantt* initGantt(Gantt* preFinal){
    preFinal->pointer = 0;
    /*Process start = {"S",0,0,0};
    for(int o = 0;o<20;o++){
        preFinal->diagram[o] = start;
    }*/
    preFinal->diagram = (char*)malloc(59*sizeof(char));
    return preFinal;
}
Gantt* append(Gantt* old,Process k){
    strcat(old->diagram,k.name);
    old->pointer++;
    return old;
}
void print_Gantt(Gantt* toPrint){
    printf("0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20\n");
    int i,l;
	for(i =0;i < 20;i++){
		printf("5");
        //Process currProcess = toPrint->diagram[i];
        /*for(l = 0;l<2;l++){
        	printf("%c",currProcess.name[l]);
		}*/
		//printf("%d",currProcess.arrive_time);
		//printf("%s",currProcess.name);
		//printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
        printf(" ");
    }
    printf("\n");
}
