#include "gtest/gtest.h"

extern "C" {
#include "scanner.h"
#include "token.h"
#include "charItr.h"
#include <stdbool.h>
#include <string.h>
}



TEST(scanner, new_scanner)
{
    const char buffer[21] = "(a (a b))";
    int len = strlen(buffer);
    CharItr itr = charItr_value(buffer, len);

    Scanner scanner = scanner_value(&itr);

    ASSERT_EQ(scanner.next, *(itr.cursor));
    ASSERT_EQ(scanner.itr->sentinel, buffer + len);
    ASSERT_EQ(scanner.next, '(');
}
    

TEST(scanner, token_peek)
{

    const char buffer[21] = "(a (a b))";
    int len = strlen(buffer);
    CharItr itr = charItr_value(buffer, len);

    const Scanner scanner = scanner_value(&itr);
    Token token = scanner_peek(&scanner);
    TokenType lparenToken = LPAREN_TOKEN;
    TokenType charToken = CHAR_TOKEN;

    
    ASSERT_EQ(token.type, lparenToken);
    ASSERT_NE(token.type, charToken);

} 


TEST(scanner, has_Next_token)
{

    const char buffer[21] = "(";
    int len = strlen(buffer);
    CharItr itr = charItr_value(buffer, len);

    Scanner scanner = scanner_value(&itr);
    bool valid = scanner_has_next(&scanner);

    charItr_next(&itr);
    valid = scanner_has_next(&scanner);
    ASSERT_EQ(valid, false);
    ASSERT_FALSE(valid == true);
}

TEST(scanner, generate_token)
{
    Token token = token_factory('(');
    Token charToken = token_factory('a');
    Token rparenToken = token_factory(')');
    Token spaceToken = token_factory(' ');

    TokenType lparen_token = LPAREN_TOKEN;
    TokenType char_token = CHAR_TOKEN;
    TokenType rparen_token = RPAREN_TOKEN;
    TokenType space_token = SPACE_TOKEN;

    ASSERT_EQ(token.type, lparen_token);
    ASSERT_EQ(charToken.type, char_token);
    ASSERT_EQ(rparenToken.type, rparen_token);
    ASSERT_EQ(spaceToken.type, space_token);

}

TEST(scanner, get_next_token)
{

    
    const char buffer[21] = "(a (a b))";
    int len = strlen(buffer);
    CharItr itr = charItr_value(buffer, len);

    Scanner scanner = scanner_value(&itr);

    TokenType lparen = LPAREN_TOKEN;
    TokenType charToken = CHAR_TOKEN;
    TokenType rparen = RPAREN_TOKEN;
    TokenType spaceToken = SPACE_TOKEN;

    Token token = scanner_next(&scanner);
    ASSERT_EQ(token.type, lparen);

    Token token1 = scanner_next(&scanner);
    ASSERT_EQ(token1.type, charToken);

    Token token2 = scanner_next(&scanner);
    ASSERT_EQ(token2.type, spaceToken);

    Token token3 = scanner_next(&scanner);
    Token token4 = scanner_next(&scanner);
    Token token5 = scanner_next(&scanner);

    Token token6 = scanner_next(&scanner);
    ASSERT_EQ(token6.type, charToken);

    Token token7 = scanner_next(&scanner);
    ASSERT_EQ(token7.type, rparen);
    Token token8 = scanner_next(&scanner);
    ASSERT_EQ(token8.type, rparen);

    bool valid = scanner_has_next(&scanner);
    EXPECT_TRUE(valid == false);
    ASSERT_EQ(itr.cursor, itr.sentinel);

}
