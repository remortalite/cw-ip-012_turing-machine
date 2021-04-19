#ifndef PROGRAM_H
#define PROGRAM_H

#define INIT_LEN_ACTIONS 1
#define MAX_LEN_STATENAME 64
#define KOEF_ACTIONS_ENLARGE 2

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

State create_state(char* name);

Action create_action(char symb_old, char symb_new, Motion motion, char* next);

State add_action(Action, State);

#endif // PROGRAM_H
