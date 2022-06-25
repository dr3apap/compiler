#include "gtest/gtest.h"

extern "C" {
      #include "charItr.h"
      #include <string.h>
}


TEST(charItr, return_charItr)
{
    const char buffer[21] = "(a (a b))";
    CharItr itr = charItr_value(buffer, strlen(buffer));
    CharItr itr1 =  itr;
    //ASSERT_EQ(itr, itr1);
    ASSERT_EQ(itr.cursor, buffer);
    ASSERT_EQ(itr.sentinel, buffer + 9);
}



TEST(charItr, return_cursor)
{
    const char buffer[21] = "(a (a b))";
    CharItr itr = charItr_value(buffer, strlen(buffer));
    const char *cursor1 = charItr_cursor(&itr);
    ASSERT_EQ(cursor1, itr.cursor);
}

TEST(charItr, char_peek)
{
    char c = '(';
    const char buffer[21] = "(a (a b))";
    CharItr itr = charItr_value(buffer, strlen(buffer));


    char lexeme = charItr_peek(&itr);
    ASSERT_EQ(lexeme, c);
}

TEST(charItr, has_next_bool)
{

    const char buffer[21] = "(a (a b))";
    CharItr itr = charItr_value(buffer, 20);

    bool valid = charItr_has_next(&itr);
    ASSERT_TRUE(valid);
    ASSERT_FALSE(valid);
}

TEST(charItr, next_char)
{
    
    const char buffer[21] = "(a (a b))";
    CharItr itr = charItr_value(buffer, 20);

    char next = charItr_next(&itr);
    ASSERT_EQ(next, 'a');
}

