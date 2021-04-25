#ifndef PROCESS_FILE_H
#define PROCESS_FILE_H

#include <libturing/program.h>

#include <stdio.h>

char* get_line(FILE*);

char* strip(char*);

char* get_word(char*, char**); // allocate memory for new word

Program fill_program(FILE*, Program);

#endif
