#include <stdio.h>
#include <stdlib.h>
#include <main.h>
#include <unistd.h>
#include <string.h>
#include <stdio_ext.h>
//#include <conio.h>



void doFindReport(stock* st, char* stockName)
{
	stock* iter = st;
	int buyPrice = 0;
	int sellPrice = 0;
	int profit = 0;
	int loss = 0;
	
	
	while ( iter != NULL)
	{
		if(strcmp( iter -> stockName, stockName) == 0)
		{
			buyPrice += iter->buyPrice*iter->buyQty ;
			sellPrice += iter->sellPrice*iter->sellQty ;
		}
	        iter = iter->next;
	
	}
	
	if(sellPrice>buyPrice)
	{
		profit = sellPrice - buyPrice;
		printf ( "Profit for stock %s is %d\n", stockName, profit);
	}
		
	else
			
       {
		loss = buyPrice - sellPrice;
		printf ( "Loss for stock %s is %d\n", stockName, loss);
       }
       
   //  printf("\nPress any key to return to main section..\n");
    
	//__fpurge(stdin);
	
     //getch();

}


void doAddTransaction(stock** st, char* stockName)
{
	FILE* fp = fopen("../data/transaction.csv", "a+");
	int buyQty = 0;
	int sellQty = 0;
	char buyDate[BUY_DATE_LEN] ;
	char sellDate[SELL_DATE_LEN] ;
	int buyPrice = 0;
	int sellPrice = 0;
	
	if(!fp)
	{
		printf("Can't open file\n");
		return ;
	}
	
	else
	{
		printf("---------------------------------------------------\n");
		printf("Kindly add details to the stock..\n\n");

		printf("Enter sell date of stock      : ");
		if (scanf("%s", sellDate) != 1)
		{
		        fflush(stdin);
		        printf("Please enter a valid date\n");
		        return ;
		}

		printf("Enter buy date of stock       : ");
		if (scanf("%s", buyDate) != 1)
		{
			fflush(stdin);
			printf("Please enter a valid date\n");
			return ;
		}

		printf("Enter sell quantity of stock  : ");
		if (1 != scanf("%d", &sellQty))
		{
			fflush(stdin);
			printf("Please enter a valid quantity\n");
			return ;
		}

		printf("Enter sell price of stock     : ");
		if (1 != scanf("%d", &sellPrice))
		{
		        fflush(stdin);
		        printf("Please enter a valid price\n");
		        return ;
		}
		printf("Enter buy quantity of stock   : ");
		if (1 != scanf("%d", &buyQty))
		{
			fflush(stdin);
			printf("Please enter a valid quantity\n");
			return ;
		}

		printf("Enter buy price of stock      : ");
		if (1 != scanf("%d", &buyPrice))
		{
			fflush(stdin);
			printf("Please enter a valid price\n");
			return ;
		}
		printf("---------------------------------------------------\n");
	}
	
    stock *newStock = (stock*)malloc(sizeof(stock));
    strcpy(newStock -> stockName, stockName);
    strcpy(newStock -> buyDate, buyDate);
    strcpy(newStock -> sellDate, "");
    newStock -> buyQty = buyQty ;
    newStock -> sellQty = sellQty ;
    newStock -> buyPrice = buyPrice ;
    newStock -> sellPrice = sellPrice ;
    
    fprintf(fp, "%s|%s|%d|%d|%s|%d|%d\n",stockName, buyDate, buyQty, buyPrice, sellDate, sellQty, sellPrice);
    
    printf("\nDetails added successfully\n");
    
    fclose(fp);
    
    printf("\nPress any key to return to main section..\n");
    
    __fpurge(stdin);
	
     getchar();

}

void  menu(stock** st)
{
	int ch ;
	int returnValue = 0;
	char stockName[30];
	
	
	do 
	{
	     
	    //system("clear");
	   
	    printf("-------------------------------------------------\n");	
		printf("1. Add Transaction\n");
		printf("2. Display Report (Profit/Loss)\n");
		printf("3. Save Files (Masters)\n");
		printf("4. Exit \n");
	    printf("------------------------------------------------\n\n");	
	        
	    printf("\tChoice : ");

		returnValue = scanf ("%d", &ch);
		if ( returnValue == 0 || returnValue ==  EOF)
		{
			fflush(stdin);
			printf("Invalid input. Please enter valid input\n");
			//continue ; // 
			
			break;
		}
		
		//loadFromFile("../data/transaction.csv", &st[0]);
		switch(ch)
		{
			case 1:
				//system("clear");
				selectChoice(stockName);
				doAddTransaction(st, stockName);
				break;
	
			case 2:
				//system("clear");
				selectChoice(stockName);
				doFindReport(*st, stockName);
				break;
				
	
			case 3:
				//system("clear");
				printf("File saved successfully\n\n");
				break;
		
			case 4:
				//system("clear");
				printf("Exiting\n");
				break;
				
			default:
			    printf("Invalid operation\n\n");
				break;
		}

	} while ( ch != 4);
	

}

