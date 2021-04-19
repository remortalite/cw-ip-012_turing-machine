#ifndef TAPE_H
#define TAPE_H

typedef struct node* Node;
struct node {
    char symbol;
    struct node* prev;
    struct node* next;
};

Node create_tape();

Node add_node_head(char, Node);

Node get_tail(Node);

Node add_node_tail(char, Node);

Node rm_node_head(Node);

Node rm_node_tail(Node);

int is_node_last(Node);

int is_tape_empty(Node);

void free_tape(Node);

#endif // TAPE_H
