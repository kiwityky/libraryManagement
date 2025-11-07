#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "input.h"

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
        trim_text(buffer);
        if (!text_is_empty(buffer)) {
            break;
        }
        printf("Noi dung khong duoc rong. Vui long nhap lai.\n");
    }
}

int read_number(const char *label, int min_value, int max_value) {
    char line[64];
    int value;
    while (1) {
        read_text(label, line, sizeof(line));
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

void read_date_prompt(const char *label, int *day, int *month, int *year) {
    char caption[128];
    if (label == NULL) {
        label = "Ngay";
    }
    snprintf(caption, sizeof(caption), "%s - ngay (1-30): ", label);
    *day = read_number(caption, 1, 30);
    snprintf(caption, sizeof(caption), "%s - thang (1-12): ", label);
    *month = read_number(caption, 1, 12);
    snprintf(caption, sizeof(caption), "%s - nam (1900-9999): ", label);
    *year = read_number(caption, 1900, 9999);
}
