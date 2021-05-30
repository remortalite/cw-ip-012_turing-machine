#ifndef ARGS_H
#define ARGS_H

#define INPUT_DEFAULT "./turing.txt"
#define OUTPUT_DEFAULT NULL
#define STARTFILE_DEFAULT NULL
#define SILENTMODE_DEFAULT 0

#define MAX_FILENAME 32

struct params {
    char* input;
    char* output;
    char* startfile;
    short silent;
};

void parse_args(struct params*, int argc, char** argv);

char* get_input_filename();

void get_missing_params(struct params*);

void print_params(struct params);

#endif
