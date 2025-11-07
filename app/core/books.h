#ifndef BOOKS_H
#define BOOKS_H

#include "../data/books_mem.h"

//Chức năng: Hiển thị danh mục sách hiện có.
void list_books();

//Chức năng: Nhập và thêm mới một bản ghi sách.
void add_book_entry();

//Chức năng: Cập nhật thông tin của một bản ghi sách.
void update_book_entry();

//Chức năng: Xóa sách khỏi kho bằng ISBN.
void remove_book_by_isbn();

//Chức năng: Tìm và hiển thị sách theo ISBN.
 void search_book_by_isbn();

 //Chức năng: Tìm và hiển thị sách theo tiêu đề chính xác.
void search_book_by_title();

/**Chức năng: Tìm vị trí sách dựa trên ISBN.
 * Tham số: isbn: Chuỗi ISBN cần tìm.
 * Giá trị trả về: Chỉ số sách hoặc -1 nếu không tồn tại.*/
int locate_book_by_isbn(const char *isbn);

#endif
