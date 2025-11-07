#ifndef LOANS_MEM_H
#define LOANS_MEM_H

#include "members_mem.h"
#include "books_mem.h"

#define LOAN_CAPACITY 2000
#define LOAN_ITEM_LIMIT 5

extern int loan_count;
extern int return_count;

void reset_loan_store();

char *loan_idcard_at(int index);
char *loan_member_name_at(int index);
int *loan_books_amount();
char *loan_isbn_at(int loan_index, int book_index);
int *loan_item_status();
int loan_item_position(int loan_index, int book_index);

extern int loan_borrow_day[LOAN_CAPACITY];
extern int loan_borrow_month[LOAN_CAPACITY];
extern int loan_borrow_year[LOAN_CAPACITY];
extern int loan_due_day[LOAN_CAPACITY];
extern int loan_due_month[LOAN_CAPACITY];
extern int loan_due_year[LOAN_CAPACITY];

#endif
