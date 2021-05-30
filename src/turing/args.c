#include <libturing/checks.h>
#include <libturing/process_file.h>

#include <turing/args.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_args(struct _params* params, int argc, char** argv)
{
    int i;
    for (i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
            case 'f':
                if (params->input != NULL) {
                    raise_and_exit_argparse();
                }
                params->input = argv[++i];
                break;
            case 'o':
                if (params->output != NULL) {
                    raise_and_exit_argparse();
                }
                params->output = argv[++i];
                break;
            case 's':
                if (params->startfile != NULL) {
                    raise_and_exit_argparse();
                }
                params->startfile = argv[++i];
                break;
            case '-':
                if (strcmp("--silent", argv[i]) == 0) {
                    params->silent = 1;
                }
                break;
            default:
                fprintf(stderr, "Wrong parameter: %s\n", argv[i]);
                raise_and_exit_argparse();
            }
        }
    }
#ifdef DEBUG
    printf("Parameters:\n");
    printf("Input: %s\n", params->input);
    printf("Output: %s\n", params->output);
    printf("Startfile: %s\n", params->startfile);
    printf("Silent: %d\n\n", params->silent);
#endif
}

char* get_input_filename()
{
    char* str_dest = calloc(MAX_FILENAME, sizeof(char));
    check_allocated(str_dest);
    fgets(str_dest, MAX_FILENAME, stdin);
    str_dest = get_word(str_dest, NULL);
    return (str_dest == NULL || str_dest[0] == '\0') ? NULL : str_dest;
}

void get_missing_params(struct _params* params)
{
    if (params->input == NULL) {
        printf("Please enter an input filename: [default: %s]\n",
               INPUT_DEFAULT);
        params->input = get_input_filename();
        if (params->input == NULL) {
            printf("Using default path: %s\n\n", (char*)INPUT_DEFAULT);
            params->input = INPUT_DEFAULT;
        }
    }

    if (params->output == NULL) {
        printf("Please enter an output filename: [default: %s]\n",
               OUTPUT_DEFAULT ? OUTPUT_DEFAULT : "None");
        params->output = get_input_filename();
        if (params->output == NULL && OUTPUT_DEFAULT) {
            printf("Using default path: %s\n\n", (char*)OUTPUT_DEFAULT);
            params->output = OUTPUT_DEFAULT;
        }
    }

    if (params->startfile == NULL) {
        printf("Enter startline filename: [default: %s] (you can enter it "
               "manually later)\n",
               STARTFILE_DEFAULT ? STARTFILE_DEFAULT : "None");
        params->startfile = get_input_filename();
        if (params->startfile == NULL && STARTFILE_DEFAULT) {
            printf("Using default path: %s\n\n", (char*)STARTFILE_DEFAULT);
            params->startfile = STARTFILE_DEFAULT;
        }
    }
}
