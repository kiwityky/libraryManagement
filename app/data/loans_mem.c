#include <string.h>

#include "loans_mem.h"

int loan_count = 0;
int return_count = 0;

static char loan_idcards[LOAN_CAPACITY * MEMBER_IDCARD_LEN];
static char loan_names[LOAN_CAPACITY * MEMBER_NAME_LEN];
static char loan_isbn_bucket[LOAN_CAPACITY * LOAN_ITEM_LIMIT * BOOK_ISBN_LEN];
static int loan_status_bucket[LOAN_CAPACITY * LOAN_ITEM_LIMIT];
static int loan_books_counter[LOAN_CAPACITY];

int loan_borrow_day[LOAN_CAPACITY];
int loan_borrow_month[LOAN_CAPACITY];
int loan_borrow_year[LOAN_CAPACITY];
int loan_due_day[LOAN_CAPACITY];
int loan_due_month[LOAN_CAPACITY];
int loan_due_year[LOAN_CAPACITY];

void reset_loan_store() {
    loan_count = 0;
    return_count = 0;
    memset(loan_idcards, 0, sizeof(loan_idcards));
    memset(loan_names, 0, sizeof(loan_names));
    memset(loan_isbn_bucket, 0, sizeof(loan_isbn_bucket));
    memset(loan_status_bucket, 0, sizeof(loan_status_bucket));
    memset(loan_books_counter, 0, sizeof(loan_books_counter));
}

static char *loan_slot(char *base, int limit, int index) {
    return &base[index * limit];
}

char *loan_idcard_at(int index) {
    return loan_slot(loan_idcards, MEMBER_IDCARD_LEN, index);
}

char *loan_member_name_at(int index) {
    return loan_slot(loan_names, MEMBER_NAME_LEN, index);
}

int *loan_books_amount() {
    return loan_books_counter;
}

int loan_item_position(int loan_index, int book_index) {
    return loan_index * LOAN_ITEM_LIMIT + book_index;
}

char *loan_isbn_at(int loan_index, int book_index) {
    int offset = (loan_index * LOAN_ITEM_LIMIT + book_index) * BOOK_ISBN_LEN;
    return &loan_isbn_bucket[offset];
}

int *loan_item_status() {
    return loan_status_bucket;
}
