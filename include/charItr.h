#ifndef CHARITR_H
#define CHARITR_H
#include <stdbool.h>
#include <stdlib.h>
typedef struct CharItr {
    char *cursor;
    char *sentinel; 
} CharItr;

CharItr charItr_value(const char *start, size_t length);
bool charItr_has_next(const CharItr *self);
char charItr_next(CharItr *self);
char charItr_peek(const CharItr *self);
const char* charItr_cursor(const CharItr *self);
#endif
