#include <stdlib.h>
#include <stdio.h>
#include "node.h"

Node* OOM_GUARD(void *ptr, char *file, size_t line)
{
    if (ptr == NULL){ 
        fprintf(stderr, "Out of memory in %s on line %ld\n", file, line);
        exit(EXIT_FAILURE);
    }
    return ptr;
}


