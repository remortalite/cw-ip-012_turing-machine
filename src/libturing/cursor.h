#ifndef CURSOR_H
#define CURSOR_H

#include <libturing/program.h>
#include <libturing/tape.h>

void start_program(Program, Tape*, Node* cursor);

void make_motion(Tape*, Node* cursor, Motion);
void run_action(Tape*, Action, Node* cursor);

#endif
