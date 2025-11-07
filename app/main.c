#include <stdio.h>

#include "core/members.h"
#include "core/books.h"
#include "core/loans.h"
#include "core/reports.h"
#include "data/members_mem.h"
#include "data/books_mem.h"
#include "data/loans_mem.h"
#include "helpers/input.h"

/**
 * Chức năng: Hiển thị và xử lý các tùy chọn quản lý thành viên.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
static void member_menu() {
    int choice;
    do {
        printf("\n👤━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("🧑‍🤝‍🧑 QUẢN LÝ THÀNH VIÊN\n");
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("1️⃣  Thêm thành viên mới\n");
        printf("2️⃣  Cập nhật thông tin\n");
        printf("3️⃣  Xóa theo CMND\n");
        printf("4️⃣  Xem danh sách\n");
        printf("5️⃣  Tìm theo mã thẻ\n");
        printf("6️⃣  Tìm theo CMND\n");
        printf("7️⃣  Tìm theo họ tên\n");
        printf("8️⃣  Gia hạn thẻ (nhập số tháng tùy ý)\n");
        printf("9️⃣  Cảnh báo thẻ sắp hết hạn\n");
        printf("0️⃣  🔙 Quay lại\n");
        choice = read_number("Lựa chọn: ", 0, 9);
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

/**
 * Chức năng: Hiển thị và xử lý các tùy chọn quản lý sách.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
static void book_menu() {
    int choice;
    do {
        printf("\n📚━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("📘 QUẢN LÝ SÁCH\n");
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("1️⃣  Thêm sách mới\n");
        printf("2️⃣  Cập nhật thông tin sách\n");
        printf("3️⃣  Xóa sách\n");
        printf("4️⃣  Danh mục sách\n");
        printf("5️⃣  Tìm theo ISBN\n");
        printf("6️⃣  Tìm theo tiêu đề\n");
        printf("0️⃣  🔙 Quay lại\n");
        choice = read_number("Lựa chọn: ", 0, 6);
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

/**
 * Chức năng: Hiển thị và xử lý các tùy chọn mượn trả sách.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
static void loan_menu() {
    int choice;
    do {
        printf("\n📖━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("📥 MƯỢN / TRẢ SÁCH\n");
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("1️⃣  Lập phiếu mượn\n");
        printf("2️⃣  Lập phiếu trả\n");
        printf("3️⃣  Thống kê sách đang mượn\n");
        printf("0️⃣  🔙 Quay lại\n");
        choice = read_number("Lựa chọn: ", 0, 3);
        switch (choice) {
            case 1: create_loan_ticket(); break;
            case 2: process_return_ticket(); break;
            case 3: show_borrowed_overview(); break;
            default: break;
        }
    } while (choice != 0);
}

/**
 * Chức năng: Hiển thị và xử lý các báo cáo thống kê.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
static void report_menu() {
    int choice;
    do {
        printf("\n📊━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("🧾 BÁO CÁO THỐNG KÊ\n");
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("1️⃣  Tổng quan thư viện\n");
        printf("2️⃣  Thống kê độc giả theo giới tính\n");
        printf("3️⃣  Thống kê thể loại sách\n");
        printf("4️⃣  Danh sách độc giả trễ hạn\n");
        printf("5️⃣  Sách chưa trả\n");
        printf("0️⃣  🔙 Quay lại\n");
        choice = read_number("Lựa chọn: ", 0, 5);
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

/**
 * Chức năng: Điểm vào chương trình và điều phối các menu chính.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - Mã thoát chương trình (0 khi thành công).
 */
int main() {
    reset_member_store();
    reset_book_store();
    reset_loan_store();

    int choice;
    do {
        printf("\n🏛️━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("📚 TRÌNH QUẢN LÝ THƯ VIỆN\n");
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("1️⃣  Quản lý thành viên\n");
        printf("2️⃣  Quản lý sách\n");
        printf("3️⃣  Mượn / Trả sách\n");
        printf("4️⃣  Báo cáo thống kê\n");
        printf("0️⃣  🔚 Thoát\n");
        choice = read_number("Lựa chọn: ", 0, 4);
        switch (choice) {
            case 1: member_menu(); break;
            case 2: book_menu(); break;
            case 3: loan_menu(); break;
            case 4: report_menu(); break;
            default: break;
        }
    } while (choice != 0);

    printf("Tạm biệt! 👋\n");
    return 0;
}
