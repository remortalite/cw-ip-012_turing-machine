#include <libturing/checks.h>

#include <stdio.h>
#include <stdlib.h>

static int end_of_line(char c)
{
    int eol;

    eol = (c == '\r' || c == '\n');
    return eol;
}

char* get_line(FILE* fin)
{
    int i;
    char c;
    int maxline = 2;
    char* line = calloc(maxline, sizeof(char));

    for (i = 0; (c = getc(fin)) != EOF && !end_of_line(c); i++) {
        if (i >= maxline - 1) {
            // realloc
            maxline *= 2;
            char* newl = realloc(line, maxline);
            check_allocated(newl);
            line = newl;
        }
        line[i] = c;
    }
    line[i] = '\0';

    return (c == EOF && i == 0) ? NULL : line;
}
