#ifndef STORAGE_H
#define STORAGE_H

#include "contact.h"

int storage_save(const Book *b, const char *path);
int storage_load(Book *b, const char *path);

#endif