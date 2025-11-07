#ifndef DATE_H
#define DATE_H

/**
 * Chức năng: Chuyển ngày, tháng, năm sang tổng số ngày theo lịch 30 ngày/tháng.
 * Tham số:
 *   - day: Ngày trong tháng (1-30, sẽ được hiệu chỉnh nếu ngoài phạm vi).
 *   - month: Tháng trong năm (1-12, sẽ được hiệu chỉnh nếu ngoài phạm vi).
 *   - year: Năm dương lịch (>= 0).
 * Giá trị trả về:
 *   - Số ngày tương ứng kể từ mốc 0.
 */
int to_days_30(int day, int month, int year);
/**
 * Chức năng: Chuyển tổng số ngày theo lịch 30 ngày/tháng thành ngày, tháng, năm.
 * Tham số:
 *   - total_days: Tổng số ngày theo hệ 30 ngày/tháng (>= 0).
 *   - day: Con trỏ nhận giá trị ngày (1-30) sau chuyển đổi, có thể NULL.
 *   - month: Con trỏ nhận giá trị tháng (1-12) sau chuyển đổi, có thể NULL.
 *   - year: Con trỏ nhận giá trị năm (>=0) sau chuyển đổi, có thể NULL.
 * Giá trị trả về:
 *   - void.
 */
void from_days_30(int total_days, int *day, int *month, int *year);
/**
 * Chức năng: Cộng thêm số ngày vào một ngày cho sẵn theo lịch 30 ngày/tháng.
 * Tham số:
 *   - day: Ngày ban đầu (1-30, sẽ được hiệu chỉnh nếu ngoài phạm vi).
 *   - month: Tháng ban đầu (1-12, sẽ được hiệu chỉnh nếu ngoài phạm vi).
 *   - year: Năm ban đầu (>=0).
 *   - add_days: Số ngày cần cộng thêm (có thể âm hoặc dương).
 *   - out_day: Con trỏ nhận ngày mới, có thể NULL.
 *   - out_month: Con trỏ nhận tháng mới, có thể NULL.
 *   - out_year: Con trỏ nhận năm mới, có thể NULL.
 * Giá trị trả về:
 *   - void.
 */
void advance_days_30(int day, int month, int year, int add_days, int *out_day, int *out_month, int *out_year);
/**
 * Chức năng: Cộng thêm số tháng vào một ngày cho sẵn theo lịch 30 ngày/tháng.
 * Tham số:
 *   - day: Ngày ban đầu (1-30, sẽ được hiệu chỉnh nếu ngoài phạm vi).
 *   - month: Tháng ban đầu (1-12, sẽ được hiệu chỉnh nếu ngoài phạm vi).
 *   - year: Năm ban đầu (>=0).
 *   - add_months: Số tháng cần cộng thêm (có thể âm hoặc dương).
 *   - out_day: Con trỏ nhận ngày mới, có thể NULL.
 *   - out_month: Con trỏ nhận tháng mới, có thể NULL.
 *   - out_year: Con trỏ nhận năm mới, có thể NULL.
 * Giá trị trả về:
 *   - void.
 */
void advance_months_30(int day, int month, int year, int add_months, int *out_day, int *out_month, int *out_year);
/**
 * Chức năng: So sánh hai ngày theo lịch 30 ngày/tháng.
 * Tham số:
 *   - d1, m1, y1: Ngày thứ nhất.
 *   - d2, m2, y2: Ngày thứ hai.
 * Giá trị trả về:
 *   - -1 nếu ngày thứ nhất nhỏ hơn ngày thứ hai, 1 nếu lớn hơn, 0 nếu bằng nhau.
 */
int compare_dates_30(int d1, int m1, int y1, int d2, int m2, int y2);
/**
 * Chức năng: Tính số ngày chênh lệch giữa hai ngày theo lịch 30 ngày/tháng.
 * Tham số:
 *   - d1, m1, y1: Ngày mốc ban đầu.
 *   - d2, m2, y2: Ngày mốc kết thúc.
 * Giá trị trả về:
 *   - Số ngày của mốc kết thúc trừ mốc ban đầu (có thể âm).
 */
int difference_days_30(int d1, int m1, int y1, int d2, int m2, int y2);

#endif
