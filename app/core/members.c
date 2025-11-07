#include <stdio.h>
#include <string.h>

#include "members.h"
#include "../helpers/input.h"
#include "../helpers/date.h"

static void member_table_header() {
    printf("%-4s | %-12s | %-24s | %-12s | %-10s | %-6s | %-24s | %-24s | %-10s | %-10s\n",
           "STT", "Ma the", "Ho ten", "CMND", "Sinh", "Gioi", "Email", "Dia chi", "Lap the", "Het han");
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
}

static void member_table_row(int index) {
    printf("%-4d | %-12s | %-24s | %-12s | %02d/%02d/%04d | %-6s | %-24s | %-24s | %02d/%02d/%04d | %02d/%02d/%04d\n",
           index + 1,
           member_code_at(index),
           member_name_at(index),
           member_idcard_at(index),
           member_birth_day[index], member_birth_month[index], member_birth_year[index],
           member_gender_at(index),
           member_email_at(index),
           member_address_at(index),
           member_issue_day[index], member_issue_month[index], member_issue_year[index],
           member_expire_day[index], member_expire_month[index], member_expire_year[index]);
}

int locate_member_by_code(const char *code) {
    for (int i = 0; i < member_count; i++) {
        if (strcmp(member_code_at(i), code) == 0) {
            return i;
        }
    }
    return -1;
}

int locate_member_by_idcard(const char *idcard) {
    for (int i = 0; i < member_count; i++) {
        if (strcmp(member_idcard_at(i), idcard) == 0) {
            return i;
        }
    }
    return -1;
}

static void shift_members_left(int start_index) {
    for (int i = start_index; i < member_count - 1; i++) {
        copy_text(member_code_at(i), member_code_at(i + 1), MEMBER_CODE_LEN);
        copy_text(member_name_at(i), member_name_at(i + 1), MEMBER_NAME_LEN);
        copy_text(member_idcard_at(i), member_idcard_at(i + 1), MEMBER_IDCARD_LEN);
        copy_text(member_gender_at(i), member_gender_at(i + 1), MEMBER_GENDER_LEN);
        copy_text(member_email_at(i), member_email_at(i + 1), MEMBER_EMAIL_LEN);
        copy_text(member_address_at(i), member_address_at(i + 1), MEMBER_ADDRESS_LEN);
        member_birth_day[i] = member_birth_day[i + 1];
        member_birth_month[i] = member_birth_month[i + 1];
        member_birth_year[i] = member_birth_year[i + 1];
        member_issue_day[i] = member_issue_day[i + 1];
        member_issue_month[i] = member_issue_month[i + 1];
        member_issue_year[i] = member_issue_year[i + 1];
        member_expire_day[i] = member_expire_day[i + 1];
        member_expire_month[i] = member_expire_month[i + 1];
        member_expire_year[i] = member_expire_year[i + 1];
    }
}

static void fill_member_base_info(int index, const char *code, const char *name, const char *idcard,
                                  const char *gender, const char *email, const char *address,
                                  int birth_day, int birth_month, int birth_year,
                                  int issue_day, int issue_month, int issue_year) {
    copy_text(member_code_at(index), code, MEMBER_CODE_LEN);
    copy_text(member_name_at(index), name, MEMBER_NAME_LEN);
    copy_text(member_idcard_at(index), idcard, MEMBER_IDCARD_LEN);
    copy_text(member_gender_at(index), gender, MEMBER_GENDER_LEN);
    copy_text(member_email_at(index), email, MEMBER_EMAIL_LEN);
    copy_text(member_address_at(index), address, MEMBER_ADDRESS_LEN);
    member_birth_day[index] = birth_day;
    member_birth_month[index] = birth_month;
    member_birth_year[index] = birth_year;
    member_issue_day[index] = issue_day;
    member_issue_month[index] = issue_month;
    member_issue_year[index] = issue_year;
}

void show_all_members() {
    printf("\n===== DANH SACH THANH VIEN =====\n\n");
    printf("Tong so thanh vien: %d\n", member_count);
    if (member_count == 0) {
        printf("Chua co ho so nao.\n");
        return;
    }
    member_table_header();
    for (int i = 0; i < member_count; i++) {
        member_table_row(i);
    }
}

