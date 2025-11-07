#include <string.h>

#include "books_mem.h"

int book_count = 0;

static char book_isbn_data[BOOK_CAPACITY * BOOK_ISBN_LEN];
static char book_title_data[BOOK_CAPACITY * BOOK_TITLE_LEN];
static char book_author_data[BOOK_CAPACITY * BOOK_AUTHOR_LEN];
static char book_publisher_data[BOOK_CAPACITY * BOOK_PUBLISHER_LEN];
static char book_category_data[BOOK_CAPACITY * BOOK_CATEGORY_LEN];

int book_year[BOOK_CAPACITY];
int book_price[BOOK_CAPACITY];
int book_total_copy[BOOK_CAPACITY];
int book_available_copy[BOOK_CAPACITY];

void reset_book_store() {
    book_count = 0;
    memset(book_isbn_data, 0, sizeof(book_isbn_data));
    memset(book_title_data, 0, sizeof(book_title_data));
    memset(book_author_data, 0, sizeof(book_author_data));
    memset(book_publisher_data, 0, sizeof(book_publisher_data));
    memset(book_category_data, 0, sizeof(book_category_data));
}

static char *book_slot(char *base, int limit, int index) {
    return &base[index * limit];
}

char *book_isbn_at(int index) {
    return book_slot(book_isbn_data, BOOK_ISBN_LEN, index);
}

char *book_title_at(int index) {
    return book_slot(book_title_data, BOOK_TITLE_LEN, index);
}

char *book_author_at(int index) {
    return book_slot(book_author_data, BOOK_AUTHOR_LEN, index);
}

char *book_publisher_at(int index) {
    return book_slot(book_publisher_data, BOOK_PUBLISHER_LEN, index);
}

char *book_category_at(int index) {
    return book_slot(book_category_data, BOOK_CATEGORY_LEN, index);
}
