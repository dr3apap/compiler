#include "gtest/gtest.h"

extern "C" {
 #include "node.h"
}

TEST(node, new_char_node)
{

    Node *node = CharNode_new('d');
    NodeType charNode = CHAR_NODE;

    EXPECT_EQ(node->type, charNode);
    int result = Node_drop(node);
    //EXPECT_TRUE(node == nullptr);
    EXPECT_EQ(result, 0);
}

TEST(node, new_pair_node)

{
    Node *charNode =  CharNode_new('d');
    Node *charNode1 =  CharNode_new('c');
    Node *node =  PairNode_new(charNode, charNode1);

    NodeType pairNode = PAIR_NODE;
    NodeType char_Node = CHAR_NODE;

    EXPECT_EQ(node->type, pairNode); 
    Node_drop(node);


    //EXPECT_TRUE(charNode->type == char_Node);
    //EXPECT_TRUE(charNode1->type == char_Node);
    //EXPECT_TRUE(node->type == pairNode);


    EXPECT_TRUE(node == nullptr); 
    EXPECT_TRUE(charNode == nullptr);
    EXPECT_TRUE(charNode1 == nullptr);
}
//    
//TEST(node, new_error_node)
//{
//    Node *node = ErrorNode_new("This is an error");
//
//    NodeType errorNode = ERROR_NODE;
//
//    EXPECT_EQ(node->type, errorNode); 
//    Node_drop(node);
//    EXPECT_TRUE(node == nullptr);
//}
//
//TEST(node, node_pointer_free)
//{
//
//    Node *charNode = CharNode_new('a');
//
//    NodeType char_node = CHAR_NODE;
//    
//    Node_drop(charNode);
//    EXPECT_TRUE(charNode == nullptr);
//    //EXPECT_TRUE(charNode->type == jchar_node);
//}

