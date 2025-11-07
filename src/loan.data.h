#include "book.data.h"
#include "reader.data.h"

#ifndef LOAN_DATA_H
#define LOAN_DATA_H

#define MAX_SO_LUONG_PHIEU_MUON 2000
#define MAX_SO_LUONG_PHIEU_TRA 2000

#define LENGTH_NGAY_MUON 10
#define LENGTH_THANG_MUON 10
#define LENGTH_NAM_MUON 10
#define LENGTH_NGAY_TRA 10
#define LENGTH_THANG_TRA 10
#define LENGTH_NAM_TRA 10

extern int tong_so_luong_phieu_muon;
extern int tong_so_luong_phieu_tra;

extern char g_phieu_muon_doc_gia_ho_ten[MAX_SO_LUONG_PHIEU_MUON * LENGTH_HO_VA_TEN];
extern char g_phieu_muon_doc_gia_cmnd[MAX_SO_LUONG_PHIEU_MUON * LENGTH_CMND]; 
extern int g_phieu_muon_ngay_muon[MAX_SO_LUONG_PHIEU_MUON * LENGTH_NAM_MUON];
extern int g_phieu_muon_thang_muon[MAX_SO_LUONG_PHIEU_MUON * LENGTH_THANG_MUON];
extern int g_phieu_muon_nam_muon[MAX_SO_LUONG_PHIEU_MUON * LENGTH_NAM_MUON];
extern int g_phieu_muon_ngay_tra[MAX_SO_LUONG_PHIEU_MUON * LENGTH_NGAY_TRA];
extern int g_phieu_muon_thang_tra[MAX_SO_LUONG_PHIEU_MUON * LENGTH_THANG_TRA];
extern int g_phieu_muon_nam_tra[MAX_SO_LUONG_PHIEU_MUON * LENGTH_NAM_TRA];
extern int g_phieu_muon_so_sach_muon[MAX_SO_LUONG_PHIEU_MUON];
extern char g_phieu_muon_list_isbn[MAX_SO_LUONG_PHIEU_MUON * 5 * LENGTH_ISBN];
extern char g_phieu_muon_trang_thai_sach[MAX_SO_LUONG_PHIEU_MUON * 5];

// function xác định vị trí của isbn trong list isbn sách mượn
char* index_isbn_trong_list_sach_muon(int index_phieu_muon, int index_isbn_trong_list_sach_muon);

char* phieu_muon_cmnd_at(int index);
char* phieu_muon_ho_ten_at(int index);

#endif
