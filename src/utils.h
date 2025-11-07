#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

// Đọc số nguyên trong khoảng [min_val, max_val] với kiểm tra lỗi.
int nhap_so_nguyen(const char* prompt, int min_val, int max_val);

// Nhập một chuỗi ký tự từ stdin vào bộ đệm.
void nhap_chuoi(const char* prompt, char* buf, int max_len);

// Sao chép chuỗi nguồn vào vùng nhớ đích (một chiều).
void luu_du_lieu_vao_vung_nho(char* dest, const char* source);

// Ghi giá trị số nguyên vào vùng nhớ đích.
void luu_so_nguyen_vao_vung_nho(int* dest, int value);

// Dừng màn hình cho tới khi người dùng nhấn Enter.
void press_enter_to_continue();

// Kiểm tra ngày tháng năm hợp lệ (giả định mỗi tháng có tối đa 31 ngày).
int validate_ngay_thang_nam(int ngay, int thang, int nam);

// Nhập ngày/tháng/năm ở định dạng dd/mm/yyyy và trả về giá trị đã tách.
int nhap_ngay_thang_nam(const char* label, int* ngay, int* thang, int* nam);

// Cộng thêm số ngày (giả định mỗi tháng 30 ngày) vào ngày cho trước.
void cong_ngay_gia_dinh_30(int ngay, int thang, int nam, int so_ngay_them,
                           int* ngay_out, int* thang_out, int* nam_out);

// Cộng thêm số tháng vào ngày cho trước (giả định 12 tháng/năm, 30 ngày/tháng).
void cong_thang_gia_dinh_30(int ngay, int thang, int nam, int so_thang_them,
                            int* ngay_out, int* thang_out, int* nam_out);

// Tính số ngày chênh lệch giữa hai mốc thời gian (mỗi tháng 30 ngày).
int tinh_so_ngay_chenh_lech_gia_dinh_30(int ngay1, int thang1, int nam1,
                                        int ngay2, int thang2, int nam2);

#endif
