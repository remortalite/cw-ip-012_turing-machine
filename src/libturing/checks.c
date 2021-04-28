#include <libturing/program.h>
#include <libturing/tape.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AVAIL_SYMBOLS "*_+[]<>:!#-,."

enum Errors {
    ERR_MEMORY_ALLOCATION = 1,
    ERR_WRONG_SYMBOL,
    ERR_STATENAME_LONG,
    ERR_STATENAME_CHAR,
};

void check_p_allocated(void* pname, int line)
{
    if (pname == NULL) {
        fprintf(stderr, "LINE %d: Cannot allocate memory!\n", line);
        exit(ERR_MEMORY_ALLOCATION);
    }
}

static int is_symb_in(char symbol, char* available)
{
    int i;
    for (i = 0; i < (int)strlen(available); i++) {
        if (symbol == available[i])
            return 1;
    }
    return 0;
}

static int is_symb_correct(char symbol)
{
    if (isalnum(symbol) || is_symb_in(symbol, AVAIL_SYMBOLS))
        return 1;
    return 0;
}

void check_symbol(char symbol)
{
    // check if symbol is correct
    // allow to use 0 as correct symbol for pseudoelement
    if (is_symb_correct(symbol) == 0 && symbol != 0) {
        fprintf(stderr, "Wrong symbol: '%c'(%d)!\n", symbol, (int)symbol);
        exit(ERR_WRONG_SYMBOL);
    }
}

void check_symbol_inp(char symbol)
{
    if (is_symb_correct(symbol) == 0) {
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

static void check_statename_len(const char* statename)
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

static void check_statename_char(const char* statename)
{
    int i;
    for (i = 0; i < (int)strlen(statename); i++) {
        if (isalnum(statename[i]) == 0) {
            fprintf(stderr,
                    "Error! Can't use char `%c` in statename `%s`!\n",
                    statename[i],
                    statename);
            exit(ERR_STATENAME_CHAR);
        }
    }
}

void check_statename(const char* statename)
{
    check_statename_len(statename);
    check_statename_char(statename);
}
