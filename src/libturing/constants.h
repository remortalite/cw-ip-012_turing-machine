#ifndef CONSTANTS_H
#define CONSTANTS_H

// max length of statename
#define MAX_LEN_STATENAME 64

// initial length of arrays: State.actions and Program.states
// used in: src/libturing/program.c
#define INIT_LEN_ACTIONS 1
#define INIT_LEN_PROGRAM 4

// available symbols on tape
// you can't use spaces ` ` (use `_` instead) and `;`
// used in: src/libturing/checks.c
#define AVAIL_SYMBOLS "*_+[]<>:!#-,.()?"

#endif // CONSTANTS_H