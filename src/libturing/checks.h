#ifndef CHECKS_H
#define CHECKS_H

#include <libturing/tape.h>

void check_allocated(struct node*); // ERR_MEMORY_ALLOCATION

void check_symbol(char); // ERR_WRONG_SYMBOL

#endif // CHECKS_H
