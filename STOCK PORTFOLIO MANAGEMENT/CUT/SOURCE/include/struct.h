#pragma once
#ifndef _STRUCT_H_
#define _STRUCT_H_

#define BUY_DATE_LEN 10
#define SELL_DATE_LEN 10
#define BUY_QTY_LEN 10
#define SELL_QTY_LEN 10
#define BUY_PRICE_LEN 100
#define SELL_PRICE_LEN 100
#define STOCK_NAME_LEN 100

#define COMPANY_NOTFOUND -1
#define OPERATION_FAIL -2
#define OPERATION_SUCCESS 0

#define FAILURE -1
#define STOCK_LINE_BUFFER 256

#define MAXSTOCK 50

typedef struct _stock_
{
char buyDate [BUY_DATE_LEN];
char sellDate [SELL_DATE_LEN];
int buyQty;
int sellQty;
int buyPrice;
int sellPrice;
char stockName [STOCK_NAME_LEN];
struct _stock_ *next;

} stock;

#endif

