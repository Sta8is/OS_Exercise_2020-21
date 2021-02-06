#include <stdio.h>
#ifndef PROCESS_H
#define PROCESS_H
#include "Process.h"
#endif
//Bubble Sort
void bubble_sort(Process lista[],int number)
{
    //VOID FUNCTION DOESNT RETURN ANYTHING, USE IT THEN REUSE THE ARRAY YOU WANT
    //Initialize empty struct(Process) temp
    Process temp;
    //Initialize variables for loops
    int c,d;
    for (c = 0 ; c < number - 1; c++)
    {
        for (d = 0 ; d < number - c - 1; d++)
        {
            if (lista[d].arrive_time > lista[d+1].arrive_time)
            {
                temp       = lista[d];
                lista[d]   = lista[d+1];
                lista[d+1] = temp;
            }
        }
    }
}
