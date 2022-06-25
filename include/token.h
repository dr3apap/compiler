#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    END_TOKEN = 0,
    CHAR_TOKEN = 1,
    SPACE_TOKEN = 2,
    LPAREN_TOKEN = 3,
    RPAREN_TOKEN =  4,
    ERROR_TOKEN  = 5,
    PAIR_TOKEN =  6,
}TokenType;

typedef struct Token {
    TokenType type;
    char lexeme;
}Token;

#endif

