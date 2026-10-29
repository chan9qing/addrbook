#ifndef UI_H
#define UI_H

#include "contact.h"

void ui_menu(void);
void ui_show_all(const Book *b);
void ui_read_line(const char *prompt, char *buf, int size);

#endif
