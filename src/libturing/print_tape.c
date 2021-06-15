#include <libturing/tape.h>

#include <stdio.h>

#define SIDE_SPACES 3

static void print_sepline(unsigned length)
{
    unsigned i;
    for (i = 0; i < length; i++)
        printf("%c", '-');
    putchar('\n');
}

void print_tape(Tape tape, Node cursor)
{
    Node node;
    unsigned i;
    int j;
    int idx_cursor = 0;
    char c;

    unsigned sepline_length = SIDE_SPACES * 2 + tape.length;

    print_sepline(sepline_length);
    for (j = 0; j < SIDE_SPACES; j++)
        printf(" ");
    node = tape.head;
    for (i = 0; i < tape.length; i++, node = node->next) {
        c = node->symbol;
        printf("%c", c == '_' ? ' ' : c);
        if (node == cursor)
            idx_cursor = i;
    }
    putchar('\n');
    for (j = 0; j < (SIDE_SPACES + idx_cursor); j++)
        printf(" ");
    putchar('^');
    putchar('\n');
    print_sepline(sepline_length);
}
