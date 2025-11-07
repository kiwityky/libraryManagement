#ifndef MEMBERS_H
#define MEMBERS_H

#include "../data/members_mem.h"

void show_all_members();
void create_member_record();
void update_member_record();
void remove_member_by_idcard();
void find_member_via_code();
void find_member_via_idcard();
void find_member_via_name();
void extend_member_card();
void announce_expiring_cards();

int locate_member_by_code(const char *code);
int locate_member_by_idcard(const char *idcard);

#endif
