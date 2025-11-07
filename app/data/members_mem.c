#include <string.h>

#include "members_mem.h"

int member_count = 0;

static char member_codes[MEMBER_CAPACITY * MEMBER_CODE_LEN];
static char member_names[MEMBER_CAPACITY * MEMBER_NAME_LEN];
static char member_idcards[MEMBER_CAPACITY * MEMBER_IDCARD_LEN];
static char member_genders[MEMBER_CAPACITY * MEMBER_GENDER_LEN];
static char member_emails[MEMBER_CAPACITY * MEMBER_EMAIL_LEN];
static char member_addresses[MEMBER_CAPACITY * MEMBER_ADDRESS_LEN];

int member_birth_day[MEMBER_CAPACITY];
int member_birth_month[MEMBER_CAPACITY];
int member_birth_year[MEMBER_CAPACITY];
int member_issue_day[MEMBER_CAPACITY];
int member_issue_month[MEMBER_CAPACITY];
int member_issue_year[MEMBER_CAPACITY];
int member_expire_day[MEMBER_CAPACITY];
int member_expire_month[MEMBER_CAPACITY];
int member_expire_year[MEMBER_CAPACITY];

//Chức năng: Xóa sạch dữ liệu độc giả đang lưu trong bộ nhớ tĩnh.
void reset_member_store() {
    member_count = 0;
    memset(member_codes, 0, sizeof(member_codes));
    memset(member_names, 0, sizeof(member_names));
    memset(member_idcards, 0, sizeof(member_idcards));
    memset(member_genders, 0, sizeof(member_genders));
    memset(member_emails, 0, sizeof(member_emails));
    memset(member_addresses, 0, sizeof(member_addresses));
}

/** Chức năng: Tính địa chỉ của phần tử trong mảng ký tự tuyến tính.
 * Tham số:
 *   - base: Con trỏ đến vùng nhớ gốc.
 *   - limit: Độ dài cố định của mỗi phần tử.
 *   - index: Vị trí cần truy cập.
 * Giá trị trả về:Con trỏ đến phần tử tương ứng. */
static char *slot_at(char *base, int limit, int index) {
    return &base[index * limit];
}

/**Chức năng: Lấy con trỏ đến mã thẻ của độc giả tại vị trí cho trước.
 * Tham số: index: Chỉ số độc giả.
 * Giá trị trả về: Con trỏ tới chuỗi mã thẻ. */
char *member_code_at(int index) {
    return slot_at(member_codes, MEMBER_CODE_LEN, index);
}

/** Chức năng: Lấy con trỏ đến họ tên độc giả tại vị trí cho trước.
 * Tham số: index: Chỉ số độc giả.
 * Giá trị trả về: Con trỏ tới chuỗi họ tên. */
char *member_name_at(int index) {
    return slot_at(member_names, MEMBER_NAME_LEN, index);
}

/** Chức năng: Lấy con trỏ đến CMND của độc giả tại vị trí cho trước.
 * Tham số: index: Chỉ số độc giả.
 * Giá trị trả về: Con trỏ tới chuỗi CMND. */
char *member_idcard_at(int index) {
    return slot_at(member_idcards, MEMBER_IDCARD_LEN, index);
}

/** Chức năng: Lấy con trỏ đến giới tính của độc giả tại vị trí cho trước.
 * Tham số: index: Chỉ số độc giả.
 * Giá trị trả về: Con trỏ tới chuỗi giới tính. */
char *member_gender_at(int index) {
    return slot_at(member_genders, MEMBER_GENDER_LEN, index);
}

/** Chức năng: Lấy con trỏ đến email của độc giả tại vị trí cho trước.
 * Tham số: index: Chỉ số độc giả.
 * Giá trị trả về: Con trỏ tới chuỗi email. */
char *member_email_at(int index) {
    return slot_at(member_emails, MEMBER_EMAIL_LEN, index);
}

/** Chức năng: Lấy con trỏ đến địa chỉ của độc giả tại vị trí cho trước.
 * Tham số: index: Chỉ số độc giả.
 * Giá trị trả về: Con trỏ tới chuỗi địa chỉ. */
char *member_address_at(int index) {
    return slot_at(member_addresses, MEMBER_ADDRESS_LEN, index);
}
