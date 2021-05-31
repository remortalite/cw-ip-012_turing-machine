#include <libturing/checks.h>
#include <libturing/process_file.h>
#include <libturing/program.h>
#include <libturing/tape.h>
#include <turing/args.h>

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    struct params params = {NULL, NULL, NULL, SILENTMODE_DEFAULT};
    parse_args(&params, argc, argv);

    printf("Turing machine app\n\n");

    get_missing_params(&params);
    print_params(params);

    char* startline = get_startline(params);
    if (startline == NULL) {
        fprintf(stderr, "YOU CANNOT NULL tHERE\n");
    }

    printf("*****\nStartline: `%s`\n****\n", startline);

    check_file_exists(params.input);
    FILE* fin = fopen(params.input, "r");

    Program prog = create_program();

    prog = fill_program(fin, prog);

    print_program(prog);

    fclose(fin);
    free_program(prog);
    return 0;
}
