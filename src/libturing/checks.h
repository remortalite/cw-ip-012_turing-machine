#ifndef CHECKS_H
#define CHECKS_H

#define check_allocated(p) check_p_allocated((void*)p)

void check_p_allocated(void*); // ERR_MEMORY_ALLOCATION

// check if symbol [a-zA-Z0-9\*] or zero
void check_symbol(char); // ERR_WRONG_SYMBOL

// like check_symbol, but without zero
void check_symbol_inp(char); // ERR_WRONG_SYMBOL

void print_debug_str(char* fstr, char* line); // warning, doesn't raise error

void check_statename(char*); // ERR_STATEMENT_LONG

#endif // CHECKS_H