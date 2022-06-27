#include <stdlib.h>
#include <stdio.h>
#include "node.h"

Node* OOM_GUARD(void *ptr, char *file, size_t line)
{
    if (ptr != NULL)
        return ptr;
    fprintf(stderr, "Out of memory in %s on line %d\n", file, line);
}


