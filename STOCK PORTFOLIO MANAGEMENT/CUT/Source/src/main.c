#include <stdio.h>
#include <stdlib.h>
#include <main.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char** argv)
{
	stock* st[MAXSTOCK];
	//char stockName[30];
	
    for(int i =0; i < MAXSTOCK ; i++)
        st[i] = NULL ;

    loadFromFile("../data/transaction.csv", &st[0]);

	//selectChoice(st);
	menu(st);
	
	return EXIT_SUCCESS;
}


