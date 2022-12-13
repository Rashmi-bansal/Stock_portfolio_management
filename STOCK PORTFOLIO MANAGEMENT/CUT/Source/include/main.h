#ifndef __MAIN_H__
#define __MAIN_H__

#include <struct.h>

//extern stock*  searchStockName (stock* headPointer, int stock_Name);
extern int  loadFromFile(const char* fileName, stock **headPointer);
extern void display_stock(stock* st);
extern void printLinkedList(stock* st);
extern int  freeLinkedList(stock** st);
extern void append(stock **headPointer, stock* data);
extern void selectChoice(char* stockName);
extern void menu(stock** st);
extern void doFindReport(stock* st, char* stockName);
//void doFindReport(stock * st, char* stockName);
extern void doAddTransaction(stock** st, char* stockName);

#endif

