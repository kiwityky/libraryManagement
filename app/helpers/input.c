#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "input.h"

/**
 * Chức năng: Xóa ký tự trắng ở đầu và cuối chuỗi đầu vào.
 * Tham số:
 *   - line: Chuỗi cần xử lý, NULL sẽ bị bỏ qua.
 * Giá trị trả về:
 *   - void.
 */
void trim_text(char *line) {
    if (line == NULL) {
        return;
    }
    int length = (int)strlen(line);
    while (length > 0 && (line[length - 1] == '\n' || line[length - 1] == '\r' ||
                          line[length - 1] == '\t' || line[length - 1] == ' ')) {
        line[length - 1] = '\0';
        length--;
    }
    int first = 0;
    while (line[first] == ' ' || line[first] == '\t') {
        first++;
    }
    if (first > 0) {
        int index = 0;
        while (line[first + index] != '\0') {
            line[index] = line[first + index];
            index++;
        }
        line[index] = '\0';
    }
}

/**
 * Chức năng: Sao chép chuỗi nguồn vào đích với giới hạn độ dài.
 * Tham số:
 *   - dest: Bộ đệm đích, yêu cầu đủ lớn theo limit.
 *   - src: Chuỗi nguồn cần sao chép.
 *   - limit: Số ký tự tối đa (bao gồm ký tự '\0').
 * Giá trị trả về:
 *   - void.
 */
void copy_text(char *dest, const char *src, int limit) {
    if (dest == NULL || src == NULL || limit <= 0) {
        return;
    }
    int i = 0;
    while (src[i] != '\0' && i < limit - 1) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

/**
 * Chức năng: Kiểm tra chuỗi có phải là rỗng hoặc chỉ gồm ký tự trắng.
 * Tham số:
 *   - text: Chuỗi đầu vào cần kiểm tra.
 * Giá trị trả về:
 *   - 1 nếu chuỗi rỗng/chỉ trắng, 0 nếu ngược lại.
 */
int text_is_empty(const char *text) {
    if (text == NULL) {
        return 1;
    }
    int i = 0;
    while (text[i] != '\0') {
        if (!isspace((unsigned char)text[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

/**
 * Chức năng: Đọc một dòng văn bản từ stdin và loại bỏ dòng trống.
 * Tham số:
 *   - label: Chuỗi hiển thị trước khi nhập, có thể NULL.
 *   - buffer: Bộ đệm nhận chuỗi kết quả.
 *   - limit: Kích thước tối đa của bộ đệm.
 * Giá trị trả về:
 *   - void.
 */
void read_text(const char *label, char *buffer, int limit) {
    if (buffer == NULL || limit <= 0) {
        return;
    }
    while (1) {
        if (label != NULL) {
            printf("%s", label);
        }
        if (fgets(buffer, limit, stdin) == NULL) {
            buffer[0] = '\0';
            continue;
        }
        // 🔹 Thêm đoạn này để xóa phần còn lại trong stdin (rất quan trọng)
        if (strchr(buffer, '\n') == NULL) {
            int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        }
        trim_text(buffer);
        if (!text_is_empty(buffer)) {
            break;
        }
        printf("Noi dung khong duoc rong. Vui long nhap lai.\n");
    }
}

/**
 * Chức năng: Đọc số nguyên trong khoảng cho phép với thông báo nhắc.
 * Tham số:
 *   - label: Chuỗi hiển thị trước khi nhập, có thể NULL.
 *   - min_value: Giá trị nhỏ nhất hợp lệ.
 *   - max_value: Giá trị lớn nhất hợp lệ.
 * Giá trị trả về:
 *   - Số nguyên hợp lệ do người dùng nhập.
 */
int read_number(const char *label, int min_value, int max_value) {
    char line[64];
    int value;
    while (1) {
        if (label != NULL) {
            printf("%s", label);
        }

        if (fgets(line, sizeof(line), stdin) == NULL) {
            // Nếu nhập lỗi, xóa stdin rồi yêu cầu nhập lại
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            continue;
        }

        // Xóa newline cuối dòng
        line[strcspn(line, "\n")] = 0;

        if (sscanf(line, "%d", &value) != 1) {
            printf("Gia tri khong hop le. Thu lai.\n");
            continue;
        }

        if (value < min_value || value > max_value) {
            printf("Vui long nhap trong khoang %d - %d.\n", min_value, max_value);
            continue;
        }

        return value;
    }
}

/**
 * Chức năng: Hỏi lần lượt ngày, tháng, năm với phạm vi kiểm soát.
 * Tham số:
 *   - label: Nhãn mô tả nhóm thông tin ngày, có thể NULL.
 *   - day: Con trỏ nhận giá trị ngày (1-30).
 *   - month: Con trỏ nhận giá trị tháng (1-12).
 *   - year: Con trỏ nhận giá trị năm (1900-2025).
 * Giá trị trả về:
 *   - void.
 */
void read_date_prompt(const char *label, int *day, int *month, int *year) {
    char caption[128];
    if (label == NULL) {
        label = "Ngay";
    }
     snprintf(caption, sizeof(caption), "%s - ngay (1-30): ", label);
    *day = read_number(caption, 1, 30);

    printf("\n");  // 👈 thêm dòng trống giữa các prompt

    snprintf(caption, sizeof(caption), "%s - thang (1-12): ", label);
    *month = read_number(caption, 1, 12);

    printf("\n");  // 👈 thêm dòng trống giữa các prompt

    snprintf(caption, sizeof(caption), "%s - nam (1900-2025): ", label);
    *year = read_number(caption, 1900, 2025);
}
