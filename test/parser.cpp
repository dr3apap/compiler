#include "gtest/gtest.h"

extern "C" {
  #include "node.h"
  #include "scanner.h"
  #include "parser.h"
}



TEST(parser, return_pair_node)
{
   const char buffer[21] = "(a b))";
    int len = strlen(buffer);
    CharItr itr = charItr_value(buffer, len);

    Scanner scanner = scanner_value(itr);
    Node *node = parse(&scanner);


    EXPECT_EQ(scanner.next, ')');
    EXPECT_EQ(node->type, PAIR_NODE); 
    int result = Node_drop(node);
}

TEST(parser, expect_lparen_or_char_error_node)
{
   const char buffer[21] = {'(', '\0'};
    int len = strlen(buffer);
    CharItr itr = charItr_value(buffer, len);

    Scanner scanner = scanner_value(itr);
    Node *node = parse(&scanner);

    EXPECT_EQ(node->type, ERROR_NODE);
    
    EXPECT_EQ(scanner_peek(&scanner).type, END_TOKEN);
    EXPECT_STREQ(node->data.error, "expect a '(' or char"); 
    int result = Node_drop(node);
}

TEST(parser, return_expect_space_error_node)
{
   const char buffer[21] = "(a";
    int len = strlen(buffer);
    CharItr itr = charItr_value(buffer, len);

    Scanner scanner = scanner_value(itr);
    Node *node = parse(&scanner);


    EXPECT_EQ(node->type, ERROR_NODE); 
    EXPECT_STREQ(node->data.error, "expect a space ' '"); 
    int result = Node_drop(node);
}

TEST(parser, return_expect_rparen_error_node)
{
   const char buffer[21] = "(a b";
    int len = strlen(buffer);
    CharItr itr = charItr_value(buffer, len);

    Scanner scanner = scanner_value(itr);
    Node *node = parse(&scanner);


    EXPECT_EQ(node->type, ERROR_NODE); 
    EXPECT_STREQ(node->data.error, "expect a ')'"); 
    int result = Node_drop(node);
}



TEST(parser, return_expect_lparen_or_char_error_node)
{
   const char buffer[21] = " ";
    int len = strlen(buffer);
    CharItr itr = charItr_value(buffer, len);

    Scanner scanner = scanner_value(itr);
    Node *node = parse(&scanner);

    EXPECT_EQ(node->type, ERROR_NODE); 
    EXPECT_STREQ(node->data.error, "expect a '(' or char"); 
    int result = Node_drop(node);
}





TEST(parser, return_charNode)
{
    
   const char buffer[21] = "a (a b))";
    int len = strlen(buffer);
    CharItr itr = charItr_value(buffer, len);

    Scanner scanner = scanner_value(itr);
    Node *node = parse(&scanner);

    NodeType charNode = CHAR_NODE;

    EXPECT_EQ(node->type, charNode); 
    Node_drop(node);
}


