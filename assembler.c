
/******************************************************************************

                            NAME - ELI BRACHA.
                            DATE - 2/3/2018
        This Program Functions As Assembler For A specific Assembly Language.

*******************************************************************************/


#include <stdio.h>

#define MINIMUM_ARGUMENTS 1
#define STARTUP_ERROR "Error: No File Paths Specified As Arguments.\n"
#define SUCCESS_MESSAGE "Build: Success Building Files.\n"

void initialize();

void assemble(char *);

_Bool validate_files(char *);

void start_assembler(char **);

void print_label_list();

void print_code_list();

void print_data_list();

int main(int argc, char *argv[]) {
    initialize();
    argc > MINIMUM_ARGUMENTS ? start_assembler(argv) : printf(STARTUP_ERROR);
    return 0;
}

void start_assembler(char **files) {
    while (*++files) {
        if (validate_files(*files)) {
            assemble(*files);
            printf(SUCCESS_MESSAGE);
        }
    }

    printf("LABELS - ");
    print_label_list();
    printf("CODE - ");
    print_code_list();
    printf("DATA - ");
    print_data_list();
}