#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Gantt{
    //Empty string for processes names
    char diagram[100];
}Gantt;
void print_Gantt(Gantt toPrint){
   printf("%s",toPrint.diagram);
}
Gantt initGantt(Gantt old){
    old.diagram[0] = '\0';
    return old;
}
