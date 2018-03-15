
/******************************************************************************

                            NAME - ELI BRACHA.
                            DATE - 2/3/2018
        This Program Functions As Assembler For A specific Assembly Language.

*******************************************************************************/


#include <stdio.h>

#define MINIMUM_ARGUMENTS 1
#define STARTUP_ERROR "Error: No File Paths Specified As Arguments.\n"
#define SUCCESS_MESSAGE "Build: Success Building Files.\n"

_Bool validate_files(char *);

void assemble(char *);

void start_assembler(char **);

void initialize();

void printList();

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
    printList();
}