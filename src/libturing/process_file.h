#ifndef PROCESS_FILE_H
#define PROCESS_FILE_H

#include <libturing/program.h>

#include <stdio.h>

char* get_line(FILE*);

char* strip(char*);

// get_word:
// strip `line` using strip()
// allocate memory for new word
// save in `ret` pointer to next symbol after `word` (rest of the line)
// return: word or NULL
char* get_word(char* line, char** ret);

Program fill_program(FILE*, Program);

#endif
