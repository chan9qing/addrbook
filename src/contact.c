#include <string.h>
#include "contact.h"

void book_init(Book *b) {
    b->count = 0;
}

int book_find(const Book *b, const char *name) {
    for (int i = 0; i < b->count; i++) {
        if (strcmp(b->items[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int book_add(Book *b, const char *name, const char *phone, const char *email) {
    if (b->count >= MAX_CONTACTS) return -1;
    if (book_find(b, name) >= 0)  return -2;

    Contact *c = &b->items[b->count];
    strncpy(c->name, name, NAME_LEN - 1);
    c->name[NAME_LEN - 1] = '\0';
    strncpy(c->phone, phone, PHONE_LEN - 1);
    c->phone[PHONE_LEN - 1] = '\0';
    strncpy(c->email, email, EMAIL_LEN - 1);
    c->email[PHONE_LEN - 1] = '\0';
    b->count++;
    return 0;
}

int book_fix(Book *b, const char *name, const char *phone, const char *email){
        int idx = book_find(b, name);
        if(idx < 0) return -1;
        Contact *c = &b->items[idx];
        strncpy(c->name, name, NAME_LEN - 1);
        c->name[NAME_LEN - 1] = '\0';
        strncpy(c->phone, phone, PHONE_LEN - 1);
        c->phone[PHONE_LEN - 1] = '\0';
        strncpy(c->email, email, EMAIL_LEN - 1);
        c->email[PHONE_LEN - 1] = '\0';
        return 0;//已修改contact， 下一步修改ui
}

int book_remove(Book *b, const char *name) {
    int idx = book_find(b, name);
    if (idx < 0) return -1;

    for (int i = idx; i < b->count - 1; i++) {
        b->items[i] = b->items[i + 1];
    }
    b->count--;
    return 0;
}
