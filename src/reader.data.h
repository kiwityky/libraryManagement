#ifndef READER_DATA_H
#define READER_DATA_H

#define MAX_SO_LUONG_DOC_GIA 1000

#define LENGTH_MA_DOC_GIA 20
#define LENGTH_HO_VA_TEN 100
#define LENGTH_CMND 12
#define LENGTH_DATE_OF_BIRTH 10
#define LENGTH_MONTH_OF_BIRTH 10
#define LENGTH_YEAR_OF_BIRTH 10
#define LENGTH_GIOI_TINH 10
#define LENGTH_EMAIL 20
#define LENGTH_DIA_CHI 100
#define LENGTH_NGAY_LAP_THE 10
#define LENGTH_THANG_LAP_THE 10
#define LENGTH_NAM_LAP_THE 10
#define LENGTH_NGAY_HET_HAN_THE 10
#define LENGTH_THANG_HET_HAN_THE 10
#define LENGTH_NAM_HET_HAN_THE 10


extern int tong_so_luong_doc_gia;

// function khởi tạo data reader
void khoi_tao_du_lieu_reader();

extern char g_doc_gia_ma[MAX_SO_LUONG_DOC_GIA * LENGTH_MA_DOC_GIA];
extern char g_doc_gia_hoten[MAX_SO_LUONG_DOC_GIA * LENGTH_HO_VA_TEN];
extern char g_doc_gia_cmnd[MAX_SO_LUONG_DOC_GIA * LENGTH_CMND];
extern int g_doc_gia_ngay_sinh[MAX_SO_LUONG_DOC_GIA * LENGTH_DATE_OF_BIRTH];
extern int g_doc_gia_thang_sinh[MAX_SO_LUONG_DOC_GIA * LENGTH_MONTH_OF_BIRTH];
extern int g_doc_gia_nam_sinh[MAX_SO_LUONG_DOC_GIA * LENGTH_YEAR_OF_BIRTH];
extern char g_doc_gia_gioi_tinh[MAX_SO_LUONG_DOC_GIA * LENGTH_GIOI_TINH];
extern char g_doc_gia_email[MAX_SO_LUONG_DOC_GIA * LENGTH_EMAIL];
extern char g_doc_gia_dia_chi[MAX_SO_LUONG_DOC_GIA * LENGTH_DIA_CHI];
extern int g_doc_gia_ngay_lap_the[MAX_SO_LUONG_DOC_GIA * LENGTH_NGAY_LAP_THE];
extern int g_doc_gia_thang_lap_the[MAX_SO_LUONG_DOC_GIA * LENGTH_THANG_LAP_THE];
extern int g_doc_gia_nam_lap_the[MAX_SO_LUONG_DOC_GIA * LENGTH_NAM_LAP_THE];
extern int g_doc_gia_ngay_het_han_the[MAX_SO_LUONG_DOC_GIA * LENGTH_NGAY_HET_HAN_THE];
extern int g_doc_gia_thang_het_han_the[MAX_SO_LUONG_DOC_GIA * LENGTH_THANG_HET_HAN_THE];
extern int g_doc_gia_nam_het_han_the[MAX_SO_LUONG_DOC_GIA * LENGTH_NAM_HET_HAN_THE];


char* ma_doc_gia_at(int index);
char* ho_va_ten_at(int index);
char* cmnd_at(int index);
char* gioi_tinh_at(int index);
char* email_at(int index);
char* dia_chi_at(int index);

#endif

