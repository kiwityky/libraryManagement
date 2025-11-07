#ifndef LOAN_H
#define LOAN_H

#include "loan_return.h"

// function thống kê sách đang mượn
void thong_ke_sach_dang_muon();

// function lập phiếu mượn sách
void lap_phieu_muon_sach();

// function tính index sách trong phiếu mượn
int index_sach_trong_phieu_muon(int index_phieu_muon, int index_cua_sach_trong_list);

#endif

