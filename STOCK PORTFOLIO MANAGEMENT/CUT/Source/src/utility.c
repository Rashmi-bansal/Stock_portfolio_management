#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <struct.h>
#include <main.h>


int freeLinkedList(stock** st)
{
    stock* iter   = *st;
	int recordsFreed = 0;
    // Following code block frees the dynamically memory allocated 
    while ( iter != NULL )
    {
        stock* temp = iter ;
        iter = iter -> next ;
        if ( temp != NULL)
		{
            free (temp);
			recordsFreed++;
		}
    }
	return recordsFreed;

}


void display_stock(stock* st)
{
    printf("| %s | %s | %d | %d | %s | %d | %d\n",
        st->stockName,
        st->buyDate,
        st->buyQty,
        st->buyPrice,
        st->sellDate,
        st->sellQty,
        st->sellPrice);
}


void printLinkedList(stock *st)
{
    stock* iter = st;
    while ( iter != NULL )
    {
        display_stock(iter);
        iter = iter -> next ;
    }

}

int loadFromFile(const char* fileName, stock **headPointer)
{
	char lineBuffer[STOCK_LINE_BUFFER];
	const char* seperator = "|" ;
	char* token = NULL ;
	stock *iter = NULL;

	FILE* transactionFile = fopen (fileName, "r");
	if (transactionFile == NULL )
    {
		printf("Issue opening the file %s\n", fileName);
		return EXIT_FAILURE ;
	}	

	while ( fgets ( lineBuffer, STOCK_LINE_BUFFER, transactionFile) != 0)
	{
		iter = (stock*) malloc (sizeof(stock));
		if ( iter == NULL )
		{
			printf("Could not allocate memory !\n");
			break;
		}

		token = strtok (lineBuffer, seperator);
		
		if ( token != NULL)
		{
			strcpy(iter -> stockName, token);
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			strcpy(iter -> buyDate, token);
			
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> buyQty = atoi(token);
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> buyPrice = atoi(token);
		}
		token = strtok (NULL, seperator);

		if ( token != NULL)
		{
			strcpy(iter -> sellDate, token);
		}
		token = strtok (NULL, seperator);

		if ( token != NULL)
		{
			iter -> sellQty = atoi(token);
		}


		token = strtok (lineBuffer, seperator);
		if ( token != NULL)
		{
			iter -> sellPrice = atoi(token);
		}

		iter -> next = NULL ;

		append( headPointer, iter );
		
	}

	fclose(transactionFile);

	return 0;
}