void create_member_record() {
    printf("\n===== THEM THANH VIEN =====\n\n");
    if (member_count >= MEMBER_CAPACITY) {
        printf("Khong the them moi, bo nho da day.\n");
        return;
    }
    char code[MEMBER_CODE_LEN];
    while (1) {
        read_text("Ma the: ", code, MEMBER_CODE_LEN);
        if (locate_member_by_code(code) == -1) {
            break;
        }
        printf("Ma the da ton tai, vui long chon ma khac.\n");
    }
    char name[MEMBER_NAME_LEN];
    read_text("Ho ten: ", name, MEMBER_NAME_LEN);
    char idcard[MEMBER_IDCARD_LEN];
    while (1) {
        read_text("CMND: ", idcard, MEMBER_IDCARD_LEN);
        if (locate_member_by_idcard(idcard) == -1) {
            break;
        }
        printf("CMND da duoc dang ky.\n");
    }
    int birth_day, birth_month, birth_year;
    read_date_prompt("Ngay sinh", &birth_day, &birth_month, &birth_year);
    char gender[MEMBER_GENDER_LEN];
    read_text("Gioi tinh: ", gender, MEMBER_GENDER_LEN);
    char email[MEMBER_EMAIL_LEN];
    read_text("Email: ", email, MEMBER_EMAIL_LEN);
    char address[MEMBER_ADDRESS_LEN];
    read_text("Dia chi: ", address, MEMBER_ADDRESS_LEN);
    int issue_day, issue_month, issue_year;
    read_date_prompt("Ngay lap the", &issue_day, &issue_month, &issue_year);
    int expire_day, expire_month, expire_year;
    advance_months_30(issue_day, issue_month, issue_year, 48,
                     &expire_day, &expire_month, &expire_year);

    fill_member_base_info(member_count, code, name, idcard, gender, email, address,
                          birth_day, birth_month, birth_year,
                          issue_day, issue_month, issue_year);
    member_expire_day[member_count] = expire_day;
    member_expire_month[member_count] = expire_month;
    member_expire_year[member_count] = expire_year;

    member_count++;
    printf("Them thanh vien thanh cong!\n");
}

void update_member_record() {
    printf("\n===== CAP NHAT THANH VIEN =====\n\n");
    if (member_count == 0) {
        printf("Chua co du lieu de cap nhat.\n");
        return;
    }
    char code[MEMBER_CODE_LEN];
    read_text("Nhap ma the can chinh sua: ", code, MEMBER_CODE_LEN);
    int index = locate_member_by_code(code);
    if (index == -1) {
        printf("Khong tim thay ma the.\n");
        return;
    }
    char name[MEMBER_NAME_LEN];
    read_text("Ho ten moi: ", name, MEMBER_NAME_LEN);
    char idcard[MEMBER_IDCARD_LEN];
    while (1) {
        read_text("CMND moi: ", idcard, MEMBER_IDCARD_LEN);
        int existed = locate_member_by_idcard(idcard);
        if (existed == -1 || existed == index) {
            break;
        }
        printf("CMND da ton tai o ho so khac.\n");
    }
    int birth_day, birth_month, birth_year;
    read_date_prompt("Ngay sinh moi", &birth_day, &birth_month, &birth_year);
    char gender[MEMBER_GENDER_LEN];
    read_text("Gioi tinh moi: ", gender, MEMBER_GENDER_LEN);
    char email[MEMBER_EMAIL_LEN];
    read_text("Email moi: ", email, MEMBER_EMAIL_LEN);
    char address[MEMBER_ADDRESS_LEN];
    read_text("Dia chi moi: ", address, MEMBER_ADDRESS_LEN);
    int issue_day, issue_month, issue_year;
    read_date_prompt("Ngay lap the moi", &issue_day, &issue_month, &issue_year);
    int expire_day, expire_month, expire_year;
    advance_months_30(issue_day, issue_month, issue_year, 48,
                     &expire_day, &expire_month, &expire_year);

    fill_member_base_info(index, code, name, idcard, gender, email, address,
                          birth_day, birth_month, birth_year,
                          issue_day, issue_month, issue_year);
    member_expire_day[index] = expire_day;
    member_expire_month[index] = expire_month;
    member_expire_year[index] = expire_year;

    printf("Cap nhat ho so thanh cong.\n");
}

