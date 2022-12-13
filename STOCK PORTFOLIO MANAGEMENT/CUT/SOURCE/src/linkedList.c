#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <struct.h>
#include <main.h>


void append(stock **headPointer, stock* data)// 
{
    stock* iter = *headPointer ;

    if ( *headPointer == NULL ) //No  element in the linkedlist 
        *headPointer = data ;
    else
    {
        while ( iter -> next != NULL)
            iter = iter -> next;
        iter -> next = data ;
    }
    data -> next = NULL ;
}


