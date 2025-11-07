#include "fines.h"
#include "../helpers/date.h"

int compute_late_fee(int due_day, int due_month, int due_year,
                     int return_day, int return_month, int return_year) {
    int diff = difference_days_30(due_day, due_month, due_year,
                                  return_day, return_month, return_year);
    if (diff <= 0) {
        return 0;
    }
    return diff * LATE_FINE_PER_DAY;
}

int compute_lost_fee(int book_price) {
    if (book_price < 0) {
        book_price = 0;
    }
    return book_price * LOST_FINE_PERCENT / 100;
}
