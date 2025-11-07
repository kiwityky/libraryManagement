#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "stats.h"
#include "book.data.h"
#include "reader.data.h"
#include "loan.h"
#include "loan.data.h"
#include "loan_return.h"
#include "utils.h"

static void chuyen_chuoi_thanh_chu_thuong(char* dest, const char* src, int max_len) {
    int i = 0;
    for (; src[i] != '\0' && i < max_len - 1; i++) {
        dest[i] = (char)tolower((unsigned char)src[i]);
    }
    dest[i] = '\0';
}

void thong_ke_sach() {
    long long total = 0;
    int i;
    for (i = 0; i < tong_so_luong_sach; i++) {
        total += g_sach_ban_sao[i];
    }
    printf("Tong so luong sach hien co: %lld\n", total);
}

void thong_ke_doc_gia() {
    printf("Tong so luong doc gia hien co: %d\n", tong_so_luong_doc_gia);
}

void thong_ke_doc_gia_theo_gioi_tinh() {
    int tong_nam = 0;
    int tong_nu = 0;
    for (int i = 0; i < tong_so_luong_doc_gia; i++) {
        char lower[16];
        chuyen_chuoi_thanh_chu_thuong(lower, gioi_tinh_at(i), sizeof(lower));
        if (strcmp(lower, "nam") == 0) {
            tong_nam++;
        } else if (strcmp(lower, "nu") == 0) {
            tong_nu++;
        }
    }
    printf("Tong so luong doc gia nam: %d\n", tong_nam);
    printf("Tong so luong doc gia nu: %d\n", tong_nu);
}

void thong_ke_sach_theo_the_loai() {
    printf("\n=== THONG KE SACH THEO THE LOAI ===\n\n");
    
    if (tong_so_luong_sach == 0) {
        printf("Hien tai chua co sach trong thu vien.\n");
        return;
    }
    
    const char* the_loai_list[] = {
        "Programming",
        "Database",
        "Web Development",
        "Software Design",
        "Testing",
        "Networking",
        "Security",
        "AI/Machine Learning",
        "Mobile Development"
    };
    int so_the_loai = 9;
    
    printf("%-30s | %-15s | %-15s\n", "THE LOAI", "SO DAU SACH", "TONG SO SACH");
    printf("------------------------------------------------------------------\n");
    
    int tong_the_loai_co_sach = 0;
    
    for (int i = 0; i < so_the_loai; i++) {
        int so_dau_sach = 0;
        int tong_so_sach_loai = 0;
        
        for (int j = 0; j < tong_so_luong_sach; j++) {
            if (strcmp(the_loai_sach_at(j), the_loai_list[i]) == 0) {
                so_dau_sach++;
                tong_so_sach_loai += g_sach_ban_sao[j];
            }
        }
        
        if (so_dau_sach > 0) {
            printf("%-30s | %-15d | %-15d\n", the_loai_list[i], so_dau_sach, tong_so_sach_loai);
            tong_the_loai_co_sach++;
        }
    }
    
    printf("------------------------------------------------------------------\n");
    printf("Tong so the loai co sach: %d\n", tong_the_loai_co_sach);
}

void danh_sach_doc_gia_tre_han() {
    printf("\n=== DANH SACH DOC GIA BI TRE HAN ===\n\n");
    
    if (tong_so_luong_phieu_muon == 0) {
        printf("Khong co phieu muon nao.\n");
        return;
    }
    
    int ngay_hien_tai, thang_hien_tai, nam_hien_tai;
    nhap_ngay_thang_nam("Nhap ngay hien tai", &ngay_hien_tai, &thang_hien_tai, &nam_hien_tai);
    printf("Ngay dang xem: %02d/%02d/%04d\n\n", ngay_hien_tai, thang_hien_tai, nam_hien_tai);
    
    printf("%-20s | %-15s | %-15s | %-15s | %-15s\n", 
           "HO TEN", "CMND", "NGAY MUON", "HAN TRA", "SO NGAY TRE");
    printf("-------------------------------------------------------------------------------------\n");
    
    int co_doc_gia_tre_han = 0;
    
    // Duyệt qua tất cả phiếu mượn
    for (int i = 0; i < tong_so_luong_phieu_muon; i++) {
        int so_sach_muon = g_phieu_muon_so_sach_muon[i];
        int co_sach_chua_tra = 0;
        
        // Kiểm tra xem có sách nào chưa trả không
        for (int j = 0; j < so_sach_muon; j++) {
            int idx_status = index_sach_trong_phieu_muon(i, j);
            if (g_phieu_muon_trang_thai_sach[idx_status] == 0) { // chưa trả
                co_sach_chua_tra = 1;
                break;
            }
        }
        
        if (!co_sach_chua_tra) {
            continue; // Bỏ qua nếu đã trả hết sách
        }
        
        // Tính số ngày chênh lệch giữa ngày hiện tại và ngày trả dự kiến
        int ngay_tra_du_kien = g_phieu_muon_ngay_tra[i];
        int thang_tra_du_kien = g_phieu_muon_thang_tra[i];
        int nam_tra_du_kien = g_phieu_muon_nam_tra[i];
        
        int so_ngay_tre = tinh_so_ngay_chenh_lech_gia_dinh_30(
            ngay_tra_du_kien, thang_tra_du_kien, nam_tra_du_kien,
            ngay_hien_tai, thang_hien_tai, nam_hien_tai
        );
        
        // Nếu trễ hạn (số ngày > 0)
        if (so_ngay_tre > 0) {
            printf("%-20s | %-15s | %02d/%02d/%04d      | %02d/%02d/%04d     | %d ngay\n",
                   phieu_muon_ho_ten_at(i),
                   phieu_muon_cmnd_at(i),
                   g_phieu_muon_ngay_muon[i],
                   g_phieu_muon_thang_muon[i],
                   g_phieu_muon_nam_muon[i],
                   ngay_tra_du_kien,
                   thang_tra_du_kien,
                   nam_tra_du_kien,
                   so_ngay_tre);
            co_doc_gia_tre_han = 1;
        }
    }
    
    if (!co_doc_gia_tre_han) {
        printf("Khong co doc gia nao bi tre han.\n");
    }
    
    printf("-------------------------------------------------------------------------------------\n");
}