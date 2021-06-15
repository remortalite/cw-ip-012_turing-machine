#include <libturing/checks.h>
#include <libturing/print_tape.h>
#include <libturing/process_file.h>
#include <libturing/program.h>
#include <libturing/tape.h>
#include <turing/args.h>

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    Program prog = create_program();
    Tape tape = create_tape();

    struct params params = {NULL, NULL, NULL, SILENTMODE_DEFAULT};
    parse_args(&params, argc, argv);

    printf("Turing machine app\n\n");

    get_missing_params(&params);
    print_params(params);

    check_file_exists(params.input);

    char* startline = get_startline(params);

    printf("Startline: `%s`\n", startline);

    FILE* fin = fopen(params.input, "r");

    prog = fill_program(fin, prog);
    tape = fill_tape(startline, tape);

    /*
Node node;
for (node = tape.head; node != tape.tail->next; node = node->next) {
    printf("%c ", node->symbol);
}
putchar('\n');
    */
    print_tape(tape, tape.tail->prev);

    if (params.silent == 0)
        print_program(prog);

    fclose(fin);
    free_program(prog);
    return 0;
}
