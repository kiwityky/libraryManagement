#ifndef FINES_H
#define FINES_H

#define LATE_FINE_PER_DAY 5000
#define LOST_FINE_PERCENT 200

int compute_late_fee(int due_day, int due_month, int due_year,
                     int return_day, int return_month, int return_year);
int compute_lost_fee(int book_price);

#endif
