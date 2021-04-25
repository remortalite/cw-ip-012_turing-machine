#include <libturing/checks.h>
#include <libturing/process_file.h>
#include <libturing/program.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NFIELDS 5

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

    for (i = length - 1; i >= 0; i--) {
        if (line[i] == ' ' || line[i] == '\n' || line[i] == '\r'
            || line[i] == '\0') {
            line[i] = '\0';
        } else
            break;
    }
    for (i = 0; line[i] == ' ' || line[i] == '\n'; i++)
        ;
    if (i > 0)
        memmove(line, line + i, length + 1);
    return line;
}

char* get_word(char* line, char** ret)
{
    // return first word
    line = strip(line);
    int len = strcspn(line, " ");
    char* word = calloc(len + 1, sizeof(char));
    check_allocated(word);
    strncpy(word, line, len);
    word[len] = '\0';
    word = strip(word);
    if (word[0] == '\0') {
        free(word);
        return NULL;
    }
    *ret = line + len;
    return word;
}
/*
static Word* create_list() {
        Word* words = calloc(1, sizeof(Word));
        check_allocated(words);
        words->next = NULL;
        return words;
}

static Word* add_word(char* name, Word* words) {
        Word* new_word = calloc(1, sizeof(Word));
        check_allocated(new_word);
        new_word->name = calloc(strlen(name)+1, sizeof(char));
        check_allocated(new_word->name);
        strcpy(new_word->name, name);
        new_word->next = words;
        return new_word;
}

static void free_words(Word* words) {
        Word* prev = words;
        while (words) {
                prev = words;
                words = words->next;
                free(prev);
        }
}

Word* split(char* line) {
        int i;

                Word* words = create_list();
                char* new_word;
                while ((new_word = get_word(line)) != NULL) {
                        words = add_word(new_word, words);
                        line = strstr(line, new_word);
                }

                return words;

                free_words(words);;

        for (i = 0; line[i] != ' ' && line[i] != '\0'; i++) {

        }
        if (line[0] == '\0')
                return NULL;

}


Program fill_program(FILE* fin, Program prog)
{
    char* line;
        char* word;
        char* ret;
        int nfield;
        char** fields = calloc(NFIELDS, sizeof(char*));
    while ((line = get_line(fin)) != NULL) {
                nfield = 0;
        while (nfield <= NFIELDS) {
                        word = get_word(line, &ret);
                        if (word != NULL) {
                                fields[nfield++] = word;
                        }
                        if (ret == NULL)
                                break;
                        line = ret;
                }
                if (nfield == 5) {
                        prog = add_command(fields[0], fields[1][0],
fields[2][0], MOTION_LEFT, fields[4], prog); } else { fprintf(stderr, "Not
enough fields in line\n");
                }
    }
        return prog;
}
*/