void remove_member_by_idcard() {
    printf("\n===== XOA THANH VIEN =====\n\n");
    if (member_count == 0) {
        printf("Chua co ho so nao.\n");
        return;
    }
    char idcard[MEMBER_IDCARD_LEN];
    read_text("Nhap CMND can xoa: ", idcard, MEMBER_IDCARD_LEN);
    int index = locate_member_by_idcard(idcard);
    if (index == -1) {
        printf("Khong tim thay CMND nay.\n");
        return;
    }
    shift_members_left(index);
    member_count--;
    printf("Da xoa ho so co CMND %s.\n", idcard);
}

void find_member_via_code() {
    char code[MEMBER_CODE_LEN];
    read_text("Nhap ma the: ", code, MEMBER_CODE_LEN);
    int index = locate_member_by_code(code);
    if (index == -1) {
        printf("Khong tim thay ma the.\n");
        return;
    }
    member_table_header();
    member_table_row(index);
}

void find_member_via_idcard() {
    char idcard[MEMBER_IDCARD_LEN];
    read_text("Nhap CMND: ", idcard, MEMBER_IDCARD_LEN);
    int index = locate_member_by_idcard(idcard);
    if (index == -1) {
        printf("Khong tim thay CMND.\n");
        return;
    }
    member_table_header();
    member_table_row(index);
}

void find_member_via_name() {
    char name[MEMBER_NAME_LEN];
    read_text("Nhap ho ten: ", name, MEMBER_NAME_LEN);
    int found = 0;
    for (int i = 0; i < member_count; i++) {
        if (strcmp(member_name_at(i), name) == 0) {
            if (!found) {
                member_table_header();
            }
            member_table_row(i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong co ho ten phu hop.\n");
    }
}

void extend_member_card() {
    printf("\n===== GIA HAN THE =====\n\n");
    if (member_count == 0) {
        printf("Chua co ho so.\n");
        return;
    }

    char code[MEMBER_CODE_LEN];
    read_text("Nhap ma the can gia han: ", code, MEMBER_CODE_LEN);
    int index = locate_member_by_code(code);
    if (index == -1) {
        printf("Khong tim thay ma the.\n");
        return;
    }

    // 👉 Thêm phần nhập số tháng muốn gia hạn
    int extend_months = read_number("Nhap so thang muon gia han (VD: 12, 24, 48): ", 1, 120);

    advance_months_30(member_expire_day[index],
                      member_expire_month[index],
                      member_expire_year[index],
                      extend_months,
                      &member_expire_day[index],
                      &member_expire_month[index],
                      &member_expire_year[index]);

    printf("Da gia han the %s them %d thang, het han moi: %02d/%02d/%04d.\n",
           code,
           extend_months,
           member_expire_day[index], member_expire_month[index], member_expire_year[index]);
}

void announce_expiring_cards() {
    printf("\n===== CANH BAO HET HAN =====\n\n");
    if (member_count == 0) {
        printf("Khong co du lieu.\n");
        return;
    }
    int check_day, check_month, check_year;
    read_date_prompt("Ngay kiem tra", &check_day, &check_month, &check_year);
    int warned = 0;
    for (int i = 0; i < member_count; i++) {
        int remaining = difference_days_30(check_day, check_month, check_year,
                                          member_expire_day[i], member_expire_month[i], member_expire_year[i]);
        if (remaining < 0) {
            continue;
        }
        if (remaining <= 30) {
            if (!warned) {
                printf("The sap het han trong 30 ngay:\n");
                member_table_header();
            }
            member_table_row(i);
            printf("  -> Con %d ngay nua het han.\n", remaining);
            warned = 1;
        }
    }
    if (!warned) {
        printf("Khong co the nao sap het han trong 30 ngay toi.\n");
    }
}
