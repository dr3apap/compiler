#include "gtest/gtest.h"

extern "C" {
      #include "charItr.h"
      #include <string.h>
}


TEST(charItr, return_charItr)
{
    const char buffer[21] = "(a (a b))";
    CharItr itr = charItr_value(buffer, strlen(buffer));
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
    CharItr itr = charItr_value(buffer, strlen(buffer));

    bool valid = charItr_has_next(&itr);
    ASSERT_TRUE(valid == true);

    charItr_has_next(&itr);
    charItr_has_next(&itr);
    charItr_has_next(&itr);
    charItr_has_next(&itr);
    charItr_has_next(&itr);
    charItr_has_next(&itr);
    charItr_has_next(&itr);
    charItr_has_next(&itr);

    bool line = charItr_has_next(&itr);
    
    ASSERT_FALSE(line == false);
}

TEST(charItr, next_char)
{
    
    const char buffer[21] = "(a (a b))";
    CharItr itr = charItr_value(buffer, 20);

    char next = charItr_next(&itr);
    ASSERT_EQ(next, '(');
    char next_char = charItr_next(&itr);
    ASSERT_EQ(next_char, 'a');
}




