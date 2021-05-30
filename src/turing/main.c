#include <libturing/process_file.h>
#include <libturing/program.h>
#include <libturing/tape.h>
#include <turing/args.h>

#include <stdio.h>
#include <string.h>

#define PATH_DEFAULT "./turing_prog1.txt"

int main(int argc, char** argv)
{
    struct _params params = {NULL, NULL, NULL, 0};

    parse_args(&params, argc, argv);

#ifdef DEBUG
    printf("Parameters:\n");
    printf("Input: %s\n", params.input);
    printf("Output: %s\n", params.output);
    printf("Startfile: %s\n", params.startfile);
    printf("Silent: %d\n\n", params.silent);
#endif

    printf("Turing machine app\n");

    if (params.input == NULL) {
        printf("Please enter an input filename:\n");
    }

    FILE* fin = fopen(params.input ? params.input : PATH_DEFAULT, "r");
    if (fin == NULL)
        return 1;

    Program prog = create_program();

    prog = fill_program(fin, prog);

    print_program(prog);

    fclose(fin);
    free_program(prog);

    return 0;
}
