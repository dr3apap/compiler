#include "gtest/gtest.h"

extern "C" {
  #include "node.h"
  #include "scanner.h"
  #include "parser.h"
}


//TEST(parser, return_pairNode)
//{
//   const char buffer[21] = "(a)";
//    int len = strlen(buffer);
//    CharItr itr = charItr_value(buffer, len);
//
//    Scanner scanner = scanner_value(&itr);
//    Node *node = parse(&scanner);
//
//    NodeType charNode = CHAR_NODE;
//
//    ASSERT_EQ(node->type, charNode); 
//    ASSERT_EQ(scanner.next, ')');
//    Node_drop(node);
//}
//
//
//TEST(parser, return_lparen_token)
//{
//   const char buffer[21] = "(a";
//    int len = strlen(buffer);
//    CharItr itr = charItr_value(buffer, len);
//
//    Scanner scanner = scanner_value(&itr);
//    Node *node = parse(&scanner);
//
//    NodeType pairNode = PAIR_NODE;
//
//    ASSERT_EQ(scanner.next, ')');
//
//    ASSERT_EQ(node->type, pairNode); 
//    Node_drop(node);
//}

TEST(parser, return_pair_node)
{
   const char buffer[21] = "(a (a b))";
    int len = strlen(buffer);
    CharItr itr = charItr_value(buffer, len);

    Scanner scanner = scanner_value(&itr);
    Node *node = parse(&scanner);

    NodeType pairNode = PAIR_NODE;

    EXPECT_EQ(scanner.next, ')');
    //EXPECT_EQ(node->type, pairNode); 
    int result = Node_drop(node);
    EXPECT_EQ(result, 0);
}


TEST(parser, return_charNode)
{
    
   const char buffer[21] = "a (a b))";
    int len = strlen(buffer);
    CharItr itr = charItr_value(buffer, len);

    Scanner scanner = scanner_value(&itr);
    Node *node = parse(&scanner);

    NodeType charNode = CHAR_NODE;

    EXPECT_EQ(node->type, charNode); 
    Node_drop(node);
}


