#ifndef TAPE_H
#define TAPE_H

struct node {
    char symbol;
    struct node* prev;
    struct node* next;
};

struct node* create_tape();

struct node* add_node_head(char, struct node*);

struct node* get_tail(struct node*);

struct node* add_node_tail(char, struct node*);

struct node* rm_node_head(struct node*);

struct node* rm_node_tail(struct node*);

#endif // TAPE_H
