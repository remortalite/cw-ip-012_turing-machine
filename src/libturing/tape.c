#include <stdio.h>
#include <stdlib.h>

struct node {
    char symbol;
    struct node* prev;
    struct node* next;
};

struct node* create_tape()
{
    struct node* tape = calloc(1, sizeof(struct node));
    tape->prev = NULL;
    tape->next = NULL;
    return tape;
}

struct node* add_tape_head(char symbol, struct node* tape)
{
    struct node* new_head = calloc(1, sizeof(struct node));
    new_head->prev = NULL;
    new_head->next = tape;
    new_head->symbol = symbol;
    tape->prev = new_head;
    return new_head;
}

static struct node* get_tail(struct node* tape)
{
    while (tape->next)
        tape = tape->next;
    return tape;
}

struct node* add_tape_tail(char symbol, struct node* tape)
{
    struct node* new_tail = calloc(1, sizeof(struct node));
    struct node* prev_tail = get_tail(tape);
    prev_tail->prev->next = new_tail;
    new_tail->prev = prev_tail->prev;
    new_tail->next = prev_tail;
    prev_tail->prev = new_tail;
}
