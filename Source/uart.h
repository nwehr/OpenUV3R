#ifndef _uart_h
#define _uart_h

#include <MC81F8816.h>

void uart_init();
void uart_tx(char* msg, int len);

#endif