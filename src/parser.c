#include "node.h"
#include "parser.h"
#include "scanner.h"
#define MAX_BUFF_ERR 1024
Node *errorNodes[MAX_BUFF_ERR];
size_t node_ref_count = 0;

static Node* parse_pair(Scanner *scanner);
static Node* parse_char(Scanner *scanner);
static Node* parse_error(Scanner *scanner, char *msg);

Node* parse(Scanner *scanner)
{
   Token token = scanner_peek(scanner);

    switch(token.type){
        case CHAR_TOKEN:
            return parse_char(scanner);
        case LPAREN_TOKEN:
            return parse_pair(scanner);
        default:
            return parse_error(scanner, "expect a '(' or char");
         } 
}


static Node* parse_pair(Scanner *scanner)
{
     Token next = scanner_next(scanner);
     Node *left = parse(scanner);
     if (left->type == ERROR_NODE)
         return left;
     if (scanner->next == ' '){ 
         next = scanner_next(scanner); 
     } else {
         *(errorNodes + node_ref_count) = left;
         ++node_ref_count;
         return parse_error(scanner, "expect a space ' '");
     }
        Node *right = parse(scanner);
        if (right->type == ERROR_NODE)
            return right;
     if (scanner->next == ')') {
         next = scanner_next(scanner);
     } else {
        *(errorNodes + node_ref_count) = PairNode_new(left, right);
        ++node_ref_count;
        return parse_error(scanner, "expect a ')'");
     }
         
      return PairNode_new(left, right);

}

static Node* parse_char(Scanner *scanner)
{

    Token token = scanner_next(scanner);
    return CharNode_new(token.lexeme);
}

static Node* parse_error(Scanner *scanner, char *msg)
{

    return ErrorNode_new(msg);

}

