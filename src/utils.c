#include <stdio.h>
#include <string.h>

#include "utils.h"

/*
 * Đọc số nguyên trong phạm vi [min_val, max_val] với kiểm tra lỗi.
 * prompt: thông báo hiển thị trước khi nhập.
 * return: giá trị số nguyên hợp lệ.
 */
int nhap_so_nguyen(const char* prompt, int min_val, int max_val) {
    char line[128];
    int val;
    while (1) {
        if (prompt && *prompt) {
            printf("%s", prompt);
            fflush(stdout);
        }
        if (!fgets(line, sizeof(line), stdin)) {
            continue;
        }
        // TODO: cần phải viết hàm trim để xóa khoảng trống của line
        if (line[0] == '\0') continue; // skip dòng không nhập gì
        char extra;
        // check xem có ký tự thừa không
        // ép kiểu: biến giá trị string nhập vào thành giá trị integer và gắn vào biến val thông qua địa chỉ &val
        // biến extra dùng để check có giá trị sau đó nữa không
        // vd: 123 -> đúng, nếu 123abc -> vẫn đúng nếu không có biến extra -> bug
        if (sscanf(line, "%d %c", &val, &extra) == 1) { 
            if (val < min_val || val > max_val) {
                printf("Vui long nhap trong khoang [%d %d].\n", min_val, max_val);
            }
            return val;
        } else {
            printf("Vui long nhap mot so nguyen.\n");
        };
    }
}

/*
 * Nhập chuỗi ký tự từ stdin.
 * prompt: thông báo hiển thị.
 * buf: vùng nhớ để ghi kết quả.
 * max_len: kích thước bộ đệm.
 */
void nhap_chuoi(const char* prompt, char* buf, int max_len) {
    if (prompt && *prompt) {
        printf("%s", prompt);
    }
    if (fgets(buf, max_len, stdin) == NULL) {
        if (max_len > 0) buf[0] = '\0';
        return;
    }
    // Xóa ký tự xuống dòng (\n hoặc \r\n)
    size_t n = strlen(buf);
    if (n > 0 && buf[n-1] == '\n') buf[n-1] = '\0';
    n = strlen(buf);
    if (n > 0 && buf[n-1] == '\r') buf[n-1] = '\0';
}

/*
 * Sao chép chuỗi vào vùng nhớ đích.
 */
void luu_du_lieu_vao_vung_nho(char* dest, const char* source) {
    strcpy(dest, source);
}

/*
 * Ghi số nguyên vào vùng nhớ đích.
 */
void luu_so_nguyen_vao_vung_nho(int* dest, int value) {
    *dest = value;
}

/*
 * Tạm dừng chương trình cho tới khi người dùng nhấn Enter.
 */
void press_enter_to_continue() {
    printf("Bam Enter de tiep tuc");
    fflush(stdout);
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} // 
}

int validate_ngay_thang_nam(int ngay, int thang, int nam) {
    if (nam < 1 || thang < 1|| thang > 12 || ngay < 1 || ngay > 31) return 0;
    if (thang == 2 && ngay > 29) return 0;
    if ((thang == 4 || thang == 6 || thang == 9 || thang == 11) && ngay > 30) return 0;
    return 1;
}

static int parse_ngay_thang_nam(const char* chuoi, int* ngay, int* thang, int* nam) {
    int day, month, year;
    if (sscanf(chuoi, "%d/%d/%d", &day, &month, &year) == 3) {
        if (validate_ngay_thang_nam(day, month, year)) {
            *ngay = day;
            *thang = month;
            *nam = year;
            return 1;
        }
    }
    return 0;
}

/*
 * Nhập ngày tháng năm định dạng dd/mm/yyyy.
 */
int nhap_ngay_thang_nam(const char* label, int* ngay , int* thang, int* nam) {
    char line[128];
    while (1) {
        printf("%s (dd/mm/yyyy): ", label);
        fflush(stdout);
        if (!fgets(line, sizeof(line), stdin)) continue;
        if (parse_ngay_thang_nam(line, ngay, thang, nam)) {
            return 1;
        }
        printf("Dinh dang ngay khong hop le, vui long thu lai.\n");
    }
}

static long long chuyen_thanh_tong_ngay(int ngay, int thang, int nam) {
    long long total = (long long)nam * 360LL;
    total += (long long)(thang - 1) * 30LL;
    total += (long long)(ngay - 1);
    return total;
}

static void chuyen_tong_ngay_thanh_ngay(long long tong_ngay, int* ngay, int* thang, int* nam) {
    if (tong_ngay < 0) {
        tong_ngay = 0;
    }
    *nam = (int)(tong_ngay / 360LL);
    long long phan_du = tong_ngay % 360LL;
    *thang = (int)(phan_du / 30LL) + 1;
    *ngay = (int)(phan_du % 30LL) + 1;
}

/*
 * Cộng thêm số ngày theo giả định 30 ngày/tháng.
 */
void cong_ngay_gia_dinh_30(int ngay, int thang, int nam, int so_ngay_them,
                           int* ngay_out, int* thang_out, int* nam_out) {
    long long tong = chuyen_thanh_tong_ngay(ngay, thang, nam);
    tong += so_ngay_them;
    chuyen_tong_ngay_thanh_ngay(tong, ngay_out, thang_out, nam_out);
}

/*
 * Cộng thêm số tháng theo giả định 12 tháng/năm, 30 ngày/tháng.
 */
void cong_thang_gia_dinh_30(int ngay, int thang, int nam, int so_thang_them,
                            int* ngay_out, int* thang_out, int* nam_out) {
    long long tong_thang = (long long)nam * 12LL + (thang - 1) + so_thang_them;
    if (tong_thang < 0) tong_thang = 0;
    *nam_out = (int)(tong_thang / 12LL);
    *thang_out = (int)(tong_thang % 12LL) + 1;
    *ngay_out = ngay;
    if (*ngay_out > 30) {
        *ngay_out = 30;
    }
}

/*
 * Tính số ngày chênh lệch theo giả định 30 ngày/tháng.
 */
int tinh_so_ngay_chenh_lech_gia_dinh_30(int ngay1, int thang1, int nam1,
                                        int ngay2, int thang2, int nam2) {
    long long t1 = chuyen_thanh_tong_ngay(ngay1, thang1, nam1);
    long long t2 = chuyen_thanh_tong_ngay(ngay2, thang2, nam2);
    return (int)(t2 - t1);
}