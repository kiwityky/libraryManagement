#ifndef MEMBERS_MEM_H
#define MEMBERS_MEM_H

#define MEMBER_CAPACITY 1000
#define MEMBER_CODE_LEN 20
#define MEMBER_NAME_LEN 100
#define MEMBER_IDCARD_LEN 12
#define MEMBER_GENDER_LEN 10
#define MEMBER_EMAIL_LEN 40
#define MEMBER_ADDRESS_LEN 120

extern int member_count;

void reset_member_store();

char *member_code_at(int index);
char *member_name_at(int index);
char *member_idcard_at(int index);
char *member_gender_at(int index);
char *member_email_at(int index);
char *member_address_at(int index);

extern int member_birth_day[MEMBER_CAPACITY];
extern int member_birth_month[MEMBER_CAPACITY];
extern int member_birth_year[MEMBER_CAPACITY];
extern int member_issue_day[MEMBER_CAPACITY];
extern int member_issue_month[MEMBER_CAPACITY];
extern int member_issue_year[MEMBER_CAPACITY];
extern int member_expire_day[MEMBER_CAPACITY];
extern int member_expire_month[MEMBER_CAPACITY];
extern int member_expire_year[MEMBER_CAPACITY];

#endif
