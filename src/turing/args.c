#include <libturing/checks.h>

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
}
