#ifndef BOOKS_H
#define BOOKS_H

#include "../data/books_mem.h"

/**
 * Chức năng: Hiển thị danh mục sách hiện có.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void list_books();
/**
 * Chức năng: Nhập và thêm mới một bản ghi sách.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void add_book_entry();
/**
 * Chức năng: Cập nhật thông tin của một bản ghi sách.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void update_book_entry();
/**
 * Chức năng: Xóa sách khỏi kho bằng ISBN.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void remove_book_by_isbn();
/**
 * Chức năng: Tìm và hiển thị sách theo ISBN.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void search_book_by_isbn();
/**
 * Chức năng: Tìm và hiển thị sách theo tiêu đề chính xác.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void search_book_by_title();

/**
 * Chức năng: Tìm vị trí sách dựa trên ISBN.
 * Tham số:
 *   - isbn: Chuỗi ISBN cần tìm.
 * Giá trị trả về:
 *   - Chỉ số sách hoặc -1 nếu không tồn tại.
 */
int locate_book_by_isbn(const char *isbn);

#endif
