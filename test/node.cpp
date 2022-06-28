#include "gtest/gtest.h"

extern "C" {
 #include "node.h"
}

TEST(node, new_char_node)
{

    Node *node = CharNode_new('d');
    NodeType charNode = CHAR_NODE;

    EXPECT_EQ(node->type, charNode);
    // memory free
    int result = Node_drop(node);
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
    EXPECT_FALSE(node->type == pairNode);

}
    

TEST(node, new_error_node)
{
    Node *node = ErrorNode_new("This is an error");

    NodeType errorNode = ERROR_NODE;

    EXPECT_EQ(node->type, errorNode); 
    Node_drop(node);
    EXPECT_FALSE(node->type == errorNode);
}

TEST(node, node_pointer_free)
{

    Node *charNode =  CharNode_new('a');
    Node *charNode1 =  CharNode_new('b');
    Node *node =  PairNode_new(charNode, charNode1);


    NodeType pairNode = PAIR_NODE;
    NodeType char_Node = CHAR_NODE;

    // Before memory free
    EXPECT_TRUE(charNode->data.value == 'a');
    EXPECT_TRUE(charNode1->data.value == 'b');

    // Freeing the memory on the heap 
    Node_drop(node);

    // After memory free
    EXPECT_FALSE(charNode->data.value == 'a');
    EXPECT_FALSE(charNode1->data.value == 'b');
    EXPECT_FALSE(node->type == pairNode);
    EXPECT_FALSE(node->data.pair.left->type == char_Node); 
}

