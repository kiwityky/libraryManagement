#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "book.h"

/*
 * In tiêu đề bảng sách với định dạng cột cố định.
 */
static void in_tieu_de_bang_sach() {
    printf("%-3s | %-18s | %-28s | %-22s | %-18s | %-6s | %-18s | %-8s | %-8s\n",
           "#", "ISBN", "Tieu de", "Tac gia", "NXB", "Nam", "The loai", "Tong", "Con");
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
}

/*
 * In thông tin một sách theo định dạng cột.
 */
void print_sach_theo_hang(int i) {
    printf("%-3d | %-18s | %-28s | %-22s | %-18s | %-6d | %-18s | %-8d | %-8d\n",
           i + 1,
           isbn_sach_at(i),
           tieu_de_sach_at(i),
           tac_gia_sach_at(i),
           nxb_sach_at(i),
           g_sach_nam_xuat_ban[i],
           the_loai_sach_at(i),
           g_sach_ban_sao[i],
           g_sach_ban_sao_co_san[i]);
}

/*
 * Hiển thị toàn bộ danh sách sách.
 */
void get_list_sach() {
    printf("\n=== DANH SACH CAC DAU SACH ===\n\n");
    printf("Tong so dau sach: %d\n\n", tong_so_luong_sach);

    if (tong_so_luong_sach == 0) {
        printf("Thu vien chua co sach nao.\n");
        return;
    }

    in_tieu_de_bang_sach();
    for (int i = 0; i < tong_so_luong_sach; i++) {
        print_sach_theo_hang(i);
    }
}

/*
 * Thêm sách mới vào thư viện.
 */
int them_sach() {
    printf("\n=== THEM SACH VAO THU VIEN ===\n\n");
    if (tong_so_luong_sach >= MAX_SO_LUONG_SACH) {
        printf("Khong the them sach vao thu vien, so luong sach da toi gioi han.");
        return 0;
    }
    // nhập ISBN với kiểm tra trùng lặp
    char isbn[LENGTH_ISBN];
    int isbn_valid = 0;
    while (!isbn_valid) {
        nhap_chuoi("ISBN: ", isbn, LENGTH_ISBN);
        isbn_valid = validate_sach_by_isbn(isbn);
    }
    char tieu_de[LENGTH_TIEU_DE];
    nhap_chuoi("Tieu de: ", tieu_de, LENGTH_TIEU_DE);
    char tac_gia[LENGTH_TAC_GIA];
    nhap_chuoi("Tac gia: ", tac_gia, LENGTH_TAC_GIA);
    char nha_xuat_ban[LENGTH_NXB];
    nhap_chuoi("Nha xuat ban: ", nha_xuat_ban, LENGTH_NXB);
    int year = nhap_so_nguyen("Nam xuat ban: ", 1, 9999);
    char the_loai[LENGTH_THE_LOAI];
    chon_the_loai_sach(the_loai);
    int gia = nhap_so_nguyen("Gia: ", 0, 999999999);
    int so_luong = nhap_so_nguyen("So luong: ", 0, 99999999);

    // lưu từng mục thông tin của sách vào array chứa dữ liệu của từng loại
    int i = tong_so_luong_sach;
    luu_du_lieu_vao_vung_nho(isbn_sach_at(i), isbn);
    luu_du_lieu_vao_vung_nho(tieu_de_sach_at(i), tieu_de);
    luu_du_lieu_vao_vung_nho(tac_gia_sach_at(i), tac_gia);
    luu_du_lieu_vao_vung_nho(nxb_sach_at(i), nha_xuat_ban);
    luu_du_lieu_vao_vung_nho(the_loai_sach_at(i), the_loai);
    g_sach_nam_xuat_ban[i] = year;
    g_sach_gia[i] = gia;
    g_sach_ban_sao[i] = so_luong;
    g_sach_ban_sao_co_san[i] = so_luong;

    tong_so_luong_sach++;
    printf("Them sach vao thu vien thanh cong!\n\n");
    return 1;

}

/*
 * Xóa sách khỏi thư viện dựa vào ISBN.
 */
