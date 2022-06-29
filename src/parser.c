#include "node.h"
#include "parser.h"
#include "scanner.h"
Node *errorNodes[];
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
            return parse_error(scanner, "expect a ( or char");
         } 
}


static Node* parse_pair(Scanner *scanner)
{
     Token next = scanner_next(scanner);
     Node *left = parse(scanner);
     if (scanner->next == ' '){ 
         next = scanner_next(scanner); 
     } else {
         errorNodes[node_ref_count] = parse_error(scanner, "expect a space");
         node_ref_count++;
     }
     Node *right = parse(scanner);
     if (scanner->next == ')') {
         next = scanner_next(scanner);
     } else {
       errorNodes[node_ref_count]  = parse_error(scanner, "expect a )");
       node_ref_count++;
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

