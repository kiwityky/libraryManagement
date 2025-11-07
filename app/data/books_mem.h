#ifndef BOOKS_MEM_H
#define BOOKS_MEM_H

#define BOOK_CAPACITY 1000
#define BOOK_ISBN_LEN 20
#define BOOK_TITLE_LEN 100
#define BOOK_AUTHOR_LEN 60
#define BOOK_PUBLISHER_LEN 60
#define BOOK_CATEGORY_LEN 60

extern int book_count;

/**
 * Chức năng: Đặt lại kho sách đang lưu trong bộ nhớ.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void reset_book_store();

/**
 * Chức năng: Lấy con trỏ đến ISBN của sách tại vị trí tương ứng.
 * Tham số:
 *   - index: Chỉ số sách (0 <= index < BOOK_CAPACITY).
 * Giá trị trả về:
 *   - Con trỏ tới chuỗi ISBN.
 */
char *book_isbn_at(int index);
/**
 * Chức năng: Lấy con trỏ đến tiêu đề sách tại vị trí tương ứng.
 * Tham số:
 *   - index: Chỉ số sách (0 <= index < BOOK_CAPACITY).
 * Giá trị trả về:
 *   - Con trỏ tới chuỗi tiêu đề.
 */
char *book_title_at(int index);
/**
 * Chức năng: Lấy con trỏ đến tác giả sách tại vị trí tương ứng.
 * Tham số:
 *   - index: Chỉ số sách (0 <= index < BOOK_CAPACITY).
 * Giá trị trả về:
 *   - Con trỏ tới chuỗi tác giả.
 */
char *book_author_at(int index);
/**
 * Chức năng: Lấy con trỏ đến nhà xuất bản của sách tại vị trí tương ứng.
 * Tham số:
 *   - index: Chỉ số sách (0 <= index < BOOK_CAPACITY).
 * Giá trị trả về:
 *   - Con trỏ tới chuỗi nhà xuất bản.
 */
char *book_publisher_at(int index);
/**
 * Chức năng: Lấy con trỏ đến thể loại sách tại vị trí tương ứng.
 * Tham số:
 *   - index: Chỉ số sách (0 <= index < BOOK_CAPACITY).
 * Giá trị trả về:
 *   - Con trỏ tới chuỗi thể loại.
 */
char *book_category_at(int index);

extern int book_year[BOOK_CAPACITY];
extern int book_price[BOOK_CAPACITY];
extern int book_total_copy[BOOK_CAPACITY];
extern int book_available_copy[BOOK_CAPACITY];

#endif
