#include <string.h>

#include "reader.data.h"

int tong_so_luong_doc_gia = 0;

char g_doc_gia_ma[MAX_SO_LUONG_DOC_GIA * LENGTH_MA_DOC_GIA];
char g_doc_gia_hoten[MAX_SO_LUONG_DOC_GIA * LENGTH_HO_VA_TEN];
char g_doc_gia_cmnd[MAX_SO_LUONG_DOC_GIA * LENGTH_CMND];
int g_doc_gia_ngay_sinh[MAX_SO_LUONG_DOC_GIA * LENGTH_DATE_OF_BIRTH];
int g_doc_gia_thang_sinh[MAX_SO_LUONG_DOC_GIA * LENGTH_MONTH_OF_BIRTH];
int g_doc_gia_nam_sinh[MAX_SO_LUONG_DOC_GIA * LENGTH_YEAR_OF_BIRTH];
char g_doc_gia_gioi_tinh[MAX_SO_LUONG_DOC_GIA * LENGTH_GIOI_TINH];
char g_doc_gia_email[MAX_SO_LUONG_DOC_GIA * LENGTH_EMAIL];
char g_doc_gia_dia_chi[MAX_SO_LUONG_DOC_GIA * LENGTH_DIA_CHI];
int g_doc_gia_ngay_lap_the[MAX_SO_LUONG_DOC_GIA * LENGTH_NGAY_LAP_THE];
int g_doc_gia_thang_lap_the[MAX_SO_LUONG_DOC_GIA * LENGTH_THANG_LAP_THE];
int g_doc_gia_nam_lap_the[MAX_SO_LUONG_DOC_GIA * LENGTH_NAM_LAP_THE];
int g_doc_gia_ngay_het_han_the[MAX_SO_LUONG_DOC_GIA * LENGTH_NGAY_HET_HAN_THE];
int g_doc_gia_thang_het_han_the[MAX_SO_LUONG_DOC_GIA * LENGTH_THANG_HET_HAN_THE];
int g_doc_gia_nam_het_han_the[MAX_SO_LUONG_DOC_GIA * LENGTH_NAM_HET_HAN_THE];

void khoi_tao_du_lieu_reader() {
    tong_so_luong_doc_gia = 0;
}

char* ma_doc_gia_at(int index) {
    return &g_doc_gia_ma[index * LENGTH_MA_DOC_GIA];
}

char* ho_va_ten_at(int index) {
    return &g_doc_gia_hoten[index * LENGTH_HO_VA_TEN];
}

char* cmnd_at(int index) {
    return &g_doc_gia_cmnd[index * LENGTH_CMND];
}

int* ngay_sinh_at(int index) {
    return &g_doc_gia_ngay_sinh[index * LENGTH_DATE_OF_BIRTH];
}

int* thang_sinh_at(int index) {
    return &g_doc_gia_thang_sinh[index * LENGTH_MONTH_OF_BIRTH];
}

int* nam_sinh_at(int index) {
    return &g_doc_gia_nam_sinh[index * LENGTH_YEAR_OF_BIRTH];
}

char* gioi_tinh_at(int index) {
    return &g_doc_gia_gioi_tinh[index * LENGTH_GIOI_TINH];
}

char* email_at(int index) {
    return &g_doc_gia_email[index * LENGTH_EMAIL];
}

char* dia_chi_at(int index) {
    return &g_doc_gia_dia_chi[index * LENGTH_DIA_CHI];
}

int* ngay_lap_the_at(int index) {
    return &g_doc_gia_ngay_lap_the[index * LENGTH_NGAY_LAP_THE];
}

int* thang_lap_the_at(int index) {
    return &g_doc_gia_thang_lap_the[index * LENGTH_THANG_LAP_THE];
}

int* nam_lap_the_at(int index) {
    return &g_doc_gia_nam_lap_the[index * LENGTH_NAM_LAP_THE];
}

int *ngay_het_han_the_at(int index) {
    return &g_doc_gia_ngay_het_han_the[index * LENGTH_NGAY_HET_HAN_THE];
}

int *thang_het_han_the_at(int index) {
    return &g_doc_gia_thang_het_han_the[index * LENGTH_THANG_HET_HAN_THE];
}

int *nam_het_han_the_at(int index) {
    return &g_doc_gia_nam_het_han_the[index * LENGTH_NAM_HET_HAN_THE];
}