void xoa_sach() {
    char isbn[LENGTH_ISBN];
    nhap_chuoi("Nhap ISBN can xoa: ", isbn, LENGTH_ISBN);
    int index_cua_sach = tim_sach_bang_ISBN(isbn);
    if (index_cua_sach == -1) {
        printf("Khong tim thay sach voi ISBN.\n");
        return;
    }
    int i;
    for (i = index_cua_sach + 1; i < tong_so_luong_sach; i++) {
        int index_moi = i - 1;
        luu_du_lieu_vao_vung_nho(isbn_sach_at(index_moi), isbn_sach_at(i));
        luu_du_lieu_vao_vung_nho(tieu_de_sach_at(index_moi), tieu_de_sach_at(i));
        luu_du_lieu_vao_vung_nho(tac_gia_sach_at(index_moi), tac_gia_sach_at(i));
        luu_du_lieu_vao_vung_nho(nxb_sach_at(index_moi), nxb_sach_at(i));
        luu_du_lieu_vao_vung_nho(the_loai_sach_at(index_moi), the_loai_sach_at(i));
        g_sach_nam_xuat_ban[index_moi] = g_sach_nam_xuat_ban[i];
        g_sach_gia[index_moi] = g_sach_gia[i];
        g_sach_ban_sao[index_moi] = g_sach_ban_sao[i];
        g_sach_ban_sao_co_san[index_moi] = g_sach_ban_sao_co_san[i];
    }
    tong_so_luong_sach--;
    printf("\nDa xoa sach ISBN %s thanh cong\n\n", isbn);
}

/*
 * Cập nhật thông tin sách theo lựa chọn.
 */
void cap_nhat_sach() {
    char isbn[LENGTH_ISBN];
    nhap_chuoi("Nhap ISBN can cap nhat: ", isbn, LENGTH_ISBN);
    int index_cua_sach = tim_sach_bang_ISBN(isbn);
    if (index_cua_sach == -1) {
        printf("Khong tim thay sach voi ISBN.\n");
        return;
    }
    print_sach_theo_hang(index_cua_sach);
    printf("Chon muc can cap nhat:\n");
    printf("1. Tieu de\n2. Tac gia\n3. Nha xuat ban\n4. Nam xuat ban\n5. The loai\n6. Gia\n7. Tong so luong\n");
    int option = nhap_so_nguyen("Lua chon cua ban: ", 1, 7);

    if (option == 1) {
        char tieu_de_moi[LENGTH_TIEU_DE];
        nhap_chuoi("Tieu de moi: ", tieu_de_moi, LENGTH_TIEU_DE );
        luu_du_lieu_vao_vung_nho(tieu_de_sach_at(index_cua_sach), tieu_de_moi);
    }
    if (option == 2) {
        char tac_gia_moi[LENGTH_TAC_GIA];
        nhap_chuoi("Tac gia moi: ", tac_gia_moi, LENGTH_TAC_GIA);
        luu_du_lieu_vao_vung_nho(tac_gia_sach_at(index_cua_sach), tac_gia_moi);
    }
    if (option == 3) {
        char nxb_moi[LENGTH_NXB];
        nhap_chuoi("Nha xuat ban moi: ", nxb_moi, LENGTH_NXB);
        luu_du_lieu_vao_vung_nho(nxb_sach_at(index_cua_sach), nxb_moi);
    }
    if (option == 4) {
        int nam_xuat_ban_moi = nhap_so_nguyen("Nam xuat ban moi: ", 1, 9999);
        g_sach_nam_xuat_ban[index_cua_sach] = nam_xuat_ban_moi;
    }
    if (option == 5) {
        char the_loai_moi[LENGTH_THE_LOAI];
        chon_the_loai_sach(the_loai_moi);
        luu_du_lieu_vao_vung_nho(the_loai_sach_at(index_cua_sach), the_loai_moi);
    }
    if (option == 6) {
        int gia_moi = nhap_so_nguyen("Gia moi: ", 0, 999999999);
        g_sach_gia[index_cua_sach] = gia_moi;
    }
    if (option == 7) {
        int so_luong_moi = nhap_so_nguyen("So luong moi: ", 0, 99999999);
        int so_sach_dang_muon = g_sach_ban_sao[index_cua_sach] - g_sach_ban_sao_co_san[index_cua_sach];
        if (so_sach_dang_muon < 0) so_sach_dang_muon = 0;
        g_sach_ban_sao[index_cua_sach] = so_luong_moi;
        int so_con_lai = so_luong_moi - so_sach_dang_muon;
        if (so_con_lai < 0) so_con_lai = 0;
        g_sach_ban_sao_co_san[index_cua_sach] = so_con_lai;
    }
    printf("\nDa cap nhat sach isbn %s thanh cong\n\n", isbn);
}

/*
 * Tìm sách theo ISBN và hiển thị.
 */
