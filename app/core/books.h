#ifndef BOOKS_H
#define BOOKS_H

#include "../data/books_mem.h"

void list_books();
void add_book_entry();
void update_book_entry();
void remove_book_by_isbn();
void search_book_by_isbn();
void search_book_by_title();

int locate_book_by_isbn(const char *isbn);

#endif
