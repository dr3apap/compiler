#include "gtest/gtest.h"

extern "C" {
 #include "node.h"
}

TEST(node, new_char_node)
{

    Node *node =  CharNode_new('d');
    NodeType charNode   =   CHAR_NODE;

    ASSERT_EQ(node->type, charNode);


}

TEST(node, new_pair_node)

{
    Node *charNode =  CharNode_new('d');
    Node *charNode1 =  CharNode_new('c');
    Node *node =  PairNode_new(charNode, charNode1);

    NodeType pairNode   =   PAIR_NODE;

    ASSERT_EQ(node->type, pairNode); 
}
    
TEST(node, new_error_node)
{
    Node *node = ErrorNode_new("This is an error");

    NodeType errorNode = ERROR_NODE;
    ASSERT_EQ(node->type, errorNode); 
}

TEST(node, node_pointer_free)
{

    Node *charNode = CharNode_new('a');
    
    void *node = Node_drop(charNode);
    ASSERT_TRUE(node == NULL);
}

