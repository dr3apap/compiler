#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "charItr.h"

//static bool charItr_has_next(const CharItr *self)

CharItr charItr_value(const char *start, size_t length)
{

           char *cursor = start;
           char *sentinel = cursor + length;
           CharItr itr = {
                 cursor,
                 sentinel, 
            };

           return itr;
             
}

bool charItr_has_next(const CharItr *self)
{
      return self->cursor != self->sentinel;
}

char charItr_next(CharItr *self)
{
      bool valid = charItr_has_next(self);
      if (valid){
        char lexeme = *(self->cursor);
        self->cursor++;
        return lexeme;
      }

       fprintf(stderr, "Iterator out of bound\n");
       exit(EXIT_FAILURE);

}

char charItr_peek(const CharItr *self)
{
        return *(self->cursor);
}

const char* charItr_cursor(const CharItr *self)
{
    return self->cursor;
}
