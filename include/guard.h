#ifndef GUARD_H
#define GUARD_H

#include <stdlib.h>
#include "node.h"

Node* OOM_GUARD(void *ptr, char *file, size_t line);
#endif
