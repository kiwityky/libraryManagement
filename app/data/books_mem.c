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

/**
 * Chức năng: Dọn sạch dữ liệu kho sách và đặt bộ đếm về 0.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void reset_book_store() {
    book_count = 0;
    memset(book_isbn_data, 0, sizeof(book_isbn_data));
    memset(book_title_data, 0, sizeof(book_title_data));
    memset(book_author_data, 0, sizeof(book_author_data));
    memset(book_publisher_data, 0, sizeof(book_publisher_data));
    memset(book_category_data, 0, sizeof(book_category_data));
}

/**
 * Chức năng: Lấy vị trí con trỏ cho từng trường chuỗi của sách.
 * Tham số:
 *   - base: Mảng dữ liệu gốc.
 *   - limit: Độ dài tối đa của từng phần tử.
 *   - index: Vị trí sách.
 * Giá trị trả về:
 *   - Con trỏ đến chuỗi tương ứng.
 */
static char *book_slot(char *base, int limit, int index) {
    return &base[index * limit];
}

/**
 * Chức năng: Truy xuất chuỗi ISBN của sách.
 * Tham số:
 *   - index: Chỉ số sách cần lấy.
 * Giá trị trả về:
 *   - Con trỏ tới ISBN.
 */
char *book_isbn_at(int index) {
    return book_slot(book_isbn_data, BOOK_ISBN_LEN, index);
}

/**
 * Chức năng: Truy xuất tiêu đề của sách.
 * Tham số:
 *   - index: Chỉ số sách cần lấy.
 * Giá trị trả về:
 *   - Con trỏ tới tiêu đề.
 */
char *book_title_at(int index) {
    return book_slot(book_title_data, BOOK_TITLE_LEN, index);
}

/**
 * Chức năng: Truy xuất tên tác giả của sách.
 * Tham số:
 *   - index: Chỉ số sách cần lấy.
 * Giá trị trả về:
 *   - Con trỏ tới tên tác giả.
 */
char *book_author_at(int index) {
    return book_slot(book_author_data, BOOK_AUTHOR_LEN, index);
}

/**
 * Chức năng: Truy xuất tên nhà xuất bản của sách.
 * Tham số:
 *   - index: Chỉ số sách cần lấy.
 * Giá trị trả về:
 *   - Con trỏ tới tên nhà xuất bản.
 */
char *book_publisher_at(int index) {
    return book_slot(book_publisher_data, BOOK_PUBLISHER_LEN, index);
}

/**
 * Chức năng: Truy xuất thể loại của sách.
 * Tham số:
 *   - index: Chỉ số sách cần lấy.
 * Giá trị trả về:
 *   - Con trỏ tới thể loại.
 */
char *book_category_at(int index) {
    return book_slot(book_category_data, BOOK_CATEGORY_LEN, index);
}
