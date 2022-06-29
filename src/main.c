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
char buffer[MAX_BUFFER_LENGTH + 1];

void ErrorNOde_drop(Node *node, size_t ref_count);
bool read_next_line(char *buffer, size_t len);
void node_print(Node *node, size_t spaces);
void indent(size_t spaces);
void zero_out_buffer(char *buffer, size_t len);

int main(void)
{
    extern Node *errorNodes; 
    extern size_t node_ref_count;

    zero_out_buffer(buffer, MAX_BUFFER_LENGTH);

    while (read_next_line(buffer, MAX_BUFFER_LENGTH)){
            CharItr itr = charItr_value(buffer, strlen(buffer));
            Scanner scanner = scanner_value(itr);
            Node *node = parse(&scanner);
            node_print(node, 0);
            Node_drop(node);
        }
    
        ErrorNOde_drop(errorNodes, node_ref_count);
}

bool read_next_line(char *buffer, size_t length)
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

void zero_out_buffer(char *buffer, size_t len)
{
    for (int i = 0; i <= len; i++)
        buffer[i] = '\0';
}


void node_print(Node *node, size_t spaces)
{
    NodeType charNode = CHAR_NODE;
    NodeType pairNode = PAIR_NODE;
    //NodeType errorNode = ERROR_NODE;

    if (node->type == charNode)
        printf("Char('%c')\n", node->data.value);
    if (node->type == pairNode){
        printf("Pair(\n");
        node_print(node->data.pair.left, 0);
        node_print(node->data.pair.right, 0);
        printf(")\n");
    } else if (node->type == ERROR_NODE){
        printf("Error('%s')\n", node->data.error);
    }

}

void indent(size_t spaces)
{
    for (int i = 0; i < spaces; i++)
        printf("    \n");
}


void ErrorNOde_drop(Node *node, size_t ref_count)
{
    while (ref_count > 0){
        Node_drop(node);
        --ref_count;
    }
}
