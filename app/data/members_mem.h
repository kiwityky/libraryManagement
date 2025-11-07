#ifndef MEMBERS_MEM_H
#define MEMBERS_MEM_H

#define MEMBER_CAPACITY 1000
#define MEMBER_CODE_LEN 20
#define MEMBER_NAME_LEN 100
#define MEMBER_IDCARD_LEN 12
#define MEMBER_GENDER_LEN 10
#define MEMBER_EMAIL_LEN 40
#define MEMBER_ADDRESS_LEN 120

extern int member_count;

//Chức năng: Đặt lại toàn bộ dữ liệu lưu trữ độc giả trong bộ nhớ.
void reset_member_store();

/** Chức năng: Lấy con trỏ đến mã thẻ tại vị trí chỉ định.
 * Tham số: index: Chỉ số phần tử (0 <= index < MEMBER_CAPACITY).
 * Giá trị trả về: Con trỏ tới vùng lưu mã thẻ.
 */
char *member_code_at(int index);

/**
 * Chức năng: Lấy con trỏ đến họ tên tại vị trí chỉ định.
 * Tham số:
 *   - index: Chỉ số phần tử (0 <= index < MEMBER_CAPACITY).
 * Giá trị trả về:
 *   - Con trỏ tới vùng lưu họ tên.
 */
char *member_name_at(int index);

/**
 * Chức năng: Lấy con trỏ đến số CMND tại vị trí chỉ định.
 * Tham số:
 *   - index: Chỉ số phần tử (0 <= index < MEMBER_CAPACITY).
 * Giá trị trả về:
 *   - Con trỏ tới vùng lưu CMND.
 */
char *member_idcard_at(int index);

/**
 * Chức năng: Lấy con trỏ đến giới tính tại vị trí chỉ định.
 * Tham số:
 *   - index: Chỉ số phần tử (0 <= index < MEMBER_CAPACITY).
 * Giá trị trả về:
 *   - Con trỏ tới vùng lưu giới tính.
 */
char *member_gender_at(int index);

/**
 * Chức năng: Lấy con trỏ đến email tại vị trí chỉ định.
 * Tham số:
 *   - index: Chỉ số phần tử (0 <= index < MEMBER_CAPACITY).
 * Giá trị trả về:
 *   - Con trỏ tới vùng lưu email.
 */
char *member_email_at(int index);

/**
 * Chức năng: Lấy con trỏ đến địa chỉ tại vị trí chỉ định.
 * Tham số:
 *   - index: Chỉ số phần tử (0 <= index < MEMBER_CAPACITY).
 * Giá trị trả về:
 *   - Con trỏ tới vùng lưu địa chỉ.
 */
char *member_address_at(int index);

extern int member_birth_day[MEMBER_CAPACITY];
extern int member_birth_month[MEMBER_CAPACITY];
extern int member_birth_year[MEMBER_CAPACITY];
extern int member_issue_day[MEMBER_CAPACITY];
extern int member_issue_month[MEMBER_CAPACITY];
extern int member_issue_year[MEMBER_CAPACITY];
extern int member_expire_day[MEMBER_CAPACITY];
extern int member_expire_month[MEMBER_CAPACITY];
extern int member_expire_year[MEMBER_CAPACITY];

#endif
