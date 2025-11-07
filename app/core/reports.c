#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "reports.h"
#include "../data/books_mem.h"
#include "../data/members_mem.h"
#include "../data/loans_mem.h"
#include "../helpers/date.h"
#include "../helpers/input.h"
#include "loans.h"

/**
 * Chức năng: Thống kê số liệu tổng quan về thư viện.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void report_library_numbers() {
    printf("\n===== TONG QUAN THU VIEN =====\n\n");
    long long total_copies = 0;
    for (int i = 0; i < book_count; i++) {
        total_copies += book_total_copy[i];
    }
    printf("So dau sach: %d\n", book_count);
    printf("Tong so ban in: %lld\n", total_copies);
    printf("So thanh vien: %d\n", member_count);
}

/**
 * Chức năng: Đếm số độc giả theo giới tính nam và nữ.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void report_member_by_gender() {
    printf("\n===== THONG KE GIOI TINH =====\n\n");
    int male = 0;
    int female = 0;
    for (int i = 0; i < member_count; i++) {
        char gender[MEMBER_GENDER_LEN];
        copy_text(gender, member_gender_at(i), MEMBER_GENDER_LEN);
        for (int j = 0; gender[j] != '\0'; j++) {
            gender[j] = (char)tolower((unsigned char)gender[j]);
        }
        if (strcmp(gender, "nam") == 0) {
            male++;
        } else if (strcmp(gender, "nu") == 0) {
            female++;
        }
    }
    printf("Doc gia nam: %d\n", male);
    printf("Doc gia nu: %d\n", female);
}

/**
 * Chức năng: Thống kê số đầu sách và số bản in theo từng thể loại.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void report_books_by_category() {
    printf("\n===== THONG KE THE LOAI =====\n\n");
    if (book_count == 0) {
        printf("Chua co sach trong thu vien.\n");
        return;
    }
    const char *categories[] = {
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
    int cat_count = sizeof(categories) / sizeof(categories[0]);
    printf("%-24s | %-12s | %-12s\n", "The loai", "Dau sach", "So ban");
    printf("--------------------------------------------------------------\n");
    for (int c = 0; c < cat_count; c++) {
        int titles = 0;
        int copies = 0;
        for (int i = 0; i < book_count; i++) {
            if (strcmp(book_category_at(i), categories[c]) == 0) {
                titles++;
                copies += book_total_copy[i];
            }
        }
        if (titles > 0) {
            printf("%-24s | %-12d | %-12d\n", categories[c], titles, copies);
        }
    }
}

/**
 * Chức năng: Liệt kê các độc giả đang trả sách trễ hạn và số ngày quá hạn.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void report_overdue_readers() {
    printf("\n===== DOC GIA TRE HAN =====\n\n");
    if (loan_count == 0) {
        printf("Chua co phieu muon nao.\n");
        return;
    }
    int today_day, today_month, today_year;
    read_date_prompt("Ngay hien tai", &today_day, &today_month, &today_year);
    printf("%-24s | %-12s | %-10s | %-10s | %-10s\n",
           "Ho ten", "CMND", "Ngay muon", "Han tra", "Ngay tre");
    printf("--------------------------------------------------------------------------\n");
    int shown = 0;
    for (int i = 0; i < loan_count; i++) {
        int pending = 0;
        for (int j = 0; j < loan_books_amount()[i]; j++) {
            int pos = loan_item_position(i, j);
            if (loan_item_status()[pos] == 0) {
                pending = 1;
                break;
            }
        }
        if (!pending) {
            continue;
        }
        int diff = difference_days_30(loan_due_day[i], loan_due_month[i], loan_due_year[i],
                                      today_day, today_month, today_year);
        if (diff <= 0) {
            continue;
        }
        printf("%-24s | %-12s | %02d/%02d/%04d | %02d/%02d/%04d | %-10d\n",
               loan_member_name_at(i),
               loan_idcard_at(i),
               loan_borrow_day[i], loan_borrow_month[i], loan_borrow_year[i],
               loan_due_day[i], loan_due_month[i], loan_due_year[i],
               diff);
        shown = 1;
    }
    if (!shown) {
        printf("Khong co doc gia tre han.\n");
    }
}

/**
 * Chức năng: Báo cáo tổng số sách chưa trả trong thư viện.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void report_active_loans() {
    printf("\n===== SACH CHUA TRA =====\n\n");
    int total = count_unreturned_books();
    printf("Tong so sach dang duoc muon: %d\n", total);
}
