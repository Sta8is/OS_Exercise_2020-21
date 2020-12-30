#include <stdio.h>
#ifndef PROCESS_H
#define PROCESS_H
#include "Process.h"
#endif
//Bubble Sort
void bubble_sort(Process *lista[5]){
    Process *temp;
    int c,d;
    for (c = 0 ; c < 5 - 1; c++){
        for (d = 0 ; d < 5 - c - 1; d++){
            if (lista[d]->arrive_time > lista[d+1]->arrive_time){
                temp       = lista[d];
                lista[d]   = lista[d+1];
                lista[d+1] = temp;
            }
        }
    }
}
