#include <libturing/tape.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

enum Errors {
    ERR_MEMORY_ALLOCATION = 1,
    ERR_WRONG_SYMBOL,
};

void check_p_allocated(void* pname)
{
    if (pname == NULL) {
        fprintf(stderr, "Cannot allocate memory!\n");
        exit(ERR_MEMORY_ALLOCATION);
    }
}

void check_symbol(char symbol)
{
    // check if symbol is a letter or a number
    // allow to use 0 as correct symbol for pseudoelement
    if (isalnum(symbol) == 0 && symbol != 0) {
        fprintf(stderr, "Wrong symbol: '%c'(%d)!\n", symbol, (int)symbol);
        exit(ERR_WRONG_SYMBOL);
    }
}
