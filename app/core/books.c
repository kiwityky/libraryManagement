#include <stdio.h>
#include <string.h>

#include "books.h"
#include "../helpers/input.h"

/**
 * Chức năng: In tiêu đề bảng danh mục sách.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
static void book_table_header() {
    printf("%-4s | %-14s | %-30s | %-18s | %-18s | %-14s | %-8s | %-8s | %-8s\n",
           "STT", "ISBN", "Tieu de", "Tac gia", "Nha XB", "The loai", "Nam", "Tong", "Con");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
}

/**
 * Chức năng: In thông tin một quyển sách theo định dạng bảng.
 * Tham số:
 *   - index: Chỉ số sách cần hiển thị.
 * Giá trị trả về:
 *   - void.
 */
static void book_table_row(int index) {
    printf("%-4d | %-14s | %-30s | %-18s | %-18s | %-14s | %-8d | %-8d | %-8d\n",
           index + 1,
           book_isbn_at(index),
           book_title_at(index),
           book_author_at(index),
           book_publisher_at(index),
           book_category_at(index),
           book_year[index],
           book_total_copy[index],
           book_available_copy[index]);
}

/**
 * Chức năng: Tìm chỉ số sách dựa trên ISBN.
 * Tham số:
 *   - isbn: Chuỗi ISBN cần tra cứu.
 * Giá trị trả về:
 *   - Chỉ số sách hoặc -1 nếu không tìm thấy.
 */
int locate_book_by_isbn(const char *isbn) {
    for (int i = 0; i < book_count; i++) {
        if (strcmp(book_isbn_at(i), isbn) == 0) {
            return i;
        }
    }
    return -1;
}

/**
 * Chức năng: Dịch trái các bản ghi sách kể từ vị trí cho trước.
 * Tham số:
 *   - start_index: Chỉ số bắt đầu dịch.
 * Giá trị trả về:
 *   - void.
 */
static void shift_books_left(int start_index) {
    for (int i = start_index; i < book_count - 1; i++) {
        copy_text(book_isbn_at(i), book_isbn_at(i + 1), BOOK_ISBN_LEN);
        copy_text(book_title_at(i), book_title_at(i + 1), BOOK_TITLE_LEN);
        copy_text(book_author_at(i), book_author_at(i + 1), BOOK_AUTHOR_LEN);
        copy_text(book_publisher_at(i), book_publisher_at(i + 1), BOOK_PUBLISHER_LEN);
        copy_text(book_category_at(i), book_category_at(i + 1), BOOK_CATEGORY_LEN);
        book_year[i] = book_year[i + 1];
        book_price[i] = book_price[i + 1];
        book_total_copy[i] = book_total_copy[i + 1];
        book_available_copy[i] = book_available_copy[i + 1];
    }
}

