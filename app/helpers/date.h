#ifndef DATE_H
#define DATE_H

int to_days_30(int day, int month, int year);
void from_days_30(int total_days, int *day, int *month, int *year);
void advance_days_30(int day, int month, int year, int add_days, int *out_day, int *out_month, int *out_year);
void advance_months_30(int day, int month, int year, int add_months, int *out_day, int *out_month, int *out_year);
int compare_dates_30(int d1, int m1, int y1, int d2, int m2, int y2);
int difference_days_30(int d1, int m1, int y1, int d2, int m2, int y2);

#endif
