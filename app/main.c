#include <stdio.h>

#include "core/members.h"
#include "core/books.h"
#include "core/loans.h"
#include "core/reports.h"
#include "data/members_mem.h"
#include "data/books_mem.h"
#include "data/loans_mem.h"
#include "helpers/input.h"

//Chức năng: Hiển thị và xử lý các tùy chọn quản lý thành viên.
static void member_menu() {
    int choice;
    do {
        printf("\n----------------------------------------------\n");
        printf("QUAN LY THANH VIEN\n");
        printf("----------------------------------------------\n");
        printf("1.  Them thanh vien moi\n");
        printf("2.  Cap nhat thong tin\n");
        printf("3.  Xoa theo CMND\n");
        printf("4.  Xem danh sach\n");
        printf("5.  Tim theo ma the\n");
        printf("6.  Tim theo CMND\n");
        printf("7.  Tim theo ho ten\n");
        printf("8.  Gia han the (nhap so thang tuy y)\n");
        printf("9.  Canh bao the sap het han\n");
        printf("0.  Quay lai\n");
        choice = read_number("Lua chon: ", 0, 9);
        switch (choice) {
            case 1: create_member_record(); break;
            case 2: update_member_record(); break;
            case 3: remove_member_by_idcard(); break;
            case 4: show_all_members(); break;
            case 5: find_member_via_code(); break;
            case 6: find_member_via_idcard(); break;
            case 7: find_member_via_name(); break;
            case 8: extend_member_card(); break;
            case 9: announce_expiring_cards(); break;
            default: break;
        }
    } while (choice != 0);
}

//Chức năng: Hiển thị và xử lý các tùy chọn quản lý sách.
static void book_menu() {
    int choice;
    do {
        printf("\n----------------------------------------------\n");
        printf("QUAN LY SACH\n");
        printf("----------------------------------------------\n");
        printf("1.  Them sach moi\n");
        printf("2.  Cap nhat thong tin sach\n");
        printf("3.  Xoa sach\n");
        printf("4.  Danh muc sach\n");
        printf("5.  Tim theo ISBN\n");
        printf("6.  Tim theo tieu de\n");
        printf("0.  Quay lai\n");
        choice = read_number("Lua chon: ", 0, 6);
        switch (choice) {
            case 1: add_book_entry(); break;
            case 2: update_book_entry(); break;
            case 3: remove_book_by_isbn(); break;
            case 4: list_books(); break;
            case 5: search_book_by_isbn(); break;
            case 6: search_book_by_title(); break;
            default: break;
        }
    } while (choice != 0);
}

//Chức năng: Hiển thị và xử lý các tùy chọn mượn trả sách.
static void loan_menu() {
    int choice;
    do {
        printf("\n----------------------------------------------\n");
        printf("MUON / TRA SACH\n");
        printf("----------------------------------------------\n");
        printf("1.  Lap phieu muon\n");
        printf("2.  Lap phieu tra\n");
        printf("3.  Thong ke sach dang muon\n");
        printf("0.  Quay lai\n");
        choice = read_number("Lua chon: ", 0, 3);
        switch (choice) {
            case 1: create_loan_ticket(); break;
            case 2: process_return_ticket(); break;
            case 3: show_borrowed_overview(); break;
            default: break;
        }
    } while (choice != 0);
}

//Chức năng: Hiển thị và xử lý các báo cáo thống kê.
static void report_menu() {
    int choice;
    do {
        printf("\n----------------------------------------------\n");
        printf("BAO CAO THONG KE\n");
        printf("----------------------------------------------\n");
        printf("1.  Tong quan thu vien\n");
        printf("2.  Thong ke doc gia theo gioi tinh\n");
        printf("3.  Thong ke the loai sach\n");
        printf("4.  Danh sach doc gia tre han\n");
        printf("5.  Sach chua tra\n");
        printf("0.  Quay lai\n");
        choice = read_number("Lua chon: ", 0, 5);
        switch (choice) {
            case 1: report_library_numbers(); break;
            case 2: report_member_by_gender(); break;
            case 3: report_books_by_category(); break;
            case 4: report_overdue_readers(); break;
            case 5: report_active_loans(); break;
            default: break;
        }
    } while (choice != 0);
}

/**Chức năng: Điểm vào chương trình và điều phối các menu chính.
 * Giá trị trả về: Mã thoát chương trình (0 khi thành công).*/
int main() {
    reset_member_store();
    reset_book_store();
    reset_loan_store();

    int choice;
    do {
        printf("\n----------------------------------------------\n");
        printf("TRINH QUAN LY THU VIEN\n");
        printf("----------------------------------------------\n");
        printf("1.  Quan ly thanh vien\n");
        printf("2.  Quan ly sach\n");
        printf("3.  Muon / Tra sach\n");
        printf("4.  Bao cao thong ke\n");
        printf("0.  Thoat\n");
        choice = read_number("Lua chon: ", 0, 4);
        switch (choice) {
            case 1: member_menu(); break;
            case 2: book_menu(); break;
            case 3: loan_menu(); break;
            case 4: report_menu(); break;
            default: break;
        }
    } while (choice != 0);

    printf("Tam biet! \n");
    return 0;
}
