#include <stdio.h>

#include "utils.h"

#include "book.h"
#include "book.data.h"
#include "reader.h"
#include "reader.data.h"
#include "stats.h"

#include "loan.h"
#include "loan_return.h"
#include "loan.data.h"


static void xu_ly_quan_ly_doc_gia() {
    printf("\n=== QUAN LY DOC GIA ===\n");
    printf("1. Xem danh sach doc gia\n");
    printf("2. Them doc gia\n");
    printf("3. Chinh sua doc gia\n");
    printf("4. Xoa doc gia\n");
    printf("5. Tim theo CMND\n");
    printf("6. Tim theo Ho ten\n");

    int c = nhap_so_nguyen("Chon: ", 1, 6);
    if (c == 1) get_danh_sach_doc_gia();
    if (c == 2) them_doc_gia();
    if (c == 3) cap_nhat_doc_gia();
    if (c == 4) xoa_doc_gia_bang_cmnd();
    if (c == 5) tim_doc_gia_bang_cmnd();
    if (c == 6) tim_doc_gia_bang_ho_va_ten();
}

static void xu_ly_quan_ly_sach() {
    printf("\n=== QUAN LY SACH ===\n");
    printf("1. Xem danh sach sach\n");
    printf("2. Them sach\n");
    printf("3. Chinh sua sach\n");
    printf("4. Xoa sach\n");
    printf("5. Tim theo ISBN\n");
    printf("6. Tim theo ten sach\n");

    int c = nhap_so_nguyen("Chon: ", 1, 6);
    if (c == 1) get_list_sach();
    if (c == 2) them_sach();
    if (c == 3) cap_nhat_sach();
    if (c == 4) xoa_sach();
    if (c == 5) tim_sach_theo_ISBN();
    if (c == 6) tim_sach_theo_tieu_de();
}

static void xu_ly_thong_ke() {
    printf("\n=== THONG KE ===\n");
    printf("1. Tong so luong sach\n");
    printf("2. Thong ke so luong sach theo the loai\n");
    printf("3. Tong so luong doc gia\n");
    printf("4. Thong ke doc gia theo gioi tinh\n");
    printf("5. Thong ke so sach dang duoc muon\n");
    printf("6. Danh sach doc gia bi tre han\n");

    int c = nhap_so_nguyen("Chon: ", 1, 6);
    if (c == 1) thong_ke_sach();
    if (c == 2) thong_ke_sach_theo_the_loai();
    if (c == 3) thong_ke_doc_gia();
    if (c == 4) thong_ke_doc_gia_theo_gioi_tinh();
    if (c == 5) thong_ke_sach_dang_muon();
    if (c == 6) danh_sach_doc_gia_tre_han();
}

int main() {
    khoi_tao_du_lieu_book();
    khoi_tao_du_lieu_reader();

    while(1) {
        printf("\n===== QUAN LI THU VIEN =====\n");
        printf("1. Quan li doc gia\n");
        printf("2. Quan li sach\n");
        printf("3. Lap phieu muon sach\n");
        printf("4. Lap phieu tra sach\n");
        printf("5. Cac thong ke co ban\n");
        printf("0. Thoat\n");

        int c = nhap_so_nguyen("Chon : ", 0, 5);
        if (c == 1) xu_ly_quan_ly_doc_gia();
        if (c == 2) xu_ly_quan_ly_sach();
        if (c == 3) lap_phieu_muon_sach();
        if (c == 4) lap_phieu_tra_sach();
        if (c == 5) xu_ly_thong_ke();
        if (c == 0) return 0;

        press_enter_to_continue();
    }
    return 0;
}