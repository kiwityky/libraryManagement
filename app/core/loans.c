#include <stdio.h>
#include <string.h>

#include "loans.h"
#include "members.h"
#include "books.h"
#include "fines.h"
#include "../helpers/input.h"
#include "../helpers/date.h"

void create_loan_ticket() {
    printf("\n===== LAP PHIEU MUON =====\n\n");
    if (loan_count >= LOAN_CAPACITY) {
        printf("Khong the lap phieu muon moi.\n");
        return;
    }
    char idcard[MEMBER_IDCARD_LEN];
    read_text("CMND nguoi muon: ", idcard, MEMBER_IDCARD_LEN);
    int member_index = locate_member_by_idcard(idcard);
    if (member_index == -1) {
        printf("Khong tim thay thanh vien nay.\n");
        return;
    }
    int borrow_day, borrow_month, borrow_year;
    read_date_prompt("Ngay muon", &borrow_day, &borrow_month, &borrow_year);
    int due_day, due_month, due_year;
    advance_days_30(borrow_day, borrow_month, borrow_year, 7,
                   &due_day, &due_month, &due_year);

    int loan_index = loan_count;
    copy_text(loan_idcard_at(loan_index), idcard, MEMBER_IDCARD_LEN);
    copy_text(loan_member_name_at(loan_index), member_name_at(member_index), MEMBER_NAME_LEN);
    loan_borrow_day[loan_index] = borrow_day;
    loan_borrow_month[loan_index] = borrow_month;
    loan_borrow_year[loan_index] = borrow_year;
    loan_due_day[loan_index] = due_day;
    loan_due_month[loan_index] = due_month;
    loan_due_year[loan_index] = due_year;
    loan_books_amount()[loan_index] = 0;

    int request = read_number("So sach muon (1-5): ", 1, LOAN_ITEM_LIMIT);
    for (int i = 0; i < request; i++) {
        char isbn[BOOK_ISBN_LEN];
        read_text("Nhap ISBN sach: ", isbn, BOOK_ISBN_LEN);
        int book_index = locate_book_by_isbn(isbn);
        if (book_index == -1) {
            printf("Khong tim thay sach voi ISBN nay.\n");
            continue;
        }
        if (book_available_copy[book_index] <= 0) {
            printf("Sach khong con ban san.\n");
            continue;
        }
        int slot = loan_books_amount()[loan_index];
        copy_text(loan_isbn_at(loan_index, slot), isbn, BOOK_ISBN_LEN);
        loan_item_status()[loan_item_position(loan_index, slot)] = 0;
        loan_books_amount()[loan_index] = slot + 1;
        book_available_copy[book_index]--;
    }
    if (loan_books_amount()[loan_index] == 0) {
        printf("Khong co sach nao duoc muon, huy phieu.\n");
        return;
    }
    loan_count++;
    printf("Da lap phieu muon thanh cong. Han tra: %02d/%02d/%04d.\n",
           due_day, due_month, due_year);
}

static void show_single_loan(int index) {
    printf("Phieu #%d\n", index + 1);
    printf(" Thanh vien: %s\n", loan_member_name_at(index));
    printf(" CMND: %s\n", loan_idcard_at(index));
    printf(" Ngay muon: %02d/%02d/%04d\n", loan_borrow_day[index], loan_borrow_month[index], loan_borrow_year[index]);
    printf(" Han tra: %02d/%02d/%04d\n", loan_due_day[index], loan_due_month[index], loan_due_year[index]);
    printf(" So sach muon: %d\n", loan_books_amount()[index]);
    for (int j = 0; j < loan_books_amount()[index]; j++) {
        int pos = loan_item_position(index, j);
        int status = loan_item_status()[pos];
        const char *state = "CHUA TRA";
        if (status == 1) {
            state = "DA TRA";
        } else if (status == 2) {
            state = "MAT";
        }
        printf("  %d. ISBN: %s [%s]\n", j + 1, loan_isbn_at(index, j), state);
    }
}

void process_return_ticket() {
    printf("\n===== LAP PHIEU TRA =====\n\n");
    if (loan_count == 0) {
        printf("Khong co phieu muon nao.\n");
        return;
    }
    char idcard[MEMBER_IDCARD_LEN];
    read_text("CMND nguoi tra: ", idcard, MEMBER_IDCARD_LEN);
    int processed = 0;
    for (int i = 0; i < loan_count; i++) {
        if (strcmp(loan_idcard_at(i), idcard) != 0) {
            continue;
        }
        show_single_loan(i);
        int confirm = read_number("Xu ly phieu nay? (1=Co,0=Khong): ", 0, 1);
        if (!confirm) {
            continue;
        }
        int return_day, return_month, return_year;
        read_date_prompt("Ngay tra thuc te", &return_day, &return_month, &return_year);
        int total_fee = 0;
        for (int j = 0; j < loan_books_amount()[i]; j++) {
            int pos = loan_item_position(i, j);
            if (loan_item_status()[pos] != 0) {
                continue;
            }
            printf("\nSach %d - ISBN %s\n", j + 1, loan_isbn_at(i, j));
            printf("1. Tra binh thuong\n");
            printf("2. Mat sach\n");
            int choice = read_number("Lua chon: ", 1, 2);
            int book_index = locate_book_by_isbn(loan_isbn_at(i, j));
            if (choice == 1) {
                int fee = compute_late_fee(loan_due_day[i], loan_due_month[i], loan_due_year[i],
                                           return_day, return_month, return_year);
                if (fee > 0) {
                    printf("  Tre han, phat %d dong.\n", fee);
                    total_fee += fee;
                } else {
                    printf("  Tra dung han.\n");
                }
                loan_item_status()[pos] = 1;
                if (book_index != -1) {
                    book_available_copy[book_index]++;
                    if (book_available_copy[book_index] > book_total_copy[book_index]) {
                        book_available_copy[book_index] = book_total_copy[book_index];
                    }
                }
            } else {
                int lost_fee = 0;
                if (book_index != -1) {
                    lost_fee = compute_lost_fee(book_price[book_index]);
                    printf("  Mat sach, phat %d dong.\n", lost_fee);
                    total_fee += lost_fee;
                } else {
                    printf("  Mat sach, khong tim thay gia de tinh phat.\n");
                }
                int late_fee = compute_late_fee(loan_due_day[i], loan_due_month[i], loan_due_year[i],
                                                return_day, return_month, return_year);
                if (late_fee > 0) {
                    printf("  Them phat tre han %d dong.\n", late_fee);
                    total_fee += late_fee;
                }
                loan_item_status()[pos] = 2;
            }
        }
        printf("\nTong tien phat: %d dong\n", total_fee);
        processed = 1;
        return_count++;
    }
    if (!processed) {
        printf("Khong tim thay phieu muon voi CMND nay.\n");
    }
}

void show_borrowed_overview() {
    printf("\n===== THONG KE SACH DANG MUON =====\n\n");
    int total = count_unreturned_books();
    printf("Tong so sach chua tra: %d\n", total);
}

int count_unreturned_books() {
    int total = 0;
    for (int i = 0; i < loan_count; i++) {
        for (int j = 0; j < loan_books_amount()[i]; j++) {
            int pos = loan_item_position(i, j);
            if (loan_item_status()[pos] == 0) {
                total++;
            }
        }
    }
    return total;
}
