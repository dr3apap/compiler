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
    TokenType charToken = CHAR_TOKEN;
    TokenType pairToken = PAIR_TOKEN;

    
    ASSERT_EQ(token.type, pairToken);
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
    Token token1 = token_factory('a');
    Token token2 = token_factory(')');

    TokenType pairToken = PAIR_TOKEN;
    TokenType charToken = CHAR_TOKEN;

    ASSERT_EQ(token.type, pairToken);
    ASSERT_EQ(token1.type, charToken);
}

TEST(scanner, get_next_token)
{

    
    const char buffer[21] = "(a";
    int len = strlen(buffer);
    CharItr itr = charItr_value(buffer, len);

    Scanner scanner = scanner_value(&itr);
    Token token = scanner_next(&scanner);

    TokenType type = CHAR_TOKEN;
    TokenType type1 = PAIR_TOKEN;

    ASSERT_EQ(token.type, type1);
    ASSERT_NE(token.type, type);
}
