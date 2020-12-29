#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Gantt{
    //Empty string for processes names
    char diagram[59];
}Gantt;
void print_Gantt(Gantt toPrint){
   printf("0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20\n");
   printf("\n");
   printf("%s",toPrint.diagram);
}
Gantt initGantt(Gantt old){
    int i;
    for(i=0;i<60;i++){
        strcat(old.diagram,"");
    }
}
