#ifndef REPORTS_H
#define REPORTS_H

/**
 * Chức năng: Thống kê tổng quan số liệu thư viện.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void report_library_numbers();
/**
 * Chức năng: Thống kê số độc giả theo giới tính.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void report_member_by_gender();
/**
 * Chức năng: Thống kê sách theo từng thể loại định nghĩa sẵn.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void report_books_by_category();
/**
 * Chức năng: Liệt kê độc giả đang trả sách trễ so với hạn.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void report_overdue_readers();
/**
 * Chức năng: Báo cáo số lượng sách chưa được trả.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void report_active_loans();

#endif
