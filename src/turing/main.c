#include <libturing/process_file.h>
#include <libturing/program.h>
#include <libturing/tape.h>

#include <stdio.h>

#define PATH_DEFAULT "./turing_prog1.txt"

int main(int argc, char** argv)
{
    printf("Turing machine app\n");

    FILE* fin = fopen(argc > 1 ? argv[1] : PATH_DEFAULT, "r");
    if (fin == NULL)
        return 1;

    Program prog = create_program();

    prog = fill_program(fin, prog);

    print_program(prog);

    fclose(fin);
    free_program(prog);

    return 0;
}
