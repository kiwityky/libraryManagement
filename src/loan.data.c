#include <string.h>

#include "loan.data.h"

int tong_so_luong_phieu_muon = 0;
int tong_so_luong_phieu_tra = 0;

int g_phieu_muon_ngay_muon[MAX_SO_LUONG_PHIEU_MUON * LENGTH_NAM_MUON];
int g_phieu_muon_thang_muon[MAX_SO_LUONG_PHIEU_MUON * LENGTH_THANG_MUON];
int g_phieu_muon_nam_muon[MAX_SO_LUONG_PHIEU_MUON * LENGTH_NAM_MUON];
int g_phieu_muon_ngay_tra[MAX_SO_LUONG_PHIEU_MUON * LENGTH_NAM_TRA];
int g_phieu_muon_thang_tra[MAX_SO_LUONG_PHIEU_MUON * LENGTH_THANG_TRA];
int g_phieu_muon_nam_tra[MAX_SO_LUONG_PHIEU_MUON * LENGTH_NAM_TRA];
int g_phieu_muon_so_sach_muon[MAX_SO_LUONG_PHIEU_MUON];
char g_phieu_muon_list_isbn[MAX_SO_LUONG_PHIEU_MUON * 5 * LENGTH_ISBN];
char g_phieu_muon_doc_gia_cmnd[MAX_SO_LUONG_PHIEU_MUON * LENGTH_CMND];
char g_phieu_muon_doc_gia_ho_ten[MAX_SO_LUONG_PHIEU_MUON * LENGTH_HO_VA_TEN];
char g_phieu_muon_trang_thai_sach[MAX_SO_LUONG_PHIEU_MUON * 5];

char* index_isbn_trong_list_sach_muon(int index_phieu_muon, int index_isbn_trong_list_sach_muon) {
    int base = (index_phieu_muon * 5 + index_isbn_trong_list_sach_muon) * LENGTH_ISBN;
    return &g_phieu_muon_list_isbn[base];
}

char* phieu_muon_cmnd_at(int index_phieu_muon) {
    return &g_phieu_muon_doc_gia_cmnd[index_phieu_muon * LENGTH_CMND];
}

char* phieu_muon_ho_ten_at(int index_phieu_muon) {
    return &g_phieu_muon_doc_gia_ho_ten[index_phieu_muon * LENGTH_HO_VA_TEN];
}