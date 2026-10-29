#ifndef CONTACT_H
#define CONTACT_H

#define NAME_LEN     32
#define PHONE_LEN    16
#define EMAIL_LEN    32
#define MAX_CONTACTS 100


typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
} Contact;

typedef struct {
    Contact items[MAX_CONTACTS];
    int count;
} Book;

void book_init(Book *b);
int  book_add(Book *b, const char *name, const char *phone, const char *email);
int  book_find(const Book *b, const char *name);
int  book_remove(Book *b, const char *name);
int  book_fix(Book *b,const char *name, const char *phone, const char *email);

#endif
