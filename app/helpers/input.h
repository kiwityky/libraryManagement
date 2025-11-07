#ifndef INPUT_H
#define INPUT_H

/** Chức năng: Loại bỏ ký tự thừa ở đầu và cuối chuỗi.
 * Tham số:
 *   - line: Chuỗi cần xử lý, có thể NULL.
 * Giá trị trả về:
 *   - void. */
void trim_text(char *line);

/**
 * Chức năng: Sao chép chuỗi nguồn sang đích với giới hạn ký tự.
 * Tham số:
 *   - dest: Bộ đệm đích nhận dữ liệu.
 *   - src: Chuỗi nguồn cần sao chép.
 *   - limit: Số ký tự tối đa (bao gồm ký tự kết thúc chuỗi).
 * Giá trị trả về:
 *   - void. */
void copy_text(char *dest, const char *src, int limit);

/** Chức năng: Đọc chuỗi ký tự từ stdin với nhãn nhắc và đảm bảo không rỗng.
 * Tham số:
 *   - label: Chuỗi nhắc hiển thị trước khi nhập, có thể NULL.
 *   - buffer: Bộ đệm nhận kết quả.
 *   - limit: Kích thước tối đa của bộ đệm.
 * Giá trị trả về:
 *   - void. */
void read_text(const char *label, char *buffer, int limit);

/** Chức năng: Đọc số nguyên từ stdin trong khoảng cho phép.
 * Tham số:
 *   - label: Chuỗi nhắc hiển thị trước khi nhập, có thể NULL.
 *   - min_value: Giá trị nhỏ nhất hợp lệ.
 *   - max_value: Giá trị lớn nhất hợp lệ.
 * Giá trị trả về:
 *   - Số nguyên người dùng nhập trong khoảng. */
int read_number(const char *label, int min_value, int max_value);

/**Chức năng: Hỗ trợ nhập ngày, tháng, năm với nhãn mô tả.
 * Tham số:
 *   - label: Chuỗi mô tả nhóm ngày cần nhập, có thể NULL.
 *   - day: Con trỏ nhận ngày (1-30).
 *   - month: Con trỏ nhận tháng (1-12).
 *   - year: Con trỏ nhận năm (1900-2025).
 * Giá trị trả về: void. */

void read_date_prompt(const char *label, int *day, int *month, int *year);

/**
 * Chức năng: Kiểm tra chuỗi có chứa toàn khoảng trắng hay không.
 * Tham số:
 *   - text: Chuỗi cần kiểm tra, có thể NULL.
 * Giá trị trả về:
 *   - 1 nếu chuỗi rỗng hoặc chỉ có khoảng trắng, 0 nếu có ký tự khác. */
int text_is_empty(const char *text);

#endif
