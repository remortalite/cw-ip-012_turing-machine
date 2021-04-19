#include <libturing/program.h>

#include <ctest.h>
#include <stdlib.h>
#include <string.h>

CTEST(suite_program, create_state)
{
    State state_exp = calloc(1, sizeof(State));
    State state_res = create_state("q1");

    state_exp->name = calloc(MAX_LEN_STATENAME, sizeof(char));
    strcpy(state_exp->name, "q1");
    state_exp->len_actions = 0;
    state_exp->max_actions = INIT_LEN_ACTIONS;

    ASSERT_STR(state_exp->name, state_res->name);
    ASSERT_EQUAL(state_exp->len_actions, state_res->len_actions);
    ASSERT_EQUAL(state_exp->max_actions, state_res->max_actions);
    ASSERT_NOT_NULL(state_res->actions);

    free(state_res->actions);
    free(state_res);
}

CTEST(suite_program, create_action)
{
    Action act_res;

    char symb_old = 'a';
    char symb_new = 'b';
    Motion motion = MOTION_LEFT;
    char* next_state = "q2";

    act_res = create_action(symb_old, symb_new, motion, next_state);

    ASSERT_STR(next_state, act_res->next_state);
    ASSERT_EQUAL(symb_old, act_res->symb_old);
    ASSERT_EQUAL(symb_new, act_res->symb_new);
    ASSERT_EQUAL(motion, act_res->motion);
}

CTEST(suite_program, add_action)
{
    State st = create_state("q1");

    st = add_action(create_action('a', 'b', MOTION_STAY, "q2"), st);
    st = add_action(create_action('b', 'c', MOTION_LEFT, "q1"), st);

    ASSERT_STR("q1", st->name);
    ASSERT_EQUAL(2, st->len_actions);

    ASSERT_EQUAL('a', st->actions[0]->symb_old);
    ASSERT_EQUAL('b', st->actions[1]->symb_old);
    ASSERT_EQUAL('b', st->actions[0]->symb_new);
    ASSERT_EQUAL('c', st->actions[1]->symb_new);
    ASSERT_EQUAL(MOTION_STAY, st->actions[0]->motion);
    ASSERT_EQUAL(MOTION_LEFT, st->actions[1]->motion);
    ASSERT_STR("q2", st->actions[0]->next_state);
    ASSERT_STR("q1", st->actions[1]->next_state);

    free(st->actions[0]);
    free(st->actions[1]);
    free(st);
}
