#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "parser.h"
#include "node.h"
#include "guard.h"
#include "scanner.h"
#include "token.h"
#include "charItr.h"

#define MAX_BUFFER_LENGTH 1024

static void ErrorNode_drop(Node **node, size_t ref_count);
static bool read_next_line(char *buffer, size_t len);
static void node_print(Node *node, size_t spaces);
static void indent(size_t spaces);

int main(void)
{
    char buffer[MAX_BUFFER_LENGTH + 1];
    extern Node *errorNodes[MAX_BUFFER_LENGTH];
    extern size_t node_ref_count;

    memset(buffer, '\0', sizeof(buffer));

    while (read_next_line(buffer, MAX_BUFFER_LENGTH)){
            CharItr itr = charItr_value(buffer, strlen(buffer));
            Scanner scanner = scanner_value(itr);
            Node *node = parse(&scanner);
            node_print(node, 0);
            Node_drop(node);
        }

            ErrorNode_drop(errorNodes, node_ref_count); // Clean up all memory allocated for nodes that resulted in error.
}

static bool read_next_line(char *buffer, size_t length)
{
    char c;
    bool valid = false;
    size_t len = 0;

    while ((c = getchar()) != EOF && len <= length && c != '\n' ){
        buffer[len] = c;
        len++;
    }

    if (len > 0) 
        valid = true;
    return valid;
}


static void node_print(Node *node, size_t spaces)
{
    indent(spaces);
    if (node->type == CHAR_NODE)
        printf("Char('%c')\n", node->data.value);
    if (node->type == PAIR_NODE){
        printf("Pair(\n");
        node_print(node->data.pair.left, spaces + 2);
        node_print(node->data.pair.right, spaces + 2);
        indent(spaces);
        printf(")\n");
    } else if (node->type == ERROR_NODE){
        fprintf(stderr, "Error: %s\n", node->data.error);
    }

}

static void indent(size_t spaces)
{
    for (size_t i = 0; i < spaces; i++)
        putchar(' ');
}


static void ErrorNode_drop(Node **node, size_t ref_count)
{
    while (ref_count > 0){
        Node_drop(*node);
        ++node;
        --ref_count;
    }
}
