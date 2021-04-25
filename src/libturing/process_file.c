#include <libturing/checks.h>
#include <libturing/process_file.h>
#include <libturing/program.h>

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
*/

Program fill_program(FILE* fin, Program prog)
{
    char *line, *orig_line;
    char* word;
    char* ret;

    char* fstr_parse = "Warning! Can't parse line `%s`\n";
    char* fstr_symb
            = "Warning! Length of `symb_old` is more than 1. Use only first "
              "symbol of `%s`\n";

    char *curr_state, *next_state;
    char symb_old, symb_new, symb_motion;
    Motion motion;

    // process lines
    while (1) {
        line = get_line(fin);
        if (line == NULL)
            break;
        line = strip(line);
        // if line is empty or if it's a comment
        if (line[0] == '\0' || line[0] == ';')
            continue;

        orig_line = calloc(strlen(line) + 1, sizeof(char));
        strcpy(orig_line, line);
        // get field 1: curr_state
        word = get_word(line, &ret);
        if (word == NULL) {
            print_debug_str(fstr_parse, orig_line);
            continue;
        }
        check_statename(word);
        curr_state = word;

        // get field 2: symb_old
        word = get_word(ret, &ret);
        if (word == NULL) {
            print_debug_str(fstr_parse, orig_line);
            continue;
        }
        if (strlen(word) > 1)
            print_debug_str(fstr_symb, word);
        symb_old = word[0];
        // TODO: check symbol

        // get field 3: symb_new
        word = get_word(ret, &ret);
        if (word == NULL) {
            print_debug_str(fstr_parse, orig_line);
            continue;
        }
        if (strlen(word) > 1)
            print_debug_str(fstr_symb, word);
        symb_new = word[0];
        // TODO: check symbol

        // get field 4: motion
        word = get_word(ret, &ret);
        if (word == NULL) {
            print_debug_str(fstr_parse, orig_line);
            continue;
        }
        if (strlen(word) > 1)
            print_debug_str(fstr_symb, word);
        symb_motion = word[0];
        switch (symb_motion) {
        case 'l':
            motion = MOTION_LEFT;
            break;
        case 'r':
            motion = MOTION_RIGHT;
            break;
        case '*':
            motion = MOTION_STAY;
            break;
        default:
            print_debug_str(fstr_parse, orig_line);
            continue;
        };

        // get field 5: next_state
        word = get_word(ret, &ret);
        if (word == NULL) {
            print_debug_str(fstr_parse, orig_line);
            continue;
        }
        check_statename(word);
        next_state = word;

        prog = add_command(
                curr_state, symb_old, symb_new, motion, next_state, prog);
    }
    return prog;
}
