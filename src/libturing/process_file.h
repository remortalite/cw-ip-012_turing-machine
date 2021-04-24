#ifndef PROCESS_FILE_H
#define PROCESS_FILE_H

#include <stdio.h>

char* get_line(FILE*);

char* strip(char*);

char* get_word(char*); // allocate memory for new word

#endif
