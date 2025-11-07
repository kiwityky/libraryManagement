
#ifndef READER_H
#define READER_H

#include "reader.data.h"

void print_doc_gia_theo_hang(int i);
void get_danh_sach_doc_gia();
int them_doc_gia();
int validate_ma_doc_gia(const char* ma_doc_gia);
int tim_doc_gia_by_ma(const char* ma_doc_gia);
int tim_doc_gia_by_cmnd(const char* cmnd);
int tim_doc_gia_by_ho_va_ten(const char* ho_va_ten);
void xoa_doc_gia_bang_cmnd();
void tim_doc_gia_bang_ma();
void tim_doc_gia_bang_cmnd();
void tim_doc_gia_bang_ho_va_ten();
void cap_nhat_doc_gia();

#endif