/**
 * Chức năng: Hiển thị toàn bộ danh mục sách hiện có.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void list_books() {
    printf("\n===== DANH MUC SACH =====\n\n");
    printf("Tong so dau sach: %d\n", book_count);
    if (book_count == 0) {
        printf("Thu vien chua co sach.\n");
        return;
    }
    book_table_header();
    for (int i = 0; i < book_count; i++) {
        book_table_row(i);
    }
}

/**
 * Chức năng: Thu thập thông tin và thêm sách mới vào kho.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void add_book_entry() {
    printf("\n===== THEM SACH =====\n\n");
    if (book_count >= BOOK_CAPACITY) {
        printf("Khong the them sach moi.\n");
        return;
    }
    char isbn[BOOK_ISBN_LEN];
    while (1) {
        read_text("ISBN: ", isbn, BOOK_ISBN_LEN);
        if (locate_book_by_isbn(isbn) == -1) {
            break;
        }
        printf("ISBN da ton tai.\n");
    }
    char title[BOOK_TITLE_LEN];
    read_text("Tieu de: ", title, BOOK_TITLE_LEN);
    char author[BOOK_AUTHOR_LEN];
    read_text("Tac gia: ", author, BOOK_AUTHOR_LEN);
    char publisher[BOOK_PUBLISHER_LEN];
    read_text("Nha xuat ban: ", publisher, BOOK_PUBLISHER_LEN);
    char category[BOOK_CATEGORY_LEN];
    read_text("The loai: ", category, BOOK_CATEGORY_LEN);
    int year = read_number("Nam xuat ban: ", 1900, 9999);
    int price = read_number("Gia sach: ", 0, 1000000000);
    int total = read_number("Tong so ban: ", 0, 100000);
    int available;
    while (1) {
        available = read_number("So ban co san: ", 0, 100000);
        if (available <= total) {
            break;
        }
        printf("So ban co san khong duoc vuot tong so ban.\n");
    }
    copy_text(book_isbn_at(book_count), isbn, BOOK_ISBN_LEN);
    copy_text(book_title_at(book_count), title, BOOK_TITLE_LEN);
    copy_text(book_author_at(book_count), author, BOOK_AUTHOR_LEN);
    copy_text(book_publisher_at(book_count), publisher, BOOK_PUBLISHER_LEN);
    copy_text(book_category_at(book_count), category, BOOK_CATEGORY_LEN);
    book_year[book_count] = year;
    book_price[book_count] = price;
    book_total_copy[book_count] = total;
    book_available_copy[book_count] = available;
    book_count++;
    printf("Da them sach moi.\n");
}

/**
 * Chức năng: Chỉnh sửa thông tin của một bản ghi sách.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void update_book_entry() {
    printf("\n===== CAP NHAT SACH =====\n\n");
    if (book_count == 0) {
        printf("Chua co sach de cap nhat.\n");
        return;
    }
    char isbn[BOOK_ISBN_LEN];
    read_text("Nhap ISBN can sua: ", isbn, BOOK_ISBN_LEN);
    int index = locate_book_by_isbn(isbn);
    if (index == -1) {
        printf("Khong tim thay ISBN.\n");
        return;
    }
    char title[BOOK_TITLE_LEN];
    read_text("Tieu de moi: ", title, BOOK_TITLE_LEN);
    char author[BOOK_AUTHOR_LEN];
    read_text("Tac gia moi: ", author, BOOK_AUTHOR_LEN);
    char publisher[BOOK_PUBLISHER_LEN];
    read_text("Nha xuat ban moi: ", publisher, BOOK_PUBLISHER_LEN);
    char category[BOOK_CATEGORY_LEN];
    read_text("The loai moi: ", category, BOOK_CATEGORY_LEN);
    int year = read_number("Nam xuat ban moi: ", 1900, 9999);
    int price = read_number("Gia sach moi: ", 0, 1000000000);
    int total = read_number("Tong so ban moi: ", 0, 100000);
    int available;
    while (1) {
        available = read_number("So ban co san moi: ", 0, 100000);
        if (available <= total) {
            break;
        }
        printf("So ban co san khong duoc vuot tong so ban.\n");
    }
    copy_text(book_title_at(index), title, BOOK_TITLE_LEN);
    copy_text(book_author_at(index), author, BOOK_AUTHOR_LEN);
    copy_text(book_publisher_at(index), publisher, BOOK_PUBLISHER_LEN);
    copy_text(book_category_at(index), category, BOOK_CATEGORY_LEN);
    book_year[index] = year;
    book_price[index] = price;
    book_total_copy[index] = total;
    if (available > total) {
        available = total;
    }
    if (available < 0) {
        available = 0;
    }
    book_available_copy[index] = available;
    printf("Cap nhat sach thanh cong.\n");
}

/**
 * Chức năng: Xóa sách khỏi kho dựa trên ISBN.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void remove_book_by_isbn() {
    printf("\n===== XOA SACH =====\n\n");
    if (book_count == 0) {
        printf("Thu vien khong co sach.\n");
        return;
    }
    char isbn[BOOK_ISBN_LEN];
    read_text("Nhap ISBN can xoa: ", isbn, BOOK_ISBN_LEN);
    int index = locate_book_by_isbn(isbn);
    if (index == -1) {
        printf("Khong tim thay ISBN.\n");
        return;
    }
    shift_books_left(index);
    book_count--;
    printf("Da xoa sach co ISBN %s.\n", isbn);
}

/**
 * Chức năng: Tra cứu và hiển thị sách theo ISBN.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void search_book_by_isbn() {
    char isbn[BOOK_ISBN_LEN];
    read_text("Nhap ISBN can tim: ", isbn, BOOK_ISBN_LEN);
    int index = locate_book_by_isbn(isbn);
    if (index == -1) {
        printf("Khong tim thay ISBN.\n");
        return;
    }
    book_table_header();
    book_table_row(index);
}

/**
 * Chức năng: Tra cứu và hiển thị sách khớp tiêu đề nhập vào.
 * Tham số:
 *   - Không có.
 * Giá trị trả về:
 *   - void.
 */
void search_book_by_title() {
    char title[BOOK_TITLE_LEN];
    read_text("Nhap tieu de: ", title, BOOK_TITLE_LEN);
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcmp(book_title_at(i), title) == 0) {
            if (!found) {
                book_table_header();
            }
            book_table_row(i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sach co tieu de do.\n");
    }
}
