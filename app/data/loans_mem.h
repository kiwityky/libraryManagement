#ifndef LOANS_MEM_H
#define LOANS_MEM_H

#include "members_mem.h"
#include "books_mem.h"

#define LOAN_CAPACITY 2000
#define LOAN_ITEM_LIMIT 5

extern int loan_count;
extern int return_count;

/**
 * Chức năng: Đặt lại toàn bộ dữ liệu mượn trả trong bộ nhớ.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void reset_loan_store();

/**
 * Chức năng: Lấy con trỏ tới CMND trong bản ghi mượn ở vị trí cho trước.
 * Tham số:
 *   - index: Chỉ số phiếu mượn (0 <= index < LOAN_CAPACITY).
 * Giá trị trả về:
 *   - Con trỏ tới chuỗi CMND.
 */
char *loan_idcard_at(int index);
/*
 * Chức năng: Lấy con trỏ tới họ tên thành viên trong bản ghi mượn.
 * Tham số:
 *   - index: Chỉ số phiếu mượn.
 * Giá trị trả về:
 *   - Con trỏ tới chuỗi họ tên.
 */
char *loan_member_name_at(int index);
/**
 * Chức năng: Lấy con trỏ tới mảng số lượng sách trong mỗi phiếu mượn.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - Con trỏ tới mảng đếm số sách.
 */
int *loan_books_amount();
/**
 * Chức năng: Lấy con trỏ tới ISBN của sách trong phiếu mượn.
 * Tham số:
 *   - loan_index: Chỉ số phiếu mượn.
 *   - book_index: Vị trí sách trong phiếu (0 <= book_index < LOAN_ITEM_LIMIT).
 * Giá trị trả về:
 *   - Con trỏ tới chuỗi ISBN.
 */
char *loan_isbn_at(int loan_index, int book_index);
/**
 * Chức năng: Lấy con trỏ tới mảng trạng thái từng sách trong các phiếu mượn.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - Con trỏ tới mảng trạng thái (0: chưa trả, 1: đã trả, 2: mất).
 */
int *loan_item_status();
/**
 * Chức năng: Tính vị trí phần tử trạng thái tương ứng trong mảng phẳng.
 * Tham số:
 *   - loan_index: Chỉ số phiếu mượn.
 *   - book_index: Vị trí sách trong phiếu.
 * Giá trị trả về:
 *   - Chỉ số phần tử trong mảng trạng thái/ISBN phẳng.
 */
int loan_item_position(int loan_index, int book_index);

extern int loan_borrow_day[LOAN_CAPACITY];
extern int loan_borrow_month[LOAN_CAPACITY];
extern int loan_borrow_year[LOAN_CAPACITY];
extern int loan_due_day[LOAN_CAPACITY];
extern int loan_due_month[LOAN_CAPACITY];
extern int loan_due_year[LOAN_CAPACITY];

#endif
