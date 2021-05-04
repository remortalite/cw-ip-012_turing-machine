#ifndef TAPE_H
#define TAPE_H

typedef struct node* Node;
struct node {
    char symbol;
    struct node* prev;
    struct node* next;
};

typedef struct tape Tape;
struct tape {
    Node head;
    Node tail;
    unsigned length;
};

Node create_node(char);

Tape create_tape(void);

void free_tape(Tape);

int is_tape_empty(Tape);

Tape add_node_head(char, Tape);

Tape add_node_tail(char, Tape);

Tape rm_node_head(Tape);

Tape rm_node_tail(Tape);

int is_node_empty(Node);

#endif // TAPE_H
