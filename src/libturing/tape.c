#include <libturing/checks.h>
#include <libturing/tape.h>

#include <stdio.h>
#include <stdlib.h>

Node create_node(char symbol)
{
    Node new_node = calloc(1, sizeof(struct node));
    check_allocated(new_node);
    check_symbol(symbol);
    new_node->symbol = symbol;
    new_node->prev = NULL;
    new_node->prev = NULL;
    return new_node;
}

Node create_tape()
{
    return create_node(0);
}

Node add_node_head(char symbol, Node tape)
{
    Node new_head = create_node(symbol);
    new_head->prev = NULL;
    new_head->next = tape;
    tape->prev = new_head;
    return new_head;
}

Node get_tail(Node tape)
{
    // return pseudoelement from the tail
    while (tape->next)
        tape = tape->next;
    return tape;
}

Node add_node_tail(char symbol, Node tape)
{
    Node new_tail = create_node(symbol);
    Node prev_tail = get_tail(tape);
    prev_tail->prev->next = new_tail;
    new_tail->prev = prev_tail->prev;
    new_tail->next = prev_tail;
    prev_tail->prev = new_tail;
    return tape;
}

Node rm_node_head(Node tape)
{
    if (tape->next == NULL)
        return tape;
    tape = tape->next;
    free(tape->prev);
    tape->prev = NULL;
    return tape;
}

Node rm_node_tail(Node tape)
{
    if (tape->next == NULL)
        return tape;

    Node tail = get_tail(tape);
    if (tail->prev->prev == NULL)
        return tail;
    Node rm_node = tail->prev;
    tail->prev = tail->prev->prev;
    tail->prev->next = tail;
    free(rm_node);
    return tape;
}

int is_node_last(Node node)
{
    // returns 1 if node is last 'real' node (doesn't include pseusoelement)
    if (node->next == NULL)
        return 0;
    else if (node->next->next == NULL)
        return 1;
    return 0;
}
