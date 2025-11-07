#ifndef FINES_H
#define FINES_H

#define LATE_FINE_PER_DAY 5000
#define LOST_FINE_PERCENT 200

/**
 * Chức năng: Tính tiền phạt trả sách trễ dựa trên số ngày quá hạn.
 * Tham số:
 *   - due_day, due_month, due_year: Ngày hạn trả sách.
 *   - return_day, return_month, return_year: Ngày trả thực tế.
 * Giá trị trả về:
 *   - Số tiền phạt trả trễ (đồng).
 */
int compute_late_fee(int due_day, int due_month, int due_year,
                     int return_day, int return_month, int return_year);
/**
 * Chức năng: Tính tiền phạt khi làm mất sách dựa trên giá bìa.
 * Tham số:
 *   - book_price: Giá sách gốc (đồng).
 * Giá trị trả về:
 *   - Số tiền phạt phải bồi thường.
 */
int compute_lost_fee(int book_price);

#endif
