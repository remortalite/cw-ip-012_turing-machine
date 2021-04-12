#include <libturing/tape.h>

#include <stdio.h>
#include <stdlib.h>

struct node* create_tape()
{
    struct node* tape = calloc(1, sizeof(struct node));
    tape->prev = NULL;
    tape->next = NULL;
    return tape;
}

struct node* add_node_head(char symbol, struct node* tape)
{
    struct node* new_head = calloc(1, sizeof(struct node));
    new_head->prev = NULL;
    new_head->next = tape;
    new_head->symbol = symbol;
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
    struct node* new_tail = calloc(1, sizeof(struct node));
    struct node* prev_tail = get_tail(tape);
    new_tail->symbol = symbol;
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
