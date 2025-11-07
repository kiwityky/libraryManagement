#ifndef INPUT_H
#define INPUT_H

void trim_text(char *line);
void copy_text(char *dest, const char *src, int limit);
void read_text(const char *label, char *buffer, int limit);
int read_number(const char *label, int min_value, int max_value);
void read_date_prompt(const char *label, int *day, int *month, int *year);
int text_is_empty(const char *text);

#endif
