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

    printf("Input name: %s\n", params.input);
    printf("Output name: %s\n", params.output);
    printf("Startfile name: %s\n", params.startfile);
    printf("Silentmode: %s\n", params.silent ? "on" : "off");

    FILE* fin = fopen(params.input, "r");
    if (fin == NULL) {
        printf("File %s doesn't exist!\n", params.input);
        return 1;
    }
    /*
        Program prog = create_program();

        prog = fill_program(fin, prog);

        print_program(prog);

        fclose(fin);
        free_program(prog);
    */
    return 0;
}
