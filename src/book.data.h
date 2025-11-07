#ifndef BOOK_DATA_H
#define BOOK_DATA_H

#define MAX_SO_LUONG_SACH 1000

#define LENGTH_ISBN 20
#define LENGTH_TIEU_DE 100
#define LENGTH_TAC_GIA 60
#define LENGTH_NXB 60
#define LENGTH_THE_LOAI 60

extern int tong_so_luong_sach;

void khoi_tao_du_lieu_book();

char* isbn_sach_at(int i);
char* tieu_de_sach_at(int i);
char* tac_gia_sach_at(int i);
char* nxb_sach_at(int i);
char* the_loai_sach_at(int i);

extern char g_sach_isbn[MAX_SO_LUONG_SACH * LENGTH_ISBN];
extern char g_sach_tieu_de[MAX_SO_LUONG_SACH * LENGTH_TIEU_DE];
extern char g_sach_tac_gia[MAX_SO_LUONG_SACH * LENGTH_TAC_GIA];
extern char g_sach_nxb[MAX_SO_LUONG_SACH * LENGTH_NXB];
extern char g_sach_the_loai[MAX_SO_LUONG_SACH * LENGTH_THE_LOAI];
extern int  g_sach_nam_xuat_ban[MAX_SO_LUONG_SACH];
extern int  g_sach_gia[MAX_SO_LUONG_SACH];
extern int  g_sach_ban_sao[MAX_SO_LUONG_SACH];
extern int  g_sach_ban_sao_co_san[MAX_SO_LUONG_SACH];

#endif

