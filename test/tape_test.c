#include <libturing/tape.h>

#include <ctest.h>
#include <stdlib.h>

#define CTEST_SEGFAULT

CTEST(suite_tape, create_tape)
{
    Node tape_res = create_tape();
    ASSERT_NULL(tape_res->prev);
    ASSERT_NULL(tape_res->next);

    free_tape(tape_res);
}

CTEST(suite_tape, add_tape_head)
{
    char symbol = 'a';
    Node first_node = create_tape();
    Node tape = add_node_head(symbol, first_node);

    ASSERT_EQUAL(tape->symbol, symbol);
    ASSERT_NULL(tape->prev);
    ASSERT_NULL(tape->next->next);

    char symbol2 = 'b';
    Node tape2 = add_node_head(symbol2, tape);

    ASSERT_NULL(tape2->prev);
    ASSERT_EQUAL(tape2->symbol, symbol2);
    ASSERT_EQUAL(tape2->next->symbol, symbol);
    ASSERT_NOT_NULL(tape2->next);
    ASSERT_NOT_NULL(tape2->next->prev);
    ASSERT_NULL(tape2->next->next->next);

    free_tape(tape2);
}

CTEST(suite_tape, get_tail)
{
    Node tape = create_tape();
    tape = add_node_head('a', tape);
    tape = add_node_head('b', tape);
    tape = add_node_head('c', tape);

    Node tail = get_tail(tape);
    ASSERT_NULL(tail->next);
    ASSERT_EQUAL(tail->prev->symbol, 'a');
    ASSERT_EQUAL(tail->prev->prev->symbol, 'b');

    free_tape(tape);
}

CTEST(suite_tape, add_node_tail)
{
    Node tape = create_tape();
    tape = add_node_head('a', tape);
    tape = add_node_head('b', tape);

    tape = add_node_tail('d', tape);

    ASSERT_NULL(tape->prev);
    ASSERT_EQUAL(tape->symbol, 'b');
    ASSERT_EQUAL(tape->next->symbol, 'a');
    ASSERT_EQUAL(tape->next->next->symbol, 'd');
    ASSERT_EQUAL(tape->next->next->next->prev->symbol, 'd');
    ASSERT_EQUAL(tape->next->next->prev->symbol, 'a');
    ASSERT_EQUAL(tape->next->prev->symbol, 'b');
    ASSERT_NULL(tape->next->next->next->next);

    free_tape(tape);
}

CTEST(suite_tape, rm_node_head)
{
    Node tape = create_tape();

    tape = rm_node_head(tape);
    ASSERT_NULL(tape->next);
    ASSERT_NULL(tape->prev);

    tape = add_node_head('a', tape);

    tape = rm_node_head(tape);
    ASSERT_NULL(tape->next);
    ASSERT_NULL(tape->prev);

    tape = add_node_head('a', tape);
    tape = add_node_head('b', tape);
    tape = add_node_head('c', tape);

    tape = rm_node_head(tape);

    ASSERT_NULL(tape->prev);
    ASSERT_EQUAL(tape->symbol, 'b');
    ASSERT_EQUAL(tape->next->symbol, 'a');

    free_tape(tape);
}

CTEST(suite_tape, rm_node_tail)
{
    Node tape = create_tape();

    tape = rm_node_tail(tape);
    ASSERT_NULL(tape->next);
    ASSERT_NULL(tape->prev);

    tape = add_node_head('a', tape);

    tape = rm_node_head(tape);
    ASSERT_NULL(tape->next);
    ASSERT_NULL(tape->prev);

    tape = add_node_head('a', tape);
    tape = add_node_head('b', tape);
    tape = add_node_head('c', tape);

    tape = rm_node_head(tape);

    ASSERT_NULL(tape->prev);
    ASSERT_EQUAL(tape->symbol, 'b');
    ASSERT_EQUAL(tape->next->symbol, 'a');
    ASSERT_EQUAL(tape->next->next->prev->symbol, 'a');
    ASSERT_NULL(tape->next->next->next);

    free_tape(tape);
}

CTEST(suite_tape, is_node_last)
{
    int result_exp, result;

    Node tape = create_tape();

    result_exp = 0;
    result = is_node_last(tape);
    ASSERT_EQUAL(result_exp, result);

    tape = add_node_head('a', tape);

    result_exp = 1;
    result = is_node_last(tape);
    ASSERT_EQUAL(result_exp, result);

    tape = add_node_head('b', tape);

    result_exp = 0;
    result = is_node_last(tape);
    ASSERT_EQUAL(result_exp, result);

    result_exp = 1;
    result = is_node_last(tape->next);
    ASSERT_EQUAL(result_exp, result);

    free_tape(tape);
}

CTEST(suite_tape, is_tape_empty)
{
    int result_exp, result;

    Node tape = create_tape();

    result_exp = 1;
    result = is_tape_empty(tape);
    ASSERT_EQUAL(result_exp, result);

    tape = add_node_head('a', tape);
    result_exp = 0;
    result = is_tape_empty(tape);
    ASSERT_EQUAL(result_exp, result);

    tape = rm_node_head(tape);
    result_exp = 1;
    result = is_tape_empty(tape);
    ASSERT_EQUAL(result_exp, result);

    free_tape(tape);
}
