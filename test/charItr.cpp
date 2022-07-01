#include "gtest/gtest.h"

extern "C" {
      #include "charItr.h"
      #include <string.h>
}


TEST(charItr, return_charItr)
{
    const char buffer[21] = "(a (a b))";
    int len = strlen(buffer);
    CharItr itr = charItr_value(buffer, len);
    ASSERT_EQ(itr.cursor, buffer);
    ASSERT_EQ(itr.sentinel, buffer + len);
}



TEST(charItr, return_cursor_position)
{
    const char buffer[21] = "(a (a b))";
    CharItr itr = charItr_value(buffer, strlen(buffer));
    const char *cursor1 = charItr_cursor(&itr);
    ASSERT_EQ(cursor1, itr.cursor);
}

TEST(charItr, peek_at_current_lexeme)
{
    const char buffer[21] = "(a (a b))";
    CharItr itr = charItr_value(buffer, strlen(buffer));

    char lexeme = charItr_peek(&itr);
    ASSERT_EQ(lexeme, '(');
}

TEST(charItr, has_next_bool)
{
    const char buffer[21] = "(a (a b))";
    CharItr itr = charItr_value(buffer, strlen(buffer));

    bool valid = charItr_has_next(&itr);
    EXPECT_TRUE(valid == true);

    charItr_next(&itr);
    charItr_next(&itr);
    charItr_next(&itr);
    charItr_next(&itr);
    charItr_next(&itr);
    charItr_next(&itr);
    charItr_next(&itr);
    charItr_next(&itr);
    charItr_next(&itr);


    bool cursor = charItr_has_next(&itr);
    
    EXPECT_TRUE(cursor == false);
}

TEST(charItr, has_next_cursor)
{
    const char buffer[21] = "(";
    CharItr itr = charItr_value(buffer, strlen(buffer));

    bool valid = charItr_has_next(&itr);
    EXPECT_TRUE(valid == true);
    charItr_next(&itr);
    valid = charItr_has_next(&itr);
    EXPECT_TRUE(valid == false);
}


TEST(charItr, next_char)
{
    
    const char buffer[21] = "(a (a b))";
    CharItr itr = charItr_value(buffer, strlen(buffer));

    char next = charItr_next(&itr);
    ASSERT_EQ(next, '(');
    char next_char = charItr_next(&itr);
    ASSERT_EQ(next_char, 'a');
}



TEST(charItr, charItr_contract_test)
{
    // Object Initialization/instance and first method/routine run on instance
    
    const char buffer[10] = "(a (a b))";
    int len = strlen(buffer);
    CharItr itr = charItr_value(buffer, len);
    ASSERT_EQ(itr.cursor, buffer);
    ASSERT_EQ(itr.sentinel, buffer + len);

    const char *cursor = charItr_cursor(&itr);
    ASSERT_EQ(cursor, itr.cursor);

    char lexeme = charItr_peek(&itr);
    ASSERT_EQ(lexeme, '(');


    bool valid = charItr_has_next(&itr);
    EXPECT_TRUE(valid == true);

    char next = charItr_next(&itr);
    ASSERT_EQ(next, '(');

// Second routine/method on object/instance, poiter is mutated and value should be mutated 

    
    const char *cursor1 = charItr_cursor(&itr);
    ASSERT_NE(cursor, cursor1);
    
    lexeme = charItr_peek(&itr);
    ASSERT_EQ(lexeme, 'a');

    valid = charItr_has_next(&itr);
    EXPECT_TRUE(valid == true);

    next = charItr_next(&itr);
    ASSERT_EQ(next, 'a');

    charItr_next(&itr);            
    charItr_next(&itr);
    charItr_next(&itr);
    charItr_next(&itr);
    charItr_next(&itr);
    charItr_next(&itr);
    charItr_next(&itr);

    const char *cursor2 = charItr_cursor(&itr);
    ASSERT_NE(cursor1, cursor2);

    valid = charItr_has_next(&itr);
    
    EXPECT_TRUE(valid == false);

    ASSERT_EQ(*(itr.sentinel), '\0');
    ASSERT_EQ(itr.cursor, itr.sentinel);
}







