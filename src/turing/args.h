#ifndef ARGS_H
#define ARGS_H

struct _params {
    char* input;
    char* output;
    char* startfile;
    short silent;
};

void parse_args(struct _params* params, int argc, char** argv);

#endif
