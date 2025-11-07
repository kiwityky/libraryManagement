#ifndef MEMBERS_H
#define MEMBERS_H

#include "../data/members_mem.h"

/**
 * Chức năng: Hiển thị toàn bộ danh sách độc giả.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void show_all_members();
/**
 * Chức năng: Thêm hồ sơ độc giả mới thông qua nhập liệu.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void create_member_record();
/**
 * Chức năng: Cập nhật thông tin của một độc giả đã tồn tại.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void update_member_record();
/**
 * Chức năng: Xóa hồ sơ độc giả dựa trên số CMND.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void remove_member_by_idcard();
/**
 * Chức năng: Tìm kiếm và hiển thị độc giả bằng mã thẻ.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void find_member_via_code();
/**
 * Chức năng: Tìm kiếm và hiển thị độc giả bằng số CMND.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void find_member_via_idcard();
/**
 * Chức năng: Tìm kiếm và hiển thị độc giả bằng họ tên chính xác.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void find_member_via_name();
/**
 * Chức năng: Gia hạn thời hạn thẻ cho độc giả.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void extend_member_card();
/**
 * Chức năng: Thông báo các thẻ sắp hết hạn trong 30 ngày tới.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void announce_expiring_cards();

/**
 * Chức năng: Tìm vị trí độc giả theo mã thẻ.
 * Tham số:
 *   - code: Chuỗi mã thẻ cần tra cứu.
 * Giá trị trả về:
 *   - Chỉ số độc giả hoặc -1 nếu không tìm thấy.
 */
int locate_member_by_code(const char *code);
/**
 * Chức năng: Tìm vị trí độc giả theo số CMND.
 * Tham số:
 *   - idcard: Chuỗi CMND cần tra cứu.
 * Giá trị trả về:
 *   - Chỉ số độc giả hoặc -1 nếu không tìm thấy.
 */
int locate_member_by_idcard(const char *idcard);

#endif
