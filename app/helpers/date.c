#include <stddef.h>
#include "date.h"

/**
 * Chức năng: Chuẩn hóa ngày-tháng-năm và quy đổi sang tổng số ngày theo lịch 30 ngày/tháng.
 * Tham số:
 *   - day: Ngày ban đầu (có thể nằm ngoài 1-30).
 *   - month: Tháng ban đầu (có thể nằm ngoài 1-12).
 *   - year: Năm ban đầu (>=0).
 * Giá trị trả về:
 *   - Tổng số ngày tính từ mốc 0 theo lịch 30 ngày/tháng.
 */
int to_days_30(int day, int month, int year) {
    int safe_day = day;
    if (safe_day < 1) {
        safe_day = 1;
    }
    if (safe_day > 30) {
        safe_day = 30;
    }
    int safe_month = month;
    if (safe_month < 1) {
        safe_month = 1;
    }
    if (safe_month > 12) {
        safe_month = 12;
    }
    return year * 360 + (safe_month - 1) * 30 + (safe_day - 1);
}

/**
 * Chức năng: Chuyển đổi tổng số ngày theo lịch 30 ngày/tháng về ngày-tháng-năm.
 * Tham số:
 *   - total_days: Tổng số ngày cần chuyển đổi (sẽ được ép tối thiểu 0).
 *   - day: Con trỏ nhận giá trị ngày (1-30), có thể NULL.
 *   - month: Con trỏ nhận giá trị tháng (1-12), có thể NULL.
 *   - year: Con trỏ nhận giá trị năm (>=0), có thể NULL.
 * Giá trị trả về:
 *   - void.
 */
void from_days_30(int total_days, int *day, int *month, int *year) {
    if (total_days < 0) {
        total_days = 0;
    }
    int local_year = total_days / 360;
    int remainder = total_days % 360;
    int local_month = remainder / 30;
    int local_day = remainder % 30;
    if (day != NULL) {
        *day = local_day + 1;
    }
    if (month != NULL) {
        *month = local_month + 1;
    }
    if (year != NULL) {
        *year = local_year;
    }
}

/**
 * Chức năng: Cộng thêm số ngày theo lịch 30 ngày/tháng và xuất kết quả ra các tham số con trỏ.
 * Tham số:
 *   - day: Ngày ban đầu.
 *   - month: Tháng ban đầu.
 *   - year: Năm ban đầu.
 *   - add_days: Số ngày cần cộng thêm (có thể âm).
 *   - out_day: Con trỏ nhận ngày mới, có thể NULL.
 *   - out_month: Con trỏ nhận tháng mới, có thể NULL.
 *   - out_year: Con trỏ nhận năm mới, có thể NULL.
 * Giá trị trả về:
 *   - void.
 */
void advance_days_30(int day, int month, int year, int add_days, int *out_day, int *out_month, int *out_year) {
    int total = to_days_30(day, month, year);
    total += add_days;
    from_days_30(total, out_day, out_month, out_year);
}

/**
 * Chức năng: Cộng thêm số tháng theo lịch 30 ngày/tháng và trả về ngày mới (không đổi ngày).
 * Tham số:
 *   - day: Ngày ban đầu (sẽ được chuẩn hóa trong khoảng 1-30).
 *   - month: Tháng ban đầu (sẽ được chuẩn hóa trong khoảng 1-12).
 *   - year: Năm ban đầu (>=0).
 *   - add_months: Số tháng cần cộng thêm (có thể âm).
 *   - out_day: Con trỏ nhận ngày mới, có thể NULL.
 *   - out_month: Con trỏ nhận tháng mới, có thể NULL.
 *   - out_year: Con trỏ nhận năm mới, có thể NULL.
 * Giá trị trả về:
 *   - void.
 */
void advance_months_30(int day, int month, int year, int add_months, int *out_day, int *out_month, int *out_year) {
    int safe_day = day;
    if (safe_day < 1) {
        safe_day = 1;
    }
    if (safe_day > 30) {
        safe_day = 30;
    }
    int safe_month = month;
    if (safe_month < 1) {
        safe_month = 1;
    }
    if (safe_month > 12) {
        safe_month = 12;
    }
    int total_months = (year * 12) + (safe_month - 1) + add_months;
    int new_year = total_months / 12;
    int new_month = total_months % 12 + 1;
    if (out_day != NULL) {
        *out_day = safe_day;
    }
    if (out_month != NULL) {
        *out_month = new_month;
    }
    if (out_year != NULL) {
        *out_year = new_year;
    }
}

/**
 * Chức năng: So sánh hai mốc thời gian theo lịch 30 ngày/tháng.
 * Tham số:
 *   - d1, m1, y1: Ngày đầu tiên.
 *   - d2, m2, y2: Ngày thứ hai.
 * Giá trị trả về:
 *   - -1 nếu ngày thứ nhất sớm hơn, 1 nếu muộn hơn, 0 nếu trùng nhau.
 */
int compare_dates_30(int d1, int m1, int y1, int d2, int m2, int y2) {
    int t1 = to_days_30(d1, m1, y1);
    int t2 = to_days_30(d2, m2, y2);
    if (t1 < t2) {
        return -1;
    }
    if (t1 > t2) {
        return 1;
    }
    return 0;
}

/**
 * Chức năng: Tính khoảng chênh lệch số ngày giữa hai mốc theo lịch 30 ngày/tháng.
 * Tham số:
 *   - d1, m1, y1: Ngày bắt đầu.
 *   - d2, m2, y2: Ngày kết thúc.
 * Giá trị trả về:
 *   - Hiệu số ngày (có thể âm) giữa hai mốc.
 */
int difference_days_30(int d1, int m1, int y1, int d2, int m2, int y2) {
    int t1 = to_days_30(d1, m1, y1);
    int t2 = to_days_30(d2, m2, y2);
    return t2 - t1;
}
