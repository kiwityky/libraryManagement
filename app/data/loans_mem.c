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

/**
 * Chức năng: Đặt lại bộ dữ liệu phiếu mượn và phiếu trả về trạng thái trống.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void reset_loan_store() {
    loan_count = 0;
    return_count = 0;
    memset(loan_idcards, 0, sizeof(loan_idcards));
    memset(loan_names, 0, sizeof(loan_names));
    memset(loan_isbn_bucket, 0, sizeof(loan_isbn_bucket));
    memset(loan_status_bucket, 0, sizeof(loan_status_bucket));
    memset(loan_books_counter, 0, sizeof(loan_books_counter));
}

/**
 * Chức năng: Tính con trỏ đến vùng dữ liệu chuỗi theo chỉ số.
 * Tham số:
 *   - base: Mảng dữ liệu gốc.
 *   - limit: Độ dài của mỗi mục.
 *   - index: Vị trí cần lấy.
 * Giá trị trả về:
 *   - Con trỏ đến dữ liệu tương ứng.
 */
static char *loan_slot(char *base, int limit, int index) {
    return &base[index * limit];
}

/**
 * Chức năng: Lấy CMND của độc giả trong phiếu mượn.
 * Tham số:
 *   - index: Chỉ số phiếu mượn.
 * Giá trị trả về:
 *   - Con trỏ tới chuỗi CMND.
 */
char *loan_idcard_at(int index) {
    return loan_slot(loan_idcards, MEMBER_IDCARD_LEN, index);
}

/**
 * Chức năng: Lấy họ tên độc giả trong phiếu mượn.
 * Tham số:
 *   - index: Chỉ số phiếu mượn.
 * Giá trị trả về:
 *   - Con trỏ tới chuỗi họ tên.
 */
char *loan_member_name_at(int index) {
    return loan_slot(loan_names, MEMBER_NAME_LEN, index);
}

/**
 * Chức năng: Lấy mảng lưu số sách trong từng phiếu mượn.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - Con trỏ tới mảng đếm số sách.
 */
int *loan_books_amount() {
    return loan_books_counter;
}

/**
 * Chức năng: Tính chỉ số phần tử trong mảng phẳng cho sách của phiếu mượn.
 * Tham số:
 *   - loan_index: Chỉ số phiếu mượn.
 *   - book_index: Thứ tự sách trong phiếu.
 * Giá trị trả về:
 *   - Vị trí phần tử trong mảng phẳng.
 */
int loan_item_position(int loan_index, int book_index) {
    return loan_index * LOAN_ITEM_LIMIT + book_index;
}

/**
 * Chức năng: Lấy ISBN của sách trong phiếu mượn theo vị trí.
 * Tham số:
 *   - loan_index: Chỉ số phiếu mượn.
 *   - book_index: Thứ tự sách trong phiếu.
 * Giá trị trả về:
 *   - Con trỏ tới chuỗi ISBN.
 */
char *loan_isbn_at(int loan_index, int book_index) {
    int offset = (loan_index * LOAN_ITEM_LIMIT + book_index) * BOOK_ISBN_LEN;
    return &loan_isbn_bucket[offset];
}

/**
 * Chức năng: Lấy mảng trạng thái sách theo từng phiếu mượn.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - Con trỏ tới mảng trạng thái.
 */
int *loan_item_status() {
    return loan_status_bucket;
}
