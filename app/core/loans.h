#ifndef LOANS_H
#define LOANS_H

#include "../data/loans_mem.h"

/**
 * Chức năng: Lập phiếu mượn sách mới cho độc giả.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void create_loan_ticket();
/**
 * Chức năng: Xử lý việc trả sách, cập nhật trạng thái và tiền phạt.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void process_return_ticket();
/**
 * Chức năng: Hiển thị tổng quan số sách đang được mượn.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void show_borrowed_overview();
/**
 * Chức năng: Đếm tổng số sách chưa được trả trong các phiếu mượn.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - Số lượng sách chưa trả.
 */
int count_unreturned_books();

#endif
