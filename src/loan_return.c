#include <stdio.h>
#include <string.h>

#include "loan_return.h"
#include "loan.h"
#include "loan.data.h"
#include "reader.h"
#include "book.h"
#include "utils.h"

/*
 * Tính tiền phạt trễ hạn dựa trên số ngày trễ (mỗi tháng 30 ngày).
 */
int tinh_tien_phat_tre_han(int ngay_tra_du_kien, int thang_tra_du_kien, int nam_tra_du_kien,
                            int ngay_tra_thuc_te, int thang_tra_thuc_te, int nam_tra_thuc_te) {
    int so_ngay_tre = tinh_so_ngay_chenh_lech_gia_dinh_30(ngay_tra_du_kien, thang_tra_du_kien, nam_tra_du_kien,
                                                          ngay_tra_thuc_te, thang_tra_thuc_te, nam_tra_thuc_te);
    if (so_ngay_tre <= 0) {
        return 0; // Trả đúng hạn hoặc sớm
    }
    return so_ngay_tre * PHAT_TRE_HAN_MOI_NGAY;
}

int tinh_tien_phat_mat_sach(int gia_sach) {
    return gia_sach * PHAT_MAT_SACH_PERCENT / 100;
}

void lap_phieu_tra_sach() {
    printf("\n=== LAP PHIEU TRA SACH ===\n\n");

    if (tong_so_luong_phieu_muon == 0) {
        printf("Khong co phieu muon nao de tra.\n");
        return;
    }

    char cmnd[LENGTH_CMND];
    nhap_chuoi("Nhap CMND nguoi tra: ", cmnd, LENGTH_CMND);

    // Tìm phiếu mượn của độc giả
    int found = 0;
    for (int i = 0; i < tong_so_luong_phieu_muon; i++) {
        if (strcmp(phieu_muon_cmnd_at(i), cmnd) == 0) {
            printf("\n--- Phieu muon #%d ---\n", i + 1);
            printf("Nguoi muon: %s (CMND: %s)\n", phieu_muon_ho_ten_at(i), phieu_muon_cmnd_at(i));
            printf("Ngay muon: %d/%d/%d\n",
                   g_phieu_muon_ngay_muon[i],
                   g_phieu_muon_thang_muon[i],
                   g_phieu_muon_nam_muon[i]);
            printf("Ngay tra du kien: %d/%d/%d\n",
                   g_phieu_muon_ngay_tra[i],
                   g_phieu_muon_thang_tra[i],
                   g_phieu_muon_nam_tra[i]);
            printf("So sach muon: %d\n", g_phieu_muon_so_sach_muon[i]);

            // Hiển thị danh sách sách đã mượn
            printf("\nDanh sach sach:\n");
            for (int j = 0; j < g_phieu_muon_so_sach_muon[i]; j++) {
                char* isbn = index_isbn_trong_list_sach_muon(i, j);
                int status = g_phieu_muon_trang_thai_sach[index_sach_trong_phieu_muon(i, j)];

                if (status == 0) { // Chưa trả
                    printf("  %d. ISBN: %s [CHUA TRA]\n", j + 1, isbn);
                } else if (status == 1) {
                    printf("  %d. ISBN: %s [DA TRA]\n", j + 1, isbn);
                } else if (status == 2) {
                    printf("  %d. ISBN: %s [MAT SACH]\n", j + 1, isbn);
                }
            }

            // Hỏi có muốn trả sách không
            int tra_sach = nhap_so_nguyen("\nTra sach cua phieu nay? (1=Co, 0=Khong): ", 0, 1);
            if (tra_sach == 0) {
                continue;
            }

            // Nhập ngày trả thực tế
            int ngay_tra_thuc_te, thang_tra_thuc_te, nam_tra_thuc_te;
            nhap_ngay_thang_nam("Ngay tra thuc te",
                               &ngay_tra_thuc_te, &thang_tra_thuc_te, &nam_tra_thuc_te);

            int tong_tien_phat = 0;

            // Xử lý từng sách
            for (int j = 0; j < g_phieu_muon_so_sach_muon[i]; j++) {
                int idx_status = index_sach_trong_phieu_muon(i, j);

                if (g_phieu_muon_trang_thai_sach[idx_status] != 0) {
                    continue; // Đã xử lý rồi
                }

                printf("\nSach %d (ISBN: %s):\n", j + 1, index_isbn_trong_list_sach_muon(i, j));
                printf("1. Tra sach binh thuong\n");
                printf("2. Sach bi mat\n");
                int lua_chon = nhap_so_nguyen("Lua chon: ", 1, 2);

                char* isbn = index_isbn_trong_list_sach_muon(i, j);
                int index_sach = tim_sach_bang_ISBN(isbn);

                if (lua_chon == 1) {
                    // Trả sách bình thường - kiểm tra trễ hạn
                    int tien_phat = tinh_tien_phat_tre_han(
                        g_phieu_muon_ngay_tra[i], g_phieu_muon_thang_tra[i], g_phieu_muon_nam_tra[i],
                        ngay_tra_thuc_te, thang_tra_thuc_te, nam_tra_thuc_te
                    );

                    if (tien_phat > 0) {
                        printf("  → Tre han! Phat: %d dong\n", tien_phat);
                        tong_tien_phat += tien_phat;
                    } else {
                        printf("  → Tra dung han\n");
                    }

                    // Đánh dấu đã trả
                    g_phieu_muon_trang_thai_sach[idx_status] = 1;

                    // Tăng số sách có sẵn
                    if (index_sach != -1) {
                        g_sach_ban_sao_co_san[index_sach]++;
                    }

                } else if (lua_chon == 2) {
                    // Sách bị mất
                    if (index_sach != -1) {
                        int tien_phat_mat = tinh_tien_phat_mat_sach(g_sach_gia[index_sach]);
                        printf("  → Mat sach! Phat: %d dong (200%% gia sach)\n", tien_phat_mat);
                        tong_tien_phat += tien_phat_mat;

                        // Kiểm tra trễ hạn (nếu mất sách vẫn tính trễ)
                        int tien_phat_tre = tinh_tien_phat_tre_han(
                            g_phieu_muon_ngay_tra[i], g_phieu_muon_thang_tra[i], g_phieu_muon_nam_tra[i],
                            ngay_tra_thuc_te, thang_tra_thuc_te, nam_tra_thuc_te
                        );
                        if (tien_phat_tre > 0) {
                            printf("  → Them phat tre han: %d dong\n", tien_phat_tre);
                            tong_tien_phat += tien_phat_tre;
                        }
                    }

                    // Đánh dấu mất sách
                    g_phieu_muon_trang_thai_sach[idx_status] = 2;
                }
            }

            printf("\n=================================\n");
            printf("TONG TIEN PHAT: %d dong\n", tong_tien_phat);
            printf("=================================\n");

            tong_so_luong_phieu_tra++;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay phieu muon cua doc gia voi CMND nay.\n");
    }
}
