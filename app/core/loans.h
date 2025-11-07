#ifndef LOANS_H
#define LOANS_H

#include "../data/loans_mem.h"

void create_loan_ticket();
void process_return_ticket();
void show_borrowed_overview();
int count_unreturned_books();

#endif
