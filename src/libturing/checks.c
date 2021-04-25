#include <libturing/program.h>
#include <libturing/tape.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Errors {
    ERR_MEMORY_ALLOCATION = 1,
    ERR_WRONG_SYMBOL,
    ERR_STATENAME_LONG,
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

void print_debug_str(char* fstr, char* line)
{
    if (fstr == line) { // do nothing; compiler warn about unusable vars
    }
#ifdef DEBUG
    fprintf(stderr, fstr, line);
#endif
}

void check_statename(char* statename)
{
    if (strlen(statename) >= MAX_LEN_STATENAME) {
        fprintf(stderr,
                "Error! Too long statename, can't be more than %d! Statename: "
                "`%s` (%d symbols)\n",
                MAX_LEN_STATENAME - 1,
                statename,
                (int)strlen(statename));
        exit(ERR_STATENAME_LONG);
    }
}
