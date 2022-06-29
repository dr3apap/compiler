#ifndef SCANNER_H
#define SCANNER_H
#include <stdbool.h>
#include "charItr.h"
#include "token.h"

typedef struct Scanner {
    CharItr itr;
    char next;
} Scanner;

Scanner scanner_value(CharItr char_itr);
bool scanner_has_next(const Scanner *self);
Token scanner_peek(const Scanner *self); // peek allow us to call the right routine base on what token we are about to process what state are we? state is our token and lexeme is what correspond to our token in the input
Token token_factory(char lexeme);
Token scanner_next(Scanner *self);
#endif





