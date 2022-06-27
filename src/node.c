#include <stdlib.h>

#include "guard.h"
#include "node.h"

Node* CharNode_new(char c)
{
    Node *node = OOM_GUARD(malloc(sizeof(Node)), __FILE__, __LINE__);
    node->type = CHAR_NODE;
    node->data.value = c;
    return node;
}

Node* PairNode_new(Node *left, Node *right)
{
    Node *node = OOM_GUARD(malloc(sizeof(Node)), __FILE__, __LINE__);
    node->type = PAIR_NODE;
    node->data.pair.left = left;
    node->data.pair.right = right;
    return node;

}
    

Node* ErrorNode_new(const char *msg)
{

    Node *node = OOM_GUARD(malloc(sizeof(Node)), __FILE__, __LINE__);
    node->type = ERROR_NODE;
    node->data.error = msg;
    return node;
}
    
void* Node_drop(Node *self)
{
    free(self);
    self = NULL;
    return self;
}
