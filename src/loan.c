#include <stdio.h>
#include <string.h>

#include "loan.h"
#include "loan.data.h"
#include "reader.h"
#include "book.h"
#include "utils.h"

/*
 * Thống kê số sách hiện đang được mượn (chưa trả).
 */
void thong_ke_sach_dang_muon() {
    printf("\n=== THONG KE SACH DANG DUOC MUON ===\n\n");
    
    if (tong_so_luong_phieu_muon == 0) {
        printf("Khong co phieu muon nao.\n");
        return;
    }
    
    int tong_sach_dang_muon = 0;
    
    // Duyệt qua tất cả phiếu mượn
    for (int i = 0; i < tong_so_luong_phieu_muon; i++) {
        int so_sach_muon = g_phieu_muon_so_sach_muon[i];
        
        // Duyệt qua từng sách trong phiếu mượn
        for (int j = 0; j < so_sach_muon; j++) {
            int idx_status = index_sach_trong_phieu_muon(i, j);
            
            // Kiểm tra trạng thái: 0 = chưa trả, 1 = đã trả, 2 = mất sách
            if (g_phieu_muon_trang_thai_sach[idx_status] == 0) {
                tong_sach_dang_muon++;
            }
        }
    }
    
    printf("Tong so sach dang duoc muon (chua tra): %d\n", tong_sach_dang_muon);
}

/*
 * Lập phiếu mượn sách mới.
 */
void lap_phieu_muon_sach() {
    printf("\n=== LAP PHIEU MUON SACH ===\n\n");
    if (tong_so_luong_phieu_muon >= MAX_SO_LUONG_PHIEU_MUON) {
        printf("Khong the lap phieu muon sach, so luong phieu muon da toi gioi han.");
        return;
    }

    char cmnd[LENGTH_CMND];
    nhap_chuoi("Nhap CMND nguoi muon: ", cmnd, LENGTH_CMND);
    int index_nguoi_muon = tim_doc_gia_by_cmnd(cmnd);
    if (index_nguoi_muon == -1) {
        printf("Khong tim thay doc gia voi CMND.\n");
        return;
    }

    int ngay_muon, thang_muon, nam_muon;
    nhap_ngay_thang_nam("Ngay muon sach", &ngay_muon, &thang_muon, &nam_muon);
    int ngay_tra, thang_tra, nam_tra;
    cong_ngay_gia_dinh_30(ngay_muon, thang_muon, nam_muon, 7,
                          &ngay_tra, &thang_tra, &nam_tra);

    int index_phieu_muon = tong_so_luong_phieu_muon;
    luu_du_lieu_vao_vung_nho(phieu_muon_cmnd_at(index_phieu_muon), cmnd);
    luu_du_lieu_vao_vung_nho(phieu_muon_ho_ten_at(index_phieu_muon), ho_va_ten_at(index_nguoi_muon));
    g_phieu_muon_ngay_muon[index_phieu_muon] = ngay_muon;
    g_phieu_muon_thang_muon[index_phieu_muon] = thang_muon;
    g_phieu_muon_nam_muon[index_phieu_muon] = nam_muon;
    g_phieu_muon_ngay_tra[index_phieu_muon] = ngay_tra;
    g_phieu_muon_thang_tra[index_phieu_muon] = thang_tra;
    g_phieu_muon_nam_tra[index_phieu_muon] = nam_tra;
    g_phieu_muon_so_sach_muon[index_phieu_muon] = 0;

    int so_luong_sach_can_muon = nhap_so_nguyen("So sach can muon (1-5): ", 1, 5);
    
    for (int i = 0; i < so_luong_sach_can_muon; i++)  {
        char ma_sach[LENGTH_ISBN];
        nhap_chuoi("Nhap ma sach can muon: ", ma_sach, LENGTH_ISBN);
        // check sách có trong thư viện không
        int index_sach_muon = tim_sach_bang_ISBN(ma_sach);
        if (index_sach_muon == -1) {
            printf("Khong tim thay sach voi ma ISBN.\n");
            continue;
        }
        // check còn sách để mượn không
        if (g_sach_ban_sao_co_san[index_sach_muon] <= 0) {
            printf("Sach can muon khong con trong thu vien. Vui long chon sach khac.");
            continue;
        }

        int index_cua_sach_trong_list = g_phieu_muon_so_sach_muon[index_phieu_muon];
        luu_du_lieu_vao_vung_nho(index_isbn_trong_list_sach_muon(index_phieu_muon, index_cua_sach_trong_list), ma_sach);
        
        g_phieu_muon_trang_thai_sach[index_sach_trong_phieu_muon(index_phieu_muon, index_cua_sach_trong_list)] = 0;
        // trừ đi số  sách có sẵn
        g_sach_ban_sao_co_san[index_sach_muon]--;

        // số lượng sách mượn trong phiếu mượn
        g_phieu_muon_so_sach_muon[index_phieu_muon]++;
   
    }
    // cộng thêm số lượng phiếu mượn
    tong_so_luong_phieu_muon++;
    printf("Tao phieu muon thanh cong!");
}

int index_sach_trong_phieu_muon(int index_phieu_muon, int index_cua_sach_trong_list) {
    return index_phieu_muon * 5 + index_cua_sach_trong_list;
}



