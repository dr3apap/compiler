#include <stdlib.h>
#include <stdbool.h>
#include "scanner.h"
#include "charItr.h"
#include "token.h"

//static bool scanner_has_next(const Scanner *self)

Scanner scanner_value(CharItr *char_itr)
{
    char next = *(char_itr->cursor); 
    Scanner scanner = {
        char_itr,
        next,
    };
    return scanner;
}

Token scanner_peek(const Scanner *self)
{

     char next_token = self->next;
    if (next_token == '(' || next_token == ' ' || next_token == ')' || next_token != '(') 
        return token_factory(next_token);
}

Token scanner_next(Scanner *self)
{

           bool valid = scanner_has_next(self);
           
           if (valid){

           Token token = token_factory(self->next);
           charItr_next(self->itr);
           return token;
           }
}


bool scanner_has_next(const Scanner *self)
{
     bool valid = charItr_has_next(self->itr);
    if (valid ){ 
        char lexeme = self->next;
        return lexeme == '(' || lexeme == ' ' || lexeme == ')' || lexeme != '('; 
    }
    return valid;
}


Token token_factory(char lexeme)
{
       if (lexeme == '('){
           TokenType type = PAIR_TOKEN;
           Token token = {
               type,
               lexeme
           };
           return token;
       }

       else if (lexeme != '(' && lexeme != ')' && lexeme != ' '){

           TokenType type = CHAR_TOKEN;
           Token token = {
               type,
               lexeme
           };
           return token;
       } else {
           TokenType type = ERROR_TOKEN;
           Token token = {
               type,
               lexeme
           };
           return token;
       }
}
           




