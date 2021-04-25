#ifndef PROGRAM_H
#define PROGRAM_H

#define INIT_LEN_ACTIONS 1
#define INIT_LEN_PROGRAM 4
#define MAX_LEN_STATENAME 64

typedef enum Motion {
    MOTION_LEFT,
    MOTION_RIGHT,
    MOTION_STAY,
} Motion;

typedef struct action* Action;
struct action {
    char symb_old;
    char symb_new;
    Motion motion;
    char* next_state;
};

typedef struct state* State;
struct state {
    char* name;
    Action* actions; // pointer to array of actions
    int len_actions;
    int max_actions; // allocated memory for array actions
};

typedef struct program Program;
struct program {
    char** names;
    State* states;
    int length;     // len of arrays `names` and `states`
    int max_length; // allocated memory for `names` and `states`
};

State create_state(char* name);

Action create_action(char symb_old, char symb_new, Motion motion, char* next);

State add_action(Action, State);

Program create_program(void);

Program add_state(State, Program);

void free_program(Program);

State get_state(char* name, Program);

Action get_action(char* name, char symb, Program);

Program
add_command(char* name, char c_old, char c_new, Motion, char* next, Program);

void print_program(Program);

#endif // PROGRAM_H
