#include <stdlib.h>
#include <stdbool.h>
#include "charItr.h"

CharItr charItr_value(const char *start, size_t length)
{

           char *cursor = start;
           char *sentinel = start + length;
           CharItr itr = {
                 cursor,
                 sentinel, 
            };

           return itr;
             
}
bool charItr_has_next(const CharItr *self)
{
      return false;
}


char charItr_next(CharItr *self)
{
   return *(self->cursor + 1);
}
char charItr_peek(const CharItr *self)
{
        return *(self->cursor);
}

const char* charItr_cursor(const CharItr *self)
{
    return self->cursor;
}
