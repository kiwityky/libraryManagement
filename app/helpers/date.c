#include <stddef.h>
#include "date.h"

int to_days_30(int day, int month, int year) {
    int safe_day = day;
    if (safe_day < 1) {
        safe_day = 1;
    }
    if (safe_day > 30) {
        safe_day = 30;
    }
    int safe_month = month;
    if (safe_month < 1) {
        safe_month = 1;
    }
    if (safe_month > 12) {
        safe_month = 12;
    }
    return year * 360 + (safe_month - 1) * 30 + (safe_day - 1);
}

void from_days_30(int total_days, int *day, int *month, int *year) {
    if (total_days < 0) {
        total_days = 0;
    }
    int local_year = total_days / 360;
    int remainder = total_days % 360;
    int local_month = remainder / 30;
    int local_day = remainder % 30;
    if (day != NULL) {
        *day = local_day + 1;
    }
    if (month != NULL) {
        *month = local_month + 1;
    }
    if (year != NULL) {
        *year = local_year;
    }
}

void advance_days_30(int day, int month, int year, int add_days, int *out_day, int *out_month, int *out_year) {
    int total = to_days_30(day, month, year);
    total += add_days;
    from_days_30(total, out_day, out_month, out_year);
}

void advance_months_30(int day, int month, int year, int add_months, int *out_day, int *out_month, int *out_year) {
    int safe_day = day;
    if (safe_day < 1) {
        safe_day = 1;
    }
    if (safe_day > 30) {
        safe_day = 30;
    }
    int safe_month = month;
    if (safe_month < 1) {
        safe_month = 1;
    }
    if (safe_month > 12) {
        safe_month = 12;
    }
    int total_months = (year * 12) + (safe_month - 1) + add_months;
    int new_year = total_months / 12;
    int new_month = total_months % 12 + 1;
    if (out_day != NULL) {
        *out_day = safe_day;
    }
    if (out_month != NULL) {
        *out_month = new_month;
    }
    if (out_year != NULL) {
        *out_year = new_year;
    }
}

int compare_dates_30(int d1, int m1, int y1, int d2, int m2, int y2) {
    int t1 = to_days_30(d1, m1, y1);
    int t2 = to_days_30(d2, m2, y2);
    if (t1 < t2) {
        return -1;
    }
    if (t1 > t2) {
        return 1;
    }
    return 0;
}

int difference_days_30(int d1, int m1, int y1, int d2, int m2, int y2) {
    int t1 = to_days_30(d1, m1, y1);
    int t2 = to_days_30(d2, m2, y2);
    return t2 - t1;
}
