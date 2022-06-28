#include <stdio.h>
#include "node.h"
#include "guard.h"


int main(void)
{

       Node *charNode = CharNode_new('d');

       Node *left =  CharNode_new('d');
       Node *right =  CharNode_new('c');

       Node *node =  PairNode_new(left, right);
       printf("Value of node before free %c\n", node->data.pair.left->data.value);
       printf("Value of charNode before free %c\n", charNode->data.value);

       printf("charNode value before freeing %p\n", charNode);
       printf("Node value before free!! %p\n", node);
       printf("Left value before free!! %p\n", left);
       printf("right value before free!!%p\n", right);

       int result = Node_drop(node);
       int result1 = Node_drop(charNode);
       printf("result of value is %d\n", result);
       printf("result of value is %d\n", result1);

       printf("charNode value after freeing! %p\n", charNode);
       printf("Node value after freeing! %p\n", node);
       printf("Left value after freeing! %p\n", left);
       printf("right value after freeing! %p\n", right);


}

