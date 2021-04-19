#include <libturing/program.h>

#include <stdlib.h>
#include <string.h>

State create_state(char* name)
{
    State state = calloc(1, sizeof(State));
    // TODO: check pointer, symbols, len(name)

    state->name = calloc(MAX_LEN_STATENAME, sizeof(char));
    strcpy(state->name, name);

    Action* act_arr = calloc(INIT_LEN_ACTIONS, sizeof(Action));

    state->actions = act_arr;
    state->len_actions = 0;
    state->max_actions = INIT_LEN_ACTIONS;

    return state;
}

Action
create_action(char symb_old, char symb_new, Motion motion, char* next_state)
{
    Action action = calloc(1, sizeof(Action));
    // TODO: check pointer, symbols, check len(next_state)
    action->symb_old = symb_old;
    action->symb_new = symb_new;
    action->motion = motion;
    action->next_state = calloc(MAX_LEN_STATENAME, sizeof(char));
    strcpy(action->next_state, next_state);
    return action;
}

State add_action(Action action, State state)
{
    if (state->len_actions + 1 > state->max_actions) {
        state->max_actions *= KOEF_ACTIONS_ENLARGE;
        state->actions
                = realloc(state->actions, sizeof(Action) * state->max_actions);
        // TODO: check pointers
    }
    state->actions[state->len_actions++] = action;

    return state;
}
