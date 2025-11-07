
#ifndef BOOK_H
#define BOOK_H

#include "book.data.h"

// function lấy show list sách và số lượng sách có trong thư viện
void get_list_sach();

// function in sách theo hàng
void print_sach_theo_hang(int i);

// function thêm sách vào thư viện
int them_sach();

// function xóa sách khỏi thư viện
void xoa_sach();

// function cập nhật thông tin sách
void cap_nhat_sach();

// function tìm sách theo ISBN
void tim_sach_theo_ISBN();

// function tìm sách theo tiêu đề
void tim_sach_theo_tieu_de();

// function cập nhật số lượng sách còn lại khi cập nhật tổng số lượng sách
// params: int index của sách
// return: none
void cap_nhat_so_luong_sach_co_san(int index);

// function tìm sách được thêm thư viện bằng ISBN
// params: char* isbn
// return: 0 nếu chưa tồn tại, 1 nếu đã tồn tại
int tim_sach_bang_ISBN(const char* isbn); 

// function validate sách bằng ISBN
// params: char* isbn
// return 0 nếu chưa tồn tại, 1 nếu đã tồn tại
int validate_sach_by_isbn(const char* isbn);

// function tìm sách bằng tiêu đề
// params: const char* tieu_de
// return: index của sách hoặc -1 nếu không tìm thấy
int tim_sach_bang_tieu_de(const char* tieu_de);

// function chọn thể loại sách từ menu
// params: char* the_loai_output
// return: none
void chon_the_loai_sach(char* the_loai_output);

#endif
