#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
typedef enum {
    ERROR_NODE = 1,
    CHAR_NODE = 2,
    PAIR_NODE = 3,
} NodeType;

typedef struct Node Node; // forward declaration

typedef struct PairValue {
    Node *left;
    Node *right;
} PairValue;


typedef char CharValue;
typedef const char *ErrorValue;


typedef union {
     CharValue value;
     ErrorValue error;
     PairValue pair;
} NodeValue;



struct Node {
    NodeType type;
    NodeValue data;
};




Node* CharNode_new(char c);
Node* PairNode_new(Node *left, Node *right);
Node* ErrorNode_new(const char *msg);
int Node_drop(Node *self);
#endif
