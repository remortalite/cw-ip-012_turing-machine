#ifndef CHECKS_H
#define CHECKS_H

#define check_allocated(p) check_p_allocated((void*)p)

void check_p_allocated(void*); // ERR_MEMORY_ALLOCATION

void check_symbol(char); // ERR_WRONG_SYMBOL

#endif // CHECKS_H
