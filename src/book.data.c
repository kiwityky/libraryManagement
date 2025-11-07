#include <string.h>

#include "book.data.h"

int tong_so_luong_sach = 0;

char g_sach_isbn[MAX_SO_LUONG_SACH *  LENGTH_ISBN];
char g_sach_tieu_de[MAX_SO_LUONG_SACH * LENGTH_TIEU_DE];
char g_sach_tac_gia[MAX_SO_LUONG_SACH * LENGTH_TAC_GIA];
char g_sach_nxb[MAX_SO_LUONG_SACH * LENGTH_NXB];
char g_sach_the_loai[MAX_SO_LUONG_SACH * LENGTH_THE_LOAI];
int  g_sach_nam_xuat_ban[MAX_SO_LUONG_SACH];
int  g_sach_gia[MAX_SO_LUONG_SACH];
int  g_sach_ban_sao[MAX_SO_LUONG_SACH];
int  g_sach_ban_sao_co_san[MAX_SO_LUONG_SACH];

void khoi_tao_du_lieu_book() {
    tong_so_luong_sach = 0;
}

char* isbn_sach_at(int index) {
    return &g_sach_isbn[index * LENGTH_ISBN];
}

char* tieu_de_sach_at(int index) {
    return &g_sach_tieu_de[index * LENGTH_TIEU_DE];
} 

char* tac_gia_sach_at(int index) {
    return &g_sach_tac_gia[index * LENGTH_TAC_GIA];
}

char* nxb_sach_at(int index) {
    return &g_sach_nxb[index * LENGTH_NXB];
}

char* the_loai_sach_at(int index) {
    return &g_sach_the_loai[index * LENGTH_THE_LOAI];
}