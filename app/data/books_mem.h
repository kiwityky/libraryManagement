#ifndef BOOKS_MEM_H
#define BOOKS_MEM_H

#define BOOK_CAPACITY 1000
#define BOOK_ISBN_LEN 20
#define BOOK_TITLE_LEN 100
#define BOOK_AUTHOR_LEN 60
#define BOOK_PUBLISHER_LEN 60
#define BOOK_CATEGORY_LEN 60

extern int book_count;

void reset_book_store();

char *book_isbn_at(int index);
char *book_title_at(int index);
char *book_author_at(int index);
char *book_publisher_at(int index);
char *book_category_at(int index);

extern int book_year[BOOK_CAPACITY];
extern int book_price[BOOK_CAPACITY];
extern int book_total_copy[BOOK_CAPACITY];
extern int book_available_copy[BOOK_CAPACITY];

#endif