void tim_sach_theo_ISBN() {
    char isbn[LENGTH_ISBN];
    nhap_chuoi("Nhap ISBN can tim: ", isbn, LENGTH_ISBN);
    int index_cua_sach = tim_sach_bang_ISBN(isbn);
    if (index_cua_sach == -1) {
        printf("Khong tim thay sach voi ISBN.\n");
        return;
    }
    print_sach_theo_hang(index_cua_sach);
}

/*
 * Tìm sách theo tiêu đề.
 */
void tim_sach_theo_tieu_de() {
    char tieu_de[LENGTH_TIEU_DE];
    nhap_chuoi("Nhap tieu de sach can tim: ", tieu_de, LENGTH_TIEU_DE);
    int index_cua_sach = tim_sach_bang_tieu_de(tieu_de);
    if (index_cua_sach == -1) {
        printf("Khong tim thay sach voi tieu de %s.\n", tieu_de);
        return;
    }
    print_sach_theo_hang(index_cua_sach);
}

/*
 * Trả về chỉ số của sách thông qua ISBN.
 */
int tim_sach_bang_ISBN(const char* isbn) {
    int i;
    for (i = 0; i < tong_so_luong_sach; i++) {
        if (strcmp(isbn_sach_at(i), isbn) == 0) {
            return i;
        }
    }
    return -1;
}

/*
 * Trả về chỉ số sách theo tiêu đề.
 */
int tim_sach_bang_tieu_de(const char* tieu_de) {
    int i;
       for (i = 0; i < tong_so_luong_sach; i++) {
        if (strcmp(tieu_de_sach_at(i), tieu_de) == 0) {
            return i;
        }
    }
    return -1;
}

/*
 * Kiểm tra ISBN đã tồn tại hay chưa.
 */
int validate_sach_by_isbn(const char* isbn) {
    int result = tim_sach_bang_ISBN(isbn);

    if (result != -1) {
        printf("------------------------------\n");
        printf("Loi: ISBN cua sach da ton tai.\n");
        printf("Vui long nhap ISBN khac.\n");
        printf("------------------------------\n");
        return 0;
    }
    return 1;
}

/*
 * Cập nhật số lượng sách còn lại dựa trên tổng số và số đang mượn.
 */
void cap_nhat_so_luong_sach_co_san(int index) {
    int so_sach_dang_muon = g_sach_ban_sao[index] - g_sach_ban_sao_co_san[index];
    if (so_sach_dang_muon < 0) so_sach_dang_muon = 0;
    int so_con_lai = g_sach_ban_sao[index] - so_sach_dang_muon;
    if (so_con_lai < 0) so_con_lai = 0;
    g_sach_ban_sao_co_san[index] = so_con_lai;
}

/*
 * Chọn thể loại sách từ danh sách có sẵn.
 */
void chon_the_loai_sach(char* the_loai_output) {
    printf("\n=== CHON THE LOAI SACH ===\n");
    printf("1. Programming (Lap trinh)\n");
    printf("2. Database (Co so du lieu)\n");
    printf("3. Web Development (Phat trien Web)\n");
    printf("4. Software Design (Thiet ke phan mem)\n");
    printf("5. Testing (Kiem thu)\n");
    printf("6. Networking (Mang may tinh)\n");
    printf("7. Security (Bao mat)\n");
    printf("8. AI/Machine Learning (Tri tue nhan tao)\n");
    printf("9. Mobile Development (Phat trien ung dung di dong)\n");
    printf("10. Other (Khac)\n");
    
    int choice = nhap_so_nguyen("Chon the loai (1-10): ", 1, 10);
    
    switch (choice) {
        case 1:
            strcpy(the_loai_output, "Programming");
            break;
        case 2:
            strcpy(the_loai_output, "Database");
            break;
        case 3:
            strcpy(the_loai_output, "Web Development");
            break;
        case 4:
            strcpy(the_loai_output, "Software Design");
            break;
        case 5:
            strcpy(the_loai_output, "Testing");
            break;
        case 6:
            strcpy(the_loai_output, "Networking");
            break;
        case 7:
            strcpy(the_loai_output, "Security");
            break;
        case 8:
            strcpy(the_loai_output, "AI/Machine Learning");
            break;
        case 9:
            strcpy(the_loai_output, "Mobile Development");
            break;
        case 10:
            printf("Nhap the loai khac: ");
            nhap_chuoi("", the_loai_output, LENGTH_THE_LOAI);
            break;
        default:
            strcpy(the_loai_output, "Unknown");
            break;
    }
    printf("Da chon the loai: %s\n", the_loai_output);
}