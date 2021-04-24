#include <libturing/checks.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char* strip(char* line)
{
    if (line == NULL)
        return NULL;
    int i = 0;
    int length = strlen(line);

    for (i = 0; line[i] == ' ' || line[i] == '\n'; i++)
        ;
    if (i > 0)
        memmove(line, line + i, length + 1);
    for (i = length + 1;; i--) {
        if (line[i] == ' ' || line[i] == '\n' || line[i] == '\r'
            || line[i] == '\0')
            line[i] = '\0';
        else
            break;
    }
    return line;
}

char* get_word(char* line)
{
    // return first word
    int len = strcspn(line, " ");
    char* word = calloc(len + 2, sizeof(char));
    check_allocated(word);
    strncpy(word, line, len);
    word[len - 1] = '\0';
    word = strip(word);
    if (word[0] == '\0') {
        free(word);
        return NULL;
    }
    return word;
}
/*
char* split(char* line) {
        int i;
        for (i = 0; line[i] != ' ' && line[i] != '\0'; i++) {

        }
        if (line[0] == '\0')
                return NULL;

}

Program fill_program(FILE* fin, Program prog)
{
    char* line;
    while ((line = get_line(fin)) != NULL) {
        line = strip(line);
                while (
    }
}
*/
