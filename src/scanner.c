#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "scanner.h"
#include "charItr.h"
#include "token.h"

//static bool scanner_has_next(const Scanner *self)

Scanner scanner_value(CharItr char_itr)
{
    char next = *(char_itr.cursor); 
    Scanner scanner = {
        char_itr,
        next,
    };
    return scanner;
}

Token scanner_peek(const Scanner *self)
{
        return token_factory(self->next);
}

Token scanner_next(Scanner *self)
{

           bool valid = scanner_has_next(self);
           if (valid){
           Token token = token_factory(charItr_next(&(self->itr)));
           self->next = *(self->itr.cursor);
           return token;
           }

           fprintf(stderr, "Scanner out of bound\n");
           exit(EXIT_FAILURE);
}


bool scanner_has_next(const Scanner *self)
{
     return charItr_has_next(&(self->itr));
}


Token token_factory(char lexeme)
{
       if (lexeme == '('){
           Token token = {
               LPAREN_TOKEN,
               lexeme
           };
           return token;

       } else if (lexeme == '\0') {
           Token token = {
               END_TOKEN,
               lexeme
           };
           return token;
       } else if (lexeme != '(' && lexeme != ')' && lexeme != ' '){

           Token token = {
               CHAR_TOKEN,
               lexeme
           };
           return token;

       } else if (lexeme == ')'){
           Token token = {
               RPAREN_TOKEN,
               lexeme
           };
           return token;

       } else if (lexeme == ' ') {
           Token token = {
               SPACE_TOKEN,
               lexeme
           };
           return token;

       } else {
           
           Token token = {
               ERROR_TOKEN,
               lexeme
           };
           return token;
       }
}
           




