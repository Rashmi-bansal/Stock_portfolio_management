#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>

#define STOCKNAME_LEN 30
#define NOOFSTOCKS 10

void  selectChoice(char* stockName)
{
	int choice;
	int returnValue = 0;
	char stocks[NOOFSTOCKS][STOCKNAME_LEN];
	char stocksLine[STOCKNAME_LEN];
	memset(stocks, 0, sizeof(stocks));
	memset(stocksLine, 0, sizeof(stocksLine));
	int i = 0;

	FILE* fp = fopen ("../data/stocks.ini", "r");
	if ( fp != NULL)
	{
		while (fgets (stocksLine, STOCKNAME_LEN,  fp) != NULL)
		{
			strncpy( stocks[i], stocksLine, STOCKNAME_LEN - 1);
			i++;
		}
		fclose(fp);
	}
	
	do 
	{
		system("clear");
		printf("\n====================================================\n    Welcome to Stock Portfolio Management Program\n====================================================\n\nPlease select the company name to stock\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++\n");

	    for ( int k = 1; k < NOOFSTOCKS; k++)
			printf ( "%d: %s\n", k, stocks[k]);
	
		printf("11. Exit\n+++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\tChoice: ");

		returnValue = scanf ("%d", &choice);
		if ( returnValue == 0 || returnValue ==  EOF)
		{
			fflush(stdin);
			printf("Invalid input. Please enter valid input\n");
			continue ; // break;
		}
	
		if (choice > 0 && choice < 11)
		{	
			printf("\n%s\n", stocks[choice]);
			strcpy(stockName, stocks[choice]);
			break;
		}

		else if ( choice == 11)
		{
			exit(0);
		}
		else 
		{	
			printf("Invalid Selection");
			break;
		}
			
	} while (1);

}
