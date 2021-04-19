#include <libturing/checks.h>
#include <libturing/tape.h>

#include <stdio.h>
#include <stdlib.h>

struct node* create_node(char symbol)
{
    struct node* new_node = calloc(1, sizeof(struct node));
    check_allocated(new_node);
    check_symbol(symbol);
    new_node->symbol = symbol;
    new_node->prev = NULL;
    new_node->prev = NULL;
    return new_node;
}

struct node* create_tape()
{
    return create_node(0);
}

struct node* add_node_head(char symbol, struct node* tape)
{
    struct node* new_head = create_node(symbol);
    new_head->prev = NULL;
    new_head->next = tape;
    tape->prev = new_head;
    return new_head;
}

struct node* get_tail(struct node* tape)
{
    while (tape->next)
        tape = tape->next;
    return tape;
}

struct node* add_node_tail(char symbol, struct node* tape)
{
    struct node* new_tail = create_node(symbol);
    struct node* prev_tail = get_tail(tape);
    prev_tail->prev->next = new_tail;
    new_tail->prev = prev_tail->prev;
    new_tail->next = prev_tail;
    prev_tail->prev = new_tail;
    return tape;
}

struct node* rm_node_head(struct node* tape)
{
    if (tape->next == NULL)
        return tape;
    tape = tape->next;
    free(tape->prev);
    tape->prev = NULL;
    return tape;
}

struct node* rm_node_tail(struct node* tape)
{
    if (tape->next == NULL)
        return tape;

    struct node* tail = get_tail(tape);
    if (tail->prev->prev == NULL)
        return tail;
    struct node* rm_node = tail->prev;
    tail->prev = tail->prev->prev;
    tail->prev->next = tail;
    free(rm_node);
    return tape;
}
